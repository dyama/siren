/**
 * \brief Shape convertion commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief wire to points
 */
mrb_value wire2pts(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	mrb_float deflect;
	int argc = mrb_get_args(mrb, "i|f", &src, &deflect);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	if (argc != 2)
		deflect = 1.0e-1;

	mrb_value result = mrb_ary_new(mrb);
	double first_param, last_param;

	TopExp_Explorer	exp(hashape->Shape(), TopAbs_EDGE);
	for(; exp.More(); exp.Next()) {
		const TopoDS_Edge& edge = TopoDS::Edge(exp.Current());
		try {
			BRepAdaptor_Curve adaptor(edge);
			first_param = adaptor.FirstParameter();
			last_param = adaptor.LastParameter();

			GCPnts_UniformDeflection unidef(adaptor, (Standard_Real)deflect);
			if (!unidef.IsDone())
				continue;

			mrb_value line = mrb_ary_new(mrb);

			// first point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(first_param)));

			for (int i=0; i<unidef.NbPoints(); i++)
				mrb_ary_push(mrb, line, pnt2ar(mrb, unidef.Value(i)));

			// last point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(last_param)));
			
			mrb_ary_push(mrb, result, line);
		}
		catch (...) {
			; // nothing to do.
		}
	}

    return result;
}

/**
 * \brief wire to plane
 */
mrb_value wire2plane(mrb_state* mrb, mrb_value self)
{
	//!!Curve‚ðŠÜ‚ñ‚¾Wire‚É‚Í–¢‘Î‰ž!!
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if ( hashape->Shape().ShapeType() != TopAbs_WIRE ) {
		static const char m[] = "Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	TopoDS_Shape shape;
	try {
		TopoDS_Wire w = TopoDS::Wire( hashape->Shape() );
		BRepBuilderAPI_MakeFace mf( w, Standard_True );
		mf.Build();
		if (  !mf.IsDone() ) {
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		shape = mf.Shape();
		//TopAbs_ShapeEnum se = shape.ShapeType();
		if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a plane.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
}
