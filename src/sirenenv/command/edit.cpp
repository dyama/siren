/**
 * \brief Edit commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief Erase object
 */
mrb_value erase(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	::unset(target);
	return mrb_nil_value();
}

/**
 * \brief copy object
 */
mrb_value copy(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(hashape->Shape());
	TopoDS_Shape shape = Builder.Shape();

	return mrb_fixnum_value(::set(shape));
}

/**
 * \brief close wire / edge object
 */
mrb_value close(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopAbs_ShapeEnum se = hashape->Shape().ShapeType();
	if ( se != TopAbs_WIRE && se != TopAbs_EDGE && se != TopAbs_COMPOUND ) {
		static const char m[] = "Failed to make a closed wire.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape;
	TopoDS_Shape sThis = hashape->Shape();
	try {
		BRepBuilderAPI_MakeWire mw;
		// find first point
		BRepAdaptor_Curve ac;
		gp_Pnt sp, ep;
		TopExp_Explorer exp( sThis, TopAbs_EDGE );
		double tol = 0.01;
		TopoDS_Edge e = TopoDS::Edge( exp.Current() );
		ac.Initialize( e );
		sp = ac.Value( ac.FirstParameter() );
		ep = ac.Value( ac.LastParameter() );
		mw.Add( e );
		if ( e.Orientation() == TopAbs_REVERSED ) sp = ep;
		//find last point
		int count = 0;
		for ( ; exp.More(); exp.Next() )
		{
			if ( exp.Current().IsNull() ) continue;
			e = TopoDS::Edge( exp.Current() );
			mw.Add( e );
			ac.Initialize( e );
			if (e.Orientation() == TopAbs_FORWARD )
				ep = ac.Value( ac.LastParameter() );
			else if (e.Orientation() == TopAbs_REVERSED )
				ep = ac.Value( ac.FirstParameter() );
		}
		if ( !sp.IsEqual( ep, tol ) ) {
			e = BRepBuilderAPI_MakeEdge( ep, sp );
			mw.Add(e);
		}
		ShapeFix_Wire sfw;
		sfw.Load( mw.Wire() );
		sfw.FixClosed();
		shape = sfw.Wire();
		if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a closed wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a closed wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
}