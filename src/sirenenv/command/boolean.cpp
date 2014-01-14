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
