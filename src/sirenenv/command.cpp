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

	// General commands
	regcmd("erase",     &erase,     1,0, "Erase specified object.",         "erase(obj) -> nil");
	regcmd("help",      &help,      1,0, "Display help of command.",        "help(cmd) -> String[][name, dest, usage]");
	regcmd("rename",    &rename,    1,1, "Rename specified object.",        "rename(src, dest = auto) -> String");
	regcmd("copy",      &copy,      1,1, "Copy specified object.",          "copy(src, dest = auto) -> String");
	regcmd("bndbox",    &bndbox,    1,0, "Get area of object exist.",       "bndbox(obj) -> String[min[X,Y,Z], max[X,Y,Z]]");
	regcmd("compound",  &compound,  1,0, "Make compound model by objects.", "compound(String[obj1, obj2, ...]) -> String");

	// Transform commands
	regcmd("translate", &translate, 2,0, "Translate specified object.",     "translate(obj, vector[X, Y, Z]) -> nil");
	regcmd("rotate",    &rotate,    4,0, "Rotate specified object.",        "rotate(obj, center[X, Y, Z], normal[X, Y, Z], angle) -> nil"); 
	regcmd("scale",     &scale,     3,0, "Scale specified object.",         "scale(obj, scale, center[X, Y, Z] = [0, 0, 0]) -> nil");
	regcmd("mirror",    &mirror,    3,0, "Mirror copy specified object.",   "mirror(obj, center[X, Y, Z], normal[X, Y, Z]) -> nil");

	// Visualization commands
	regcmd("display",   &display,   1,0, "Dislay object.",                  "display(obj) -> nil");
	regcmd("fit",       &fit,       0,0, "Fit view to objects",             "fit() -> nil");
	regcmd("update",    &update,    0,0, "Update current viewer.",          "update() -> nil");
	regcmd("color",     &color,     4,0, "Set color of object.",            "color(obj, R, G, B) -> nil");

	// Boolean operation commands
	regcmd("common",    &common,    2,1, "Common boolean operation.",       "common(obj1, obj2) -> String");
	regcmd("cut",       &cut,       2,1, "Cut boolean operation.",          "cut(obj1, obj2) -> String");
	regcmd("fuse",      &fuse,      2,1, "Fuse boolean operation.",         "fuse(obj1, obj2) -> String");
	regcmd("volume",    &volume,    1,0, "Get volume of object.",           "volume(obj) -> float");
	regcmd("cog",       &cog,       1,0, "Get center position of gravity",  "cog(obj) -> float[X, Y, Z]");

	// Make object commands
	regcmd("vertex",    &vertex,    3,0, "Make a vertex.",                  "vertex(X, Y, Z) -> String");
	regcmd("line",      &line,      2,0, "Make a line.",                    "line(sp[X, Y, Z], tp[X, Y, Z]) -> String");
	regcmd("box",       &box,       1,1, "Make a box.",                     "box(size[X, Y, Z], pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("sphere",    &sphere,    1,1, "Make a sphere.",                  "sphere(R, pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("cylinder",  &cylinder,  5,0, "Make a cylinder.",                "cylinder(pos[X, Y, Z], normal[X, Y, Z], R, height, angle) -> String");
	regcmd("cone",      &cone,      6,0, "Make a cone.",                    "cone(pos[X, Y, Z], normal[X, Y, Z], R1, R2, height, angle) -> String");
	regcmd("torus",     &torus,     7,0, "Make a torus.",                   "torus(pos[X, Y, Z], normal[X, Y, Z]], R1, R2, angle1, angle2, angle) -> String");
	regcmd("plane",     &plane,     6,0, "Make a plane.",                   "plane(pos[X, Y, Z], normal[X, Y, Z], umin, umax, vmin, vmax) -> String");

	// I/O commands
	regcmd("bsave",     &savebrep,  2,0, "Save object to a file.",          "bsave(path, obj) -> nil");
	regcmd("bload",     &loadbrep,  1,1, "Load object from a file.",        "bload(path) -> String");

	// デフォルトのグローバル変数定義
	myMirb->user_exec(
		"tri10=[10,10,10];"
		"op=[0,0,0];"
		"axx=[1,0,0];"
		"axy=[0,1,0];"
		"axz=[0,0,1];"
		"anx=[-1,0,0];"
		"any=[0,-1,0];"
		"anz=[0,0,-1];"
		);

	return true;
}

/**
 * \brief regist command with help string
 */
void OCCViewer::regcmd(const char* name, mrb_func_t func, int arg_req, int arg_opt, const char* desc, const char* usage)
{
	// mrb_define_method(ステータス, 登録先, コマンド名, 関数, コマンドが受け取る引数の情報);
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, name, func, MRB_ARGS_REQ(arg_req) | MRB_ARGS_OPT(arg_opt));

	structHelp* myHelp = new structHelp;
	myHelp->desc = new std::string(desc);
	myHelp->usage = new std::string(usage);
	Help[std::string(name)] = myHelp;

	return;
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
	AISContext->Erase(myShape, Standard_True);
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
	mrb_value vec;
	int argc = mrb_get_args(mrb, "SA", &name, &vec);

	gp_Pnt pvec = *ar2pnt(mrb, vec);
	gp_Vec myvec(pvec.X(), pvec.Y(), pvec.Z());

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
    T.SetTranslation(myvec);

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
	mrb_float a;
	mrb_value pos, norm;
	int argc = mrb_get_args(mrb, "SAAf", &name, &pos, &norm, &a);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	Standard_Real ang = (double)a * (M_PI / 180.0);
	gp_Ax1 ax = *ar2ax1(mrb, pos, norm);

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
    mrb_value name, pos;
	mrb_float s;
	int argc = mrb_get_args(mrb, "SfA", &name, &s, &pos);
	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));

	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Pnt p;
	if (argc == 2) {
		p = gp_Pnt(0, 0, 0);
	}
	else {
		p = *ar2pnt(mrb, pos);
	}

	gp_Trsf T;
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
    mrb_value name, pos, norm;
	int argc = mrb_get_args(mrb, "SAA", &name, &pos, &norm);

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	gp_Trsf T;
	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);
    T.SetMirror(ax);

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

