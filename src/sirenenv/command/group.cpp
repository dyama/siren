/**
 * \brief Group/Ungroup commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief Make coupound from multiple objects.
 */
mrb_value compound(mrb_state* mrb, mrb_value self)
{
	mrb_value ar;
	int argc = mrb_get_args(mrb, "A", &ar);

	TopoDS_Compound	comp;
	BRep_Builder B;
	B.MakeCompound(comp);

	int psize = mrb_ary_len(mrb, ar);
	for (int i=0; i<psize; i++) {
		mrb_value item = mrb_ary_ref(mrb, ar, i);
		if (!mrb_fixnum_p(item)) {
			static const char m[] = "Incorrect argument specified.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		mrb_int target = mrb_fixnum(item);
		Handle(AIS_Shape) hashape = ::get(target);
		if (hashape.IsNull()) {
			static const char m[] = "No such object name of specified at first.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		TopoDS_Shape shape = hashape->Shape();
		B.Add(comp, shape);
	}
	return mrb_fixnum_value(::set(comp));
}

/**
 * \brief Sew objects to shell.
 */
mrb_value sew(mrb_state* mrb, mrb_value self)
{
	mrb_value ar;
	mrb_float tol;
	int argc = mrb_get_args(mrb, "A|f", &ar, &tol);

	BRepBuilderAPI_Sewing sewer;
	sewer.Init();
	if (argc == 2 && tol >= 0)
		sewer.SetTolerance(tol);

	int psize = mrb_ary_len(mrb, ar);
	for (int i=0; i<psize; i++) {
		mrb_value item = mrb_ary_ref(mrb, ar, i);
		if (!mrb_fixnum_p(item)) {
			static const char m[] = "Incorrect argument specified.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		mrb_int target = mrb_fixnum(item);
		Handle(AIS_Shape) hashape = ::get(target);
		if (hashape.IsNull()) {
			static const char m[] = "No such object name of specified at first.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		TopoDS_Shape shape = hashape->Shape();
        TopExp_Explorer ex(shape, TopAbs_FACE);
        for (; ex.More(); ex.Next()) {
            sewer.Add(ex.Current());
        }
	}

	TopoDS_Shape result;
	try {
		sewer.Perform();
		result = sewer.SewedShape();
	}
	catch (...) {
		static const char m[] = "Failed to sew objects.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return mrb_fixnum_value(::set(result));
}

/**
 * \brief Explode object to child elements.
 */
mrb_value explode(mrb_state* mrb, mrb_value self)
{
	mrb_int type;
	mrb_int target;
	int argc = mrb_get_args(mrb, "ii", &type, &target);

	if (type < 0 || type > (int)TopAbs_VERTEX) {
		static const char m[] = "Incorrect type specified.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopAbs_ShapeEnum shapetype = (TopAbs_ShapeEnum)type;

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	mrb_value ar = mrb_ary_new(mrb);
    TopExp_Explorer ex(hashape->Shape(), shapetype);

    for (; ex.More(); ex.Next()) {
        const TopoDS_Shape& Sx = ex.Current();
		mrb_value hc = mrb_fixnum_value(::set(Sx));
		mrb_ary_push(mrb, ar, hc);
    }

	return ar;
}
