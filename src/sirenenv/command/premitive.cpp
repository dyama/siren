/**
 * \brief The premitive commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "StdAfx.h"
#include "OCCViewer.h"


mrbcmddef(box)
{
    mrb_float x, y, z;
	mrb_value name;
    int argc = mrb_get_args(mrb, "fff|S", &x, &y, &z, &name);

	gp_Pnt op(0.0, 0.0, 0.0);

	BRepPrimAPI_MakeBox box(op, (Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
    TopoDS_Shape shape = box.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

mrbcmddef(sphere)
{
    mrb_float r;
	mrb_value name;
    int argc = mrb_get_args(mrb, "f|S", &r, &name);

	gp_Pnt op(0.0, 0.0, 0.0);

	BRepPrimAPI_MakeSphere sp(op, (Standard_Real)r); 
    TopoDS_Shape shape = sp.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

mrbcmddef(cylinder)
{
    mrb_float px, py, pz, nx, ny, nz, r, h, a;
	mrb_value name;
	int argc = mrb_get_args(mrb, "fffffffff|S", &px, &py, &pz, &nx, &ny, &nz, &r, &h, &a, &name);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCylinder cy(ax, (Standard_Real)r, (Standard_Real)h, (Standard_Real)a);
    TopoDS_Shape shape = cy.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

mrbcmddef(cone)
{
	mrb_float px, py, pz, nx, ny, nz, r1, r2, h, ang;
	mrb_value name;
	int argc = mrb_get_args(mrb, "ffffffffff|S", &px, &py, &pz, &nx, &ny, &nz, &r1, &r2, &h, &ang, &name);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCone prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)h, (Standard_Real)ang);
    TopoDS_Shape shape = prm.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

mrbcmddef(torus)
{
	mrb_float px, py, pz, nx, ny, nz, r1, r2, a1, a2, ang;
	mrb_value name;
	int argc = mrb_get_args(mrb, "fffffffffff|S", &px, &py, &pz, &nx, &ny, &nz, &r1, &r2, &a1, &a2, &ang, &name);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeTorus prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)a1, (Standard_Real)a2, (Standard_Real)ang);
    TopoDS_Shape shape = prm.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}