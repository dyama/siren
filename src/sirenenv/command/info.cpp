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
        shape.Location(TopLoc_Location(tr) * shape.Location());
        hashape->Set(shape);
        //hashape->Redisplay();
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
