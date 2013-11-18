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
	int argc = mrb_get_args(mrb, "fff", &x, &y, &z);

	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	TopoDS_Vertex v = BRepBuilderAPI_MakeVertex(p);

	const char* rname = OCCViewer::set(v, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make line
 */
mrbcmddef(line)
{
    mrb_value sp, tp;
    int argc = mrb_get_args(mrb, "AA", &sp, &tp);

	gp_Pnt _sp = *ar2pnt(mrb, sp);
	gp_Pnt _tp = *ar2pnt(mrb, tp);

	BRepBuilderAPI_MakeEdge line(_sp, _tp);
    TopoDS_Shape shape = line.Shape();

	const char* rname = OCCViewer::set(shape, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

/**
 * \brief make box
 */
mrbcmddef(box)
{
    mrb_value size;
    mrb_value pos;
    int argc = mrb_get_args(mrb, "A|A", &size, &pos);

	gp_Pnt s = *ar2pnt(mrb, size);
	gp_Pnt op = (argc == 2) ? *ar2pnt(mrb, pos) : gp_Pnt(0.0, 0.0, 0.0);

	BRepPrimAPI_MakeBox box(op, s.X(), s.Y(), s.Z());
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
	mrb_value pos;
    int argc = mrb_get_args(mrb, "f|A", &r, &pos);

	gp_Pnt op
		= (argc == 2) ? *ar2pnt(mrb, pos) : gp_Pnt(0.0, 0.0, 0.0);

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
