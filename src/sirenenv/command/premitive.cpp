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

	return mrb_fixnum_value(OCCViewer::set(v));
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

	return mrb_fixnum_value(OCCViewer::set(shape));
}

/**
 * \brief make polyline
 */
mrbcmddef(polyline)
{
  mrb_value pts;
  int argc = mrb_get_args(mrb, "A", &pts);
	int psize = mrb_ary_len(mrb, pts);

	TopoDS_Compound comp;
	BRepBuilderAPI_MakePolygon poly;

	try
	{
		for (int i=0; i<psize; i++) {
			mrb_value pt = mrb_ary_ref(mrb, pts, i);
			gp_Pnt pnt = *ar2pnt(mrb, pt);
			poly.Add(pnt);
		}
		poly.Build();
		TopExp_Explorer exp;
		BRep_Builder build;
		build.MakeCompound(comp);
		for ( exp.Init( poly.Shape(), TopAbs_EDGE ); exp.More(); exp.Next() )
		{
			build.Add(comp, exp.Current());
		}
	}	catch (...) {
		static const char m[] = "Failed to make a polyline.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(OCCViewer::set(comp));
}

/**
 * \brief make curve
 */
mrbcmddef(curve)
{
	mrb_value pts, vecs;
	int argc = mrb_get_args(mrb, "A|A", &pts, &vecs);

	int psize = mrb_ary_len(mrb, pts);
    Handle(TColgp_HArray1OfPnt) pary = new TColgp_HArray1OfPnt(1, psize);
	for (int i=0; i<psize; i++) {
		mrb_value pt = mrb_ary_ref(mrb, pts, i);
		gp_Pnt pnt = *ar2pnt(mrb, pt);
		pary->SetValue(i+1, pnt);
	}
    GeomAPI_Interpolate intp(pary, Standard_False, 1.0e-7);

	if (argc == 2) {
		TColgp_Array1OfVec vec(1, psize);
	    Handle(TColStd_HArray1OfBoolean) use = new TColStd_HArray1OfBoolean(1, psize);

		for (int i=0; i<psize; i++) {
			mrb_value avec = mrb_ary_ref(mrb, vecs, i);
			if (mrb_nil_p(avec)) {
				//vec.SetValue(i+1, gp_Dir(1, 0, 0)); // dummy
				use->SetValue(i+1, Standard_False);	
			}
			else {
				gp_Dir dir = *ar2dir(mrb, avec);
				vec.SetValue(i+1, dir);
				use->SetValue(i+1, Standard_True);	
			}
		}
		intp.Load(vec, use, Standard_True);
		delete(use);
	}

    intp.Perform();
    Handle(Geom_BSplineCurve) geSpl = intp.Curve();
    TopoDS_Edge e = BRepBuilderAPI_MakeEdge(geSpl);

	delete(pary);

	return mrb_fixnum_value(OCCViewer::set(e));
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

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeBox box(op, s.X(), s.Y(), s.Z());
	    shape = box.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a box.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
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

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeSphere sp(op, (Standard_Real)r); 
	    shape = sp.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a sphere.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
}

/**
 * \brief make cylinder
 */
mrbcmddef(cylinder)
{
	mrb_value pos, norm;
    mrb_float r, h, a;
	int argc = mrb_get_args(mrb, "AAfff", &pos, &norm, &r, &h, &a);

	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeCylinder cy(ax, (Standard_Real)r, (Standard_Real)h, (Standard_Real)a);
	    shape = cy.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a cylinder.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
}

/**
 * \brief make cone
 */
mrbcmddef(cone)
{
	mrb_value pos, norm;
	mrb_float r1, r2, h, ang;
	int argc = mrb_get_args(mrb, "AAffff", &pos, &norm, &r1, &r2, &h, &ang);

	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeCone prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)h, (Standard_Real)ang);
	    shape = prm.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a cone.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
}

/**
 * \brief make torus
 */
mrbcmddef(torus)
{
	mrb_float r1, r2, a1, a2, ang;
	mrb_value pos, norm;
	int argc = mrb_get_args(mrb, "AAfffff", &pos, &norm, &r1, &r2, &a1, &a2, &ang);

	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeTorus prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)a1, (Standard_Real)a2, (Standard_Real)ang);
	    shape = prm.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a torus.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
}

mrbcmddef(plane)
{
	mrb_value pos, dir;
	mrb_float umin, umax, vmin, vmax;
	int argc = mrb_get_args(mrb, "AAffff", &pos, &dir, &umin, &umax, &vmin, &vmax);

	gp_Pnt _pos = *ar2pnt(mrb, pos);
	gp_Pnt _dir = *ar2pnt(mrb, dir);
	gp_Dir __dir(_dir.X(), _dir.Y(), _dir.Z());
	gp_Pln _pln(_pos, __dir);

	TopoDS_Shape shape;
	try {
		BRepBuilderAPI_MakeFace face(_pln, (Standard_Real)umin, (Standard_Real)umax, (Standard_Real)vmin, (Standard_Real)vmax);
	    shape = face.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_fixnum_value(OCCViewer::set(shape));
}
