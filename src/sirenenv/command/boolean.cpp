/**
 * \brief The boolean operation commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief get across area of s1 by s2
 */
mrb_value common(mrb_state* mrb, mrb_value self)
{
	mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	Handle(AIS_Shape) haS1 = ::get(s1);
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = ::get(s2);
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_COMMON);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief cut object (s1 by s2)
 */
mrb_value cut(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	Handle(AIS_Shape) haS1 = ::get(s1);
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = ::get(s2);
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_CUT);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief add object
 */
mrb_value fuse(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	Handle(AIS_Shape) haS1 = ::get(s1);
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = ::get(s2);
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_FUSE);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief get volume of solid object
 */
mrb_value volume(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(hashape->Shape(), gprops);
	Standard_Real vol = gprops.Mass();

	return mrb_float_value(mrb, (mrb_float)vol);
}

/**
 * \brief get point of center of gravity
 */
mrb_value cog(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(hashape->Shape(), gprops);
	gp_Pnt cog = gprops.CentreOfMass();

	return ::pnt2ar(mrb, cog);
}

/**
 * \brief 2つのオブジェクトの交線を求め、作成する
 */
mrb_value intersect(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	Handle(AIS_Shape) haS1 = ::get(s1);
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = ::get(s2);
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Section	sect(haS1->Shape(), haS2->Shape(), Standard_False );
	sect.ComputePCurveOn1(Standard_True);
	sect.Approximation(Standard_True);
	sect.Build();

	if (!sect.IsDone()) {
		static const char m[] = "Failed to intersection.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	TopoDS_Shape shape = sect.Shape();

	return mrb_fixnum_value(::set(shape));
}

/**
 * \brief 分割する
 */
mrb_value split(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	Handle(AIS_Shape) haS1 = ::get(s1);
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = ::get(s2);
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    // Intersection
    BRepAlgoAPI_Section asect(haS1->Shape(), haS2->Shape(), FALSE);
    asect.ComputePCurveOn1(TRUE);
    asect.Approximation(TRUE);
    asect.Build();
    if(!asect.IsDone())
        return mrb_nil_value();
    TopoDS_Shape curve = asect.Shape();

    BRepFeat_SplitShape splitter(haS1->Shape());
    TopExp_Explorer exp(curve, TopAbs_EDGE);

    for (; exp.More(); exp.Next()) {
        TopoDS_Shape e = exp.Current();     
        TopoDS_Shape f;
        if (asect.HasAncestorFaceOn1(e, f)) {
             TopoDS_Edge ee = TopoDS::Edge(e);
             TopoDS_Face ff = TopoDS::Face(f);
             splitter.Add(ee, ff);
        }
    }
    try {
        splitter.Build();
    	if (!splitter.IsDone()) {
    		static const char m[] = "Failed to intersection.";
            return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    	}
    }
    catch (...) {
		static const char m[] = "Failed to intersection.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	TopoDS_Shape shape = splitter.Shape();
	return mrb_fixnum_value(::set(shape));
}

/**
 * \brief サーフェスとカーブの交点を得る
 */
/*
 * GeomAPI_IntCS
 * IntCurvesFace_ShapeIntersector
 * IntCurvesFace_Intersector
 */
mrb_value intcs(mrb_state* mrb, mrb_value self)
{
    mrb_int c, s;
    mrb_bool with_normal = FALSE;
	int argc = mrb_get_args(mrb, "ii|b", &c, &s, &with_normal);

	Handle(AIS_Shape) hacurve = ::get(c);
	if (hacurve.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) hasurf = ::get(s);
	if (hasurf.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    mrb_value result = mrb_ary_new(mrb);

    Standard_Real first, last;
    TopExp_Explorer exc, exs;

    for (exc.Init(hacurve->Shape(), TopAbs_EDGE); exc.More(); exc.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exc.Current());
        Handle(Geom_Curve) gcurve = BRep_Tool::Curve(edge, first, last);

        for (exs.Init(hasurf->Shape(), TopAbs_FACE); exs.More(); exs.Next()) {
            TopoDS_Face face = TopoDS::Face(exs.Current());
            Handle(Geom_Surface) gsurf  = BRep_Tool::Surface(face);
            GeomAPI_IntCS isc = GeomAPI_IntCS(gcurve, gsurf);
            if (!isc.IsDone())
                continue;
            for (int i = 1; i <= isc.NbPoints() ; i++ ) {
               // Intersect point
               gp_Pnt p = isc.Point(i);
               mrb_value item = pnt2ar(mrb, p);
        	   mrb_ary_push(mrb, result, item);

               // Normal vector on a point
               if (with_normal) {
                   Quantity_Parameter u, v, w;
                   isc.Parameters(i, u, v, w);
                   BRepAdaptor_Surface aSurface(face);
                   gp_Vec ut, vt;
                   gp_Pnt pt;
                   aSurface.D1(u, v, pt, ut, vt);
                   gp_Vec normal = ut.Crossed(vt);
                   normal.Normalize();
                   gp_Pnt np(normal.X(), normal.Y(), normal.Z());
                   mrb_value a = pnt2ar(mrb, np);
            	   mrb_ary_push(mrb, result, a);
               }
            }
        }
    }

    return result;
}