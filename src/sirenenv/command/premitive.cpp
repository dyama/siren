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

/**
 * \brief make vertex
 */
mrbcmddef(vertex)
{
	mrb_float x, y, z;
	mrb_value name;

	int argc = mrb_get_args(mrb, "fff|S", &x, &y, &z, &name);

	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	TopoDS_Vertex v = BRepBuilderAPI_MakeVertex(p);

	const char* rname = OCCViewer::set(v, mrb_string_p(name) ? RSTRING_PTR(name) : NULL);

	// mrb_value r[3];
	// r[0] = mrb_float_value(mrb, _x);
	// r[1] = mrb_float_value(mrb, _y);
	// r[2] = mrb_float_value(mrb, _z);
	// mrb_value res = mrb_ary_new_from_values(mrb, 3, r);

	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make box
 */
mrbcmddef(box)
{
    mrb_float sx, sy, sz;
    mrb_float px, py, pz;
    int argc = mrb_get_args(mrb, "fff|fff", &sx, &sy, &sz, &px, &py, &pz);

	gp_Pnt op
		= (argc == 6) ? gp_Pnt(px, py, pz) : gp_Pnt(0.0, 0.0, 0.0);

	BRepPrimAPI_MakeBox box(op, (Standard_Real)sx, (Standard_Real)sy, (Standard_Real)sz);
    TopoDS_Shape shape = box.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make sphere
 */
mrbcmddef(sphere)
{
    mrb_float r;
    mrb_float px, py, pz;
    int argc = mrb_get_args(mrb, "f|fff", &r, &px, &py, &pz);

	gp_Pnt op
		= (argc == 4) ? gp_Pnt(px, py, pz) : gp_Pnt(0.0, 0.0, 0.0);

	BRepPrimAPI_MakeSphere sp(op, (Standard_Real)r); 
    TopoDS_Shape shape = sp.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make cylinder
 */
mrbcmddef(cylinder)
{
    mrb_float px, py, pz, nx, ny, nz, r, h, a;
	int argc = mrb_get_args(mrb, "fffffffff", &px, &py, &pz, &nx, &ny, &nz, &r, &h, &a);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCylinder cy(ax, (Standard_Real)r, (Standard_Real)h, (Standard_Real)a);
    TopoDS_Shape shape = cy.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make cone
 */
mrbcmddef(cone)
{
	mrb_float px, py, pz, nx, ny, nz, r1, r2, h, ang;
	int argc = mrb_get_args(mrb, "ffffffffff", &px, &py, &pz, &nx, &ny, &nz, &r1, &r2, &h, &ang);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCone prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)h, (Standard_Real)ang);
    TopoDS_Shape shape = prm.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make torus
 */
mrbcmddef(torus)
{
	mrb_float px, py, pz, nx, ny, nz, r1, r2, a1, a2, ang;
	int argc = mrb_get_args(mrb, "fffffffffff", &px, &py, &pz, &nx, &ny, &nz, &r1, &r2, &a1, &a2, &ang);

	gp_Pnt pnt((Standard_Real)px, (Standard_Real)py, (Standard_Real)pz);
	gp_Dir dir((Standard_Real)nx, (Standard_Real)ny, (Standard_Real)nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeTorus prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)a1, (Standard_Real)a2, (Standard_Real)ang);
    TopoDS_Shape shape = prm.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}