gp_Pnt* OCCViewer::ar2pnt(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Pnt(x, y, z);
}

gp_Vec* OCCViewer::ar2vec(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Vec(x, y, z);
}

gp_Dir* OCCViewer::ar2dir(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Dir(x, y, z);
}

gp_Ax1* OCCViewer::ar2ax1(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax1(gpnt, gdir);
}

gp_Ax2* OCCViewer::ar2ax2(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax2(gpnt, gdir);
}

gp_Ax3* OCCViewer::ar2ax3(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax3(gpnt, gdir);
}

double OCCViewer::ar2double(mrb_state* mrb, mrb_value ary)
{
	double res = 0.0;
	mrb_value val = mrb_ary_shift(mrb, ary);

	if (mrb_nil_p(val))
		res = 0.0;
	else if (mrb_float_p(val))
		res = val.value.f;
	else if (mrb_fixnum_p(val))
		res = mrb_fixnum(val);
	else
		throw "value is not numric value.";

	return res;
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

mrbcmddef(help)
{
	mrb_value name;
	int argc = mrb_get_args(mrb, "S", &name);

	// prefixmatch
	std::string ptn = std::string("^") + std::string(RSTRING_PTR(name)) + std::string(".*");
	std::tr1::regex re(ptn);

	mrb_value ar = mrb_ary_new(mrb);

	std::map<std::string, structHelp*>::iterator it = Help.begin();
	for (; it != Help.end(); it++) {
		if (std::tr1::regex_match(it->first, re)) {
			mrb_value tar[3];
			tar[0] = mrb_str_new(mrb, it->first.c_str(), strlen(it->first.c_str()));
			tar[1] = mrb_str_new(mrb, it->second->desc->c_str(), strlen(it->second->desc->c_str()));
			tar[2] = mrb_str_new(mrb, it->second->usage->c_str(), strlen(it->second->usage->c_str()));
			mrb_ary_push(mrb, ar, mrb_ary_new_from_values(mrb, 3, tar));
		}
	}
	if ((int)mrb_ary_len(mrb, ar))
		return ar;
	else
		return mrb_nil_value();
}
