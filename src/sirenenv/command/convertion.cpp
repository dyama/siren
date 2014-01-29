/**
 * \brief Shape convertion commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief wire to points
 */
mrb_value wire2pts(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	mrb_float deflect;
	int argc = mrb_get_args(mrb, "i|f", &src, &deflect);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	if (argc != 2)
		deflect = 1.0e-1;

	mrb_value result = mrb_ary_new(mrb);
	double first_param, last_param;

	TopExp_Explorer	exp(hashape->Shape(), TopAbs_EDGE);
	for(; exp.More(); exp.Next()) {
		const TopoDS_Edge& edge = TopoDS::Edge(exp.Current());
		try {
			BRepAdaptor_Curve adaptor(edge);
			first_param = adaptor.FirstParameter();
			last_param = adaptor.LastParameter();

			GCPnts_UniformDeflection unidef(adaptor, (Standard_Real)deflect);
			if (!unidef.IsDone())
				continue;

			mrb_value line = mrb_ary_new(mrb);

			// first point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(first_param)));

			for (int i=0; i<unidef.NbPoints(); i++)
				mrb_ary_push(mrb, line, pnt2ar(mrb, unidef.Value(i)));

			// last point
			mrb_ary_push(mrb, line, pnt2ar(mrb, adaptor.Value(last_param)));
			
			mrb_ary_push(mrb, result, line);
		}
		catch (...) {
			; // nothing to do.
		}
	}

    return result;
}

/**
 * \brief wire to plane
 */
mrb_value wire2plane(mrb_state* mrb, mrb_value self)
{
	//!!Curve‚ðŠÜ‚ñ‚¾Wire‚É‚Í–¢‘Î‰ž!!
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if ( hashape->Shape().ShapeType() != TopAbs_WIRE ) {
		static const char m[] = "Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	TopoDS_Shape shape;
	try {
		TopoDS_Wire w = TopoDS::Wire( hashape->Shape() );
		BRepBuilderAPI_MakeFace mf( w, Standard_True );
		mf.Build();
		if (  !mf.IsDone() ) {
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		shape = mf.Shape();
		//TopAbs_ShapeEnum se = shape.ShapeType();
		if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a plane.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
}

/**
 * \brief Make a solid by shell.
 */
mrb_value shell2solid(mrb_state* mrb, mrb_value self)
{
    mrb_int obj;
	int argc = mrb_get_args(mrb, "i", &obj);

	Handle(AIS_Shape) hashape = ::get(obj);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    mrb_value result;

    TopoDS_Solid solid;
    TopoDS_Shape shape = hashape->Shape();
    BRepBuilderAPI_MakeSolid solid_maker;
    
	for (TopExp_Explorer ex(shape, TopAbs_SHELL); ex.More(); ex.Next()) {
		TopoDS_Shell shell = TopoDS::Shell(ex.Current());
        solid_maker.Add(shell);
	}
	if (solid_maker.IsDone()) {
		solid = solid_maker.Solid();
        result = mrb_fixnum_value(::set(solid));
	}
	else {
		static const char m[] = "Failed to make a solid by shell.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    return result;
}

/**
 * \brief Make triangle mesh from face.
 */
mrb_value triangle(mrb_state* mrb, mrb_value self)
{
    mrb_int obj;
    mrb_float defl, ang;
	int argc = mrb_get_args(mrb, "i|ff", &obj, &defl, &ang);

    Standard_Real deflection = (argc >= 2 ? (Standard_Real)defl : 1.0);
    Standard_Real angle      = (argc == 3 ? (Standard_Real)ang  : 0.5);

	Handle(AIS_Shape) hashape = ::get(obj);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
    TopoDS_Shape shape = hashape->Shape();

    TopoDS_Compound comp;
    BRep_Builder B;
    B.MakeCompound(comp);

    for (TopExp_Explorer ex(shape, TopAbs_FACE); ex.More(); ex.Next()) {

        TopoDS_Face face = TopoDS::Face(ex.Current());
        BRepTools::Update(face);

        BRepMesh_IncrementalMesh imesh(face, deflection, Standard_False, angle);
        imesh.Perform();
        if (!imesh.IsDone())
            continue;

        face = TopoDS::Face(imesh.Shape());

        TopLoc_Location loc;
        // Do triangulation
        Handle(Poly_Triangulation) poly = BRep_Tool::Triangulation(face, loc);
        if (poly.IsNull()) {
            continue;
        }

        const Poly_Array1OfTriangle& tris = poly->Triangles();

        for (Standard_Integer i = tris.Lower(); i <= tris.Upper(); i++) {

            const Poly_Triangle& tri = tris.Value(i);

            // Node indexes
            Standard_Integer n1, n2, n3;

            if (face.Orientation() == TopAbs_REVERSED)
                tri.Get(n3, n2, n1);
            else
                tri.Get(n1, n2, n3);

            gp_Pnt p1 = poly->Nodes().Value(n1);
            gp_Pnt p2 = poly->Nodes().Value(n2);
            gp_Pnt p3 = poly->Nodes().Value(n3);

            gp_Vec u = gp_Vec(p2.XYZ() - p1.XYZ());                    
            gp_Vec v = gp_Vec(p3.XYZ() - p1.XYZ());

            gp_Vec norm(
                u.Y() * v.Z() - u.Z() * v.Y(),
                u.Z() * v.X() - u.X() * v.Z(),
                u.X() * v.Y() - u.Y() * v.X());
            if (norm.Magnitude() <= 0)
                continue;
            norm.Normalize();

            BRepBuilderAPI_MakePolygon polymaker;
            polymaker.Add(p1);
            polymaker.Add(p2);
            polymaker.Add(p3);
            polymaker.Add(p1);

            polymaker.Build();
            if (polymaker.IsDone()) {
                TopoDS_Wire w = polymaker.Wire();
                BRepBuilderAPI_MakeFace mf(w, Standard_True);
                mf.Build();
                if (mf.IsDone()) {
                    B.Add(comp, mf.Shape());
                }
            }
        }
    }
    hashape->Set(comp);

    return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value obj2brep(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

/**
 * \brief 
 */
mrb_value brep2obj(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}
