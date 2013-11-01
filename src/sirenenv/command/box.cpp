/**
 * \brief
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "command.h"

mrb_value command::box(mrb_state* mrb, mrb_value self)
{
    mrb_int _xs, _ys, _zs, _xp, _yp, _zp;
    int argc = mrb_get_args(mrb, "iii|iii", &_xs, &_ys, &_zs, &_xp, &_yp, &_zp);

	Standard_Real xs, ys, zs, xp = 0, yp = 0, zp = 0;
	if (argc == 3) {
		xs = (Standard_Real)_xs;
		ys = (Standard_Real)_ys;
		zs = (Standard_Real)_zs;
	}
	else if (argc == 6) {
		xs = (Standard_Real)_xs;
		ys = (Standard_Real)_ys;
		zs = (Standard_Real)_zs;
		xp = (Standard_Real)_xp;
		yp = (Standard_Real)_yp;
		zp = (Standard_Real)_zp;
	}
	else {
        mrb_value myexc;
        static const char m[] = "super called outside of method";
        myexc = mrb_exc_new(mrb, E_NOMETHOD_ERROR, m, sizeof(m) - 1);
        mrb->exc = mrb_obj_ptr(myexc);
		return mrb_nil_value();
	}
    
	BRepPrimAPI_MakeBox box(gp_Pnt(xp, yp, zp), xs, ys, zs);
    TopoDS_Shape shape = box.Shape();

	ocv->GetAISContext()->Display(new AIS_Shape(shape));
	ocv->GetAISContext()->UpdateCurrentViewer();

	return mrb_nil_value();
}
