/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

// OCCViewer.h で定義されている static な AISContext, Viewer, Map に直接
// アクセスするメソッドは、暫定的にこの中に実装しなければならない。

#include "StdAfx.h"
#include "OCCViewer.h"

bool OCCViewer::mruby_init()
{
	// init mruby interpretor
	myMirb = new Mirb();

	// コマンドの登録
	// mrb_define_method(ステータス, 登録先, コマンド名, 関数, コマンドが受け取る引数の情報);

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "erase",    &OCCViewer::erase,    MRB_ARGS_REQ(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "rename",   &OCCViewer::rename,   MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "copy",     &OCCViewer::copy,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "bndbox",   &OCCViewer::bndbox,   MRB_ARGS_REQ(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "compound", &OCCViewer::compound, MRB_ARGS_REQ(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "translate",&OCCViewer::translate,MRB_ARGS_REQ(4));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "rotate",   &OCCViewer::rotate,   MRB_ARGS_REQ(8));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "scale",    &OCCViewer::scale,    MRB_ARGS_REQ(4));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "mirror",   &OCCViewer::mirror,   MRB_ARGS_REQ(7));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "display",  &OCCViewer::display,  MRB_ARGS_REQ(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fit",      &OCCViewer::fit,      MRB_ARGS_NONE());
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "update",   &OCCViewer::update,   MRB_ARGS_NONE());
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "color",    &OCCViewer::color,    MRB_ARGS_REQ(4));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "common",   &OCCViewer::common,   MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cut",      &OCCViewer::cut,      MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fuse",     &OCCViewer::fuse,     MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "volume",   &OCCViewer::volume,   MRB_ARGS_REQ(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cog",      &OCCViewer::cog,      MRB_ARGS_REQ(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "vertex",   &OCCViewer::vertex,   MRB_ARGS_REQ(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "line",     &OCCViewer::line,     MRB_ARGS_REQ(2));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "box",      &OCCViewer::box,      MRB_ARGS_REQ(3) | MRB_ARGS_OPT(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "sphere",   &OCCViewer::sphere,   MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cylinder", &OCCViewer::cylinder, MRB_ARGS_REQ(8));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cone",     &OCCViewer::cone,     MRB_ARGS_REQ(10) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "torus",    &OCCViewer::torus,    MRB_ARGS_REQ(11) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "plane",    &OCCViewer::plane,    MRB_ARGS_REQ(6));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "save",     &OCCViewer::savebrep, MRB_ARGS_REQ(2));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "load",     &OCCViewer::loadbrep, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));

	return true;
}

bool OCCViewer::mruby_cleenup()
{
	if (myMirb)
		free(myMirb);
	return true;
}

int OCCViewer::mruby_exec(char* command)
{
	if (!myMirb)
		return -1;

	AISContext = myAISContext;
	if (AISContext.IsNull())
		return -1;
	View = myView;
	if (View.IsNull())
		return -1;

	return myMirb->user_exec(command);
}

const char* OCCViewer::set(const TopoDS_Shape& shape, const char* name /* = NULL */)
{
	Handle(AIS_Shape) hashape = new AIS_Shape(shape);
	// registration
	bool hasname = (name != NULL && strlen(name) > 0);
	char* aname = NULL;
	if (hasname) {
		::Map[std::string(name)] = hashape;
	}
	else {
		// auto naming
		char* __tmp = (char*)malloc(sizeof(char*)*16);
		if (__tmp == NULL)
			throw "memory allocation error.";
		aname = __tmp;
		sprintf(aname, "%X", shape.HashCode(INT_MAX));
		::Map[std::string(aname)] = hashape;
	}

	// display
	if (AISContext.IsNull()) {
		throw "No AIS Interactive Context.";
	}
	AISContext->Display(hashape);
	AISContext->SetMaterial(hashape, /*Graphic3d_NameOfMaterial::*/Graphic3d_NOM_STONE);
	AISContext->UpdateCurrentViewer();

	return hasname ? name : aname;
}

void OCCViewer::unset(const char* name)
{
	Handle(AIS_Shape) myShape = OCCViewer::get(name);
	AISContext->Erase(myShape, Standard_True, Standard_False);
	if (::Map.find(std::string(name)) == ::Map.end())
		return;
	::Map.erase(std::string(name));
	return;
}

Handle(AIS_Shape) OCCViewer::get(const char* name)
{
	if (::Map.find(std::string(name)) == ::Map.end())
		return NULL;
	return ::Map[name];
}

mrbcmddef(erase)
{
    mrb_value name;

	int argc = mrb_get_args(mrb, "S", &name);

	OCCViewer::unset(RSTRING_PTR(name));

	return mrb_nil_value();
}

mrbcmddef(copy)
{
	mrb_value src, dest;

	int argc = mrb_get_args(mrb, "S|S", &src, &dest);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(src));
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(hashape->Shape());
	TopoDS_Shape shape = Builder.Shape();

	const char* rname = OCCViewer::set(shape, mrb_string_p(dest) ? RSTRING_PTR(dest) : NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}

mrbcmddef(rename)
{
	mrb_value src, dest;

	int argc = mrb_get_args(mrb, "S|S", &src, &dest);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(src));
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(hashape->Shape());
	TopoDS_Shape shape = Builder.Shape();
	const char* rname = OCCViewer::set(shape, mrb_string_p(dest) ? RSTRING_PTR(dest) : NULL);

	OCCViewer::unset(RSTRING_PTR(src));

	return mrb_str_new(mrb, rname, strlen(rname));
}


mrbcmddef(update)
{
	AISContext->UpdateCurrentViewer();
	return mrb_nil_value();
}

mrbcmddef(display)
{
	if (AISContext.IsNull())
		return mrb_nil_value();

    mrb_value _name;
	int argc = mrb_get_args(mrb, "S", &_name);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name = RSTRING_PTR(_name);

	Handle(AIS_Shape) myShape = OCCViewer::get(name);

	if (myShape.IsNull())
		return mrb_nil_value();

	AISContext->Display(myShape, Standard_False);

	return mrb_str_new(mrb, name, strlen(name));
}

mrbcmddef(fit)
{
	if (!View.IsNull()) {
		View->FitAll();
		View->ZFitAll();
	}
	else {
		static const char m[] = "View is NULL object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_nil_value();
}

mrbcmddef(color)
{
    mrb_value name;
	mrb_float _r, _g, _b;
	int argc = mrb_get_args(mrb, "Sfff", &name, &_r, &_g, &_b);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	Standard_Real r = (Standard_Real)_r;
	Standard_Real g = (Standard_Real)_g;
	Standard_Real b = (Standard_Real)_b;

	Quantity_Color col =  Quantity_Color(r/255., g/255., b/255., Quantity_TOC_RGB);
    AISContext->SetColor(hashape, col.Name());

	return mrb_nil_value();
}

mrbcmddef(translate)
{
    mrb_value name;
	mrb_float vx, vy, vz;
	int argc = mrb_get_args(mrb, "Sfff", &name, &vx, &vy, &vz);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
    T.SetTranslation(gp_Vec((Standard_Real)vx, (Standard_Real)vy, (Standard_Real)vz));

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		OCCViewer::unset(RSTRING_PTR(name));
		TopoDS_Shape shape = trf.Shape();
		OCCViewer::set(shape, RSTRING_PTR(name));
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to translate object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

mrbcmddef(rotate)
{
    mrb_value name;
	mrb_float x, y, z, vx, vy, vz, a;
	int argc = mrb_get_args(mrb, "Sfffffff", &name, &x, &y, &z, &vx, &vy, &vz, &a);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	Standard_Real ang = (double)a * (M_PI / 180.0);
	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	gp_Vec vec((Standard_Real)vx, (Standard_Real)vy, (Standard_Real)vz);
	gp_Ax1 ax(p, vec);
    T.SetRotation(ax, ang);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		OCCViewer::unset(RSTRING_PTR(name));
		TopoDS_Shape shape = trf.Shape();
		OCCViewer::set(shape, RSTRING_PTR(name));
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to rotate object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

mrbcmddef(scale)
{
    mrb_value name;
	mrb_float x, y, z, s;
	int argc = mrb_get_args(mrb, "Sffff", &name, &x, &y, &z, &s);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
    T.SetScale(p, (Standard_Real)s);

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		OCCViewer::unset(RSTRING_PTR(name));
		TopoDS_Shape shape = trf.Shape();
		OCCViewer::set(shape, RSTRING_PTR(name));
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to scale object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

mrbcmddef(mirror)
{
    mrb_value name;
	mrb_float x, y, z, vx, vy, vz;
	int argc = mrb_get_args(mrb, "Sffffff", &name, &x, &y, &z, &vx, &vy, &vz);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	gp_Vec v((Standard_Real)vx, (Standard_Real)vy, (Standard_Real)vz);
    T.SetMirror(gp_Ax2(p, v));

    BRepBuilderAPI_Transform trf(T);
	trf.Perform(hashape->Shape());

	mrb_value result;
	if (trf.IsDone()){
		OCCViewer::unset(RSTRING_PTR(name));
		TopoDS_Shape shape = trf.Shape();
		OCCViewer::set(shape, RSTRING_PTR(name));
		result = mrb_nil_value();
	}
	else {
		static const char m[] = "Failed to mirror object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief mrubyの配列オブジェクトをOCCのgp_Pntに変換する
 */
gp_Pnt* OCCViewer::ar2pnt(mrb_state* mrb, const mrb_value& ar)
{
	mrb_value _x = mrb_ary_shift(mrb, ar);
	mrb_value _y = mrb_ary_shift(mrb, ar);
	mrb_value _z = mrb_ary_shift(mrb, ar);

	mrb_float x, y, z;

	if (mrb_nil_p(_x))
		throw "X value is nil.";
	else
		if (!mrb_float_p(_x)) {
			if (!mrb_fixnum_p(_x))
				throw "X value is not float type.";
			x = mrb_fixnum(_x);
		}
		else 
			x = _x.value.f;

	if (mrb_nil_p(_y))
		throw "Y value is nil.";
	else
		if (!mrb_float_p(_y)) {
			if (!mrb_fixnum_p(_y))
				throw "Y value is not float type.";
			y = mrb_fixnum(_y);
		}
		else 
			y = _y.value.f;

	if (mrb_nil_p(_z))
		throw "Z value is nil.";
	else
		if (!mrb_float_p(_z)) {
			if (!mrb_fixnum_p(_z))
				throw "Z value is not float type.";
			z = mrb_fixnum(_z);
		}
		else 
			z = _z.value.f;
	
	return new gp_Pnt((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
}

/**
 * \brief OCCのgp_Pntをmrubyの配列オブジェクトに変換する
 */
mrb_value OCCViewer::pnt2ar(mrb_state* mrb, const gp_Pnt& rPnt)
{
	mrb_value res[3];
	res[0] = mrb_float_value(mrb, rPnt.X());
	res[1] = mrb_float_value(mrb, rPnt.Y());
	res[2] = mrb_float_value(mrb, rPnt.Z());
	return mrb_ary_new_from_values(mrb, 3, res);
}

/**
 * \brief オブジェクトが存在しているエリアを取得する
 * 
 * \note グローバル座標系において、オブジェクトが存在しているエリアを
 *       X軸、Y軸、Z軸に対してそれぞれ最小値、最大値で取得する。
 */
mrbcmddef(bndbox)
{
	mrb_value name;
	int argc = mrb_get_args(mrb, "S", &name);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	TopoDS_Shape shape = hashape->Shape();
	
    Bnd_Box box;
    BRepBndLib::Add(shape, box);
    Standard_Real xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);

	mrb_value rmin = pnt2ar(mrb, gp_Pnt(xmin, ymin, zmin));
	mrb_value rmax = pnt2ar(mrb, gp_Pnt(xmax, ymax, zmax));
	
	mrb_value res[2];
	res[0] = rmin;
	res[1] = rmax;	

	return mrb_ary_new_from_values(mrb, 2, res);
}


mrbcmddef(compound)
{
	mrb_value ar;
	int argc = mrb_get_args(mrb, "A", &ar);

	TopoDS_Compound	comp;
	BRep_Builder B;
	B.MakeCompound(comp);

	for (;;) {
		mrb_value name = mrb_ary_shift(mrb, ar);
		if (mrb_nil_p(name))
			break;
		Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
		if (hashape.IsNull()) {
			static const char m[] = "No such object name of specified at first.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		TopoDS_Shape shape = hashape->Shape();
		B.Add(comp, shape);
	}

	const char* rname = OCCViewer::set(comp, NULL);
	return mrb_str_new(mrb, rname, strlen(rname));
}
