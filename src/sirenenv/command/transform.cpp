/**
 * \brief Transform commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief 
 */
mrb_value translate(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	mrb_value vec;
	int argc = mrb_get_args(mrb, "iA", &target, &vec);

	gp_Pnt pvec = *ar2pnt(mrb, vec);
	gp_Vec myvec(pvec.X(), pvec.Y(), pvec.Z());

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
    T.SetTranslation(myvec);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		hashape->Set(trf.Shape());
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to translate object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief 
 */
mrb_value rotate(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	mrb_float a;
	mrb_value pos, norm;
	int argc = mrb_get_args(mrb, "iAAf", &target, &pos, &norm, &a);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	Standard_Real ang = (double)a * (M_PI / 180.0);
	gp_Ax1 ax = *ar2ax1(mrb, pos, norm);

    T.SetRotation(ax, ang);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		hashape->Set(trf.Shape());
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to rotate object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief 
 */
mrb_value scale(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	mrb_value pos;
	mrb_float s;
	int argc = mrb_get_args(mrb, "ifA", &target, &s, &pos);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Pnt p;
	if (argc == 2) {
		p = gp_Pnt(0, 0, 0);
	}
	else {
		p = *ar2pnt(mrb, pos);
	}

	gp_Trsf T;
    T.SetScale(p, (Standard_Real)s);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		hashape->Set(trf.Shape());
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to scale object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief 
 */
mrb_value mirror(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value pos, norm;
	int argc = mrb_get_args(mrb, "iAA", &target, &pos, &norm);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);
    T.SetMirror(ax);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		hashape->Set(trf.Shape());
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to mirror object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}
