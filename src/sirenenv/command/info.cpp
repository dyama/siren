/**
 * \brief Information/Status commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"
#include "OCCViewer.h"

/**
 * \brief Check existed
 */
mrb_value exist(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	return has_object(target) ? mrb_true_value() : mrb_false_value();
}

/**
 * \brief Get location of shape in WCS
 */
mrb_value location(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value location;
	int argc = mrb_get_args(mrb, "i|A", &target, &location);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    TopoDS_Shape shape = hashape->Shape();

    if (argc == 2) {
        gp_Pnt p = *ar2pnt(mrb, location);
        gp_Trsf tr;
        tr.SetTranslation(gp_Vec(p.X(), p.Y(), p.Z()));
        shape.Location(TopLoc_Location(tr));
        hashape->Set(shape);
        redisplay(hashape);
        return mrb_nil_value();
    }
    else {
        gp_XYZ pos = shape.Location().Transformation().TranslationPart();
        return pnt2ar(mrb, gp_Pnt(pos.X(), pos.Y(), pos.Z()));
    }
}

/**
 * \brief Get type of object
 */
mrb_value type(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	int type = (int)hashape->Shape().ShapeType();

	return mrb_fixnum_value(type);
}

/**
 * \brief オブジェクトが存在しているエリアを取得する
 * 
 * \note グローバル座標系において、オブジェクトが存在しているエリアを
 *       X軸、Y軸、Z軸に対してそれぞれ最小値、最大値で取得する。
 */
mrb_value bndbox(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	TopoDS_Shape shape = hashape->Shape();
	
    Bnd_Box box;
    BRepBndLib::Add(shape, box);
    Standard_Real xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);

	mrb_value rmin = ::pnt2ar(mrb, gp_Pnt(xmin, ymin, zmin));
	mrb_value rmax = ::pnt2ar(mrb, gp_Pnt(xmax, ymax, zmax));
	
	mrb_value res[2];
	res[0] = rmin;
	res[1] = rmax;	

	return mrb_ary_new_from_values(mrb, 2, res);
}

/**
 * \brief 線上点における曲線パラメータを取得する
 */
mrb_value cparam(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value xyz;
	int argc = mrb_get_args(mrb, "iA", &target, &xyz);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    gp_Pnt p = *::ar2pnt(mrb, xyz);
	TopoDS_Shape shape = hashape->Shape();

    Standard_Real tol = 1.0e-7;
    TopExp_Explorer exp(shape, TopAbs_EDGE);
    ShapeAnalysis_Curve ana;
    gp_Pnt pp;

    Standard_Real param, distance;
    int n; // index

    for (n = 0; exp.More(); n++, exp.Next()) {
        TopoDS_Edge e = TopoDS::Edge(exp.Current());
        if (e.IsNull())
            continue;

        BRepAdaptor_Curve gcurve(e);

        distance = ana.Project(gcurve, p, tol, pp, param);

        if (fabs(distance) <= tol) {
            break;
        }
    }

	mrb_value res[2];
	res[0] = mrb_fixnum_value(n);
	res[1] = mrb_float_value(mrb, param);

	return mrb_ary_new_from_values(mrb, 2, res);
}

/**
 * \brief 曲線パラメータに対応する点座標を取得する
 */
mrb_value cpoint(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value params;
	int argc = mrb_get_args(mrb, "iA", &target, &params);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape = hashape->Shape();

    if (mrb_ary_len(mrb, params) != 2) {
		static const char m[] = "Illigal array of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    int index = mrb_fixnum(mrb_ary_ref(mrb, params, 0));
    double param = mrb_float(mrb_ary_ref(mrb, params, 1));

    TopExp_Explorer exp(shape, TopAbs_EDGE);
    for (int i=0; i<index && exp.More(); i++, exp.Next())
        ;
    TopoDS_Edge e = TopoDS::Edge(exp.Current());
    if (e.IsNull()) {
		static const char m[] = "Illigal index of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    BRepAdaptor_Curve c(e);

    gp_Pnt p;
    gp_Vec v1, v2;
    c.D2((Standard_Real)param, p, v1, v2);

    return ::pnt2ar(mrb, p);
}

/**
 * \brief 線上点(パラメータ指定)における曲率線ベクトルを取得する
 */
mrb_value ccurvature(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value params;
	int argc = mrb_get_args(mrb, "iA", &target, &params);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape = hashape->Shape();

    if (mrb_ary_len(mrb, params) != 2) {
		static const char m[] = "Illigal array of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    int index = mrb_fixnum(mrb_ary_ref(mrb, params, 0));
    double param = mrb_float(mrb_ary_ref(mrb, params, 1));

    TopExp_Explorer exp(shape, TopAbs_EDGE);
    for (int i=0; i<index && exp.More(); i++, exp.Next())
        ;
    TopoDS_Edge e = TopoDS::Edge(exp.Current());
    if (e.IsNull()) {
		static const char m[] = "Illigal index of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    BRepAdaptor_Curve c(e);

    gp_Pnt p;
    gp_Vec v1, v2;
    c.D2((Standard_Real)param, p, v1, v2);

    return ::vec2ar(mrb, v2);
}

/**
 * \brief 線上点(パラメータ指定)における接線ベクトルを取得する
 */
mrb_value ctangent(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
    mrb_value params;
	int argc = mrb_get_args(mrb, "iA", &target, &params);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape = hashape->Shape();

    if (mrb_ary_len(mrb, params) != 2) {
		static const char m[] = "Illigal array of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    int index = mrb_fixnum(mrb_ary_ref(mrb, params, 0));
    double param = mrb_float(mrb_ary_ref(mrb, params, 1));

    TopExp_Explorer exp(shape, TopAbs_EDGE);
    for (int i=0; i<index && exp.More(); i++, exp.Next())
        ;
    TopoDS_Edge e = TopoDS::Edge(exp.Current());
    if (e.IsNull()) {
		static const char m[] = "Illigal index of params.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    BRepAdaptor_Curve c(e);

    gp_Pnt p;
    gp_Vec v1, v2;
    c.D2((Standard_Real)param, p, v1, v2);

    return ::vec2ar(mrb, v1);
}
