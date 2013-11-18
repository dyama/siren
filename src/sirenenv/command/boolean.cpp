/**
 * \brief The boolean operation commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "StdAfx.h"
#include "OCCViewer.h"

/**
 * \brief get across area of s1 by s2
 */
mrbcmddef(common)
{
    mrb_value s1, s2, name;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
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
		const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
		result = mrb_str_new(mrb, rname, strlen(rname));
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
mrbcmddef(cut)
{
    mrb_value s1, s2, name;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
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
		const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
		result = mrb_str_new(mrb, rname, strlen(rname));
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
mrbcmddef(fuse)
{
    mrb_value s1, s2, name;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
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
		const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
		result = mrb_str_new(mrb, rname, strlen(rname));
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
mrbcmddef(volume)
{
    mrb_value name;
	int argc = mrb_get_args(mrb, "S", &name);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
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
mrbcmddef(cog)
{
    mrb_value name;
	int argc = mrb_get_args(mrb, "S", &name);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(hashape->Shape(), gprops);
	gp_Pnt cog = gprops.CentreOfMass();

	return pnt2ar(mrb, cog);
}
