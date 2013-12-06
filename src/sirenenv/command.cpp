/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */
// stdafx.h で定義されている static な AISContext, Viewer, Map に直接
// アクセスするメソッドは、この中に実装しなければアクセスできない。今のところ。

#include "Stdafx.h"
#include "OCCViewer.h"

/**
 * \brief 
 */
bool OCCViewer::mruby_init()
{
	// init mruby interpretor
	myMirb = new Mirb();

	// コマンドの登録

	// General commands
	regcmd("help",      &help,      1,0, "Display help of command.",        "help(cmd) -> String[][name, dest, usage]");
	regcmd("version",   &version,   0,0, "",                                "version() -> String");

	// Infomation/Status commands
	regcmd("bndbox",    &bndbox,    1,0, "Get area of object exist.",       "bndbox(ObjID) -> Ary[min[X,Y,Z], max[X,Y,Z]]");
	regcmd("selected",  &selected,  0,0, "Get name of selected objects.",   "selected() -> Ary[ObjID, ...]");
	regcmd("type",      &type,      1,0, "Get type of object.",             "type(ObjID) -> Type");
	regcmd("exist",     &exist,     1,0, "Check exist.",                    "exist(ObjID) -> Boolean");

	// Edit object commands
	regcmd("copy",      &copy,      1,0, "Copy specified object.",          "copy(ObjID) -> ObjID");
	regcmd("erase",     &erase,     1,0, "Erase specified object.",         "erase(ObjID) -> nil");
	regcmd("close",			&close,			1,0, "Close a wire.",										"close( ObjID ) -> ObjID");

	// Group commands
	regcmd("compound",  &compound,  1,0, "Make compound model by objects.", "compound([ObjID, ObjID, ...]) -> ObjID");
	regcmd("sew",       &sew,       1,1, "Make shell model by objects.",    "sew([ObjID, ObjID, ...]) -> ObjID");
	regcmd("explode",   &explode,   2,0, "Explode object to children.",     "explode(type, ObjID) -> Ary");

	// Transform commands
	regcmd("translate", &translate, 2,0, "Translate specified object.",     "translate(obj, vector[X, Y, Z]) -> nil");
	regcmd("rotate",    &rotate,    4,0, "Rotate specified object.",        "rotate(obj, center[X, Y, Z], normal[X, Y, Z], angle) -> nil"); 
	regcmd("scale",     &scale,     3,0, "Scale specified object.",         "scale(obj, scale, center[X, Y, Z] = [0, 0, 0]) -> nil");
	regcmd("mirror",    &mirror,    3,0, "Mirror copy specified object.",   "mirror(obj, center[X, Y, Z], normal[X, Y, Z]) -> nil");

	// Visualization commands
	regcmd("display",   &display,   1,0, "Dislay object.",                  "display(obj) -> nil");
	regcmd("hide",      &hide,      1,0, "Hide object.",                    "hide(obj) -> nil");
	regcmd("fit",       &fit,       0,0, "Fit view to objects",             "fit() -> nil");
	regcmd("update",    &update,    0,0, "Update current viewer.",          "update() -> nil");
	regcmd("color",     &color,     4,0, "Set color of object.",            "color(obj, R, G, B) -> nil");
	regcmd("bgcolor",   &bgcolor,   3,3, "Set color of background.",        "bgcolor(topR, topG, topB, btmR, btmG, btmB) -> nil");

	// Boolean operation commands
	regcmd("common",    &common,    2,1, "Common boolean operation.",       "common(obj1, obj2) -> String");
	regcmd("cut",       &cut,       2,1, "Cut boolean operation.",          "cut(obj1, obj2) -> String");
	regcmd("fuse",      &fuse,      2,1, "Fuse boolean operation.",         "fuse(obj1, obj2) -> String");
	regcmd("volume",    &volume,    1,0, "Get volume of object.",           "volume(obj) -> float");
	regcmd("cog",       &cog,       1,0, "Get center position of gravity",  "cog(obj) -> float[X, Y, Z]");
	regcmd("intersect", &intersect, 2,0, "Get intersection line.",          "intersect(obj1, obj2) -> ObjID)");

	// Make object commands
	regcmd("vertex",    &vertex,    3,0, "Make a vertex.",                  "vertex(X, Y, Z) -> String");
	regcmd("line",      &line,      2,0, "Make a line.",                    "line(sp[X, Y, Z], tp[X, Y, Z]) -> String");
	regcmd("polyline",  &polyline,  1,0, "Make a polyline.",                "polyline(pts[[X, Y, Z], ...]) -> String");
	regcmd("curve",     &curve,     1,1, "Make a curve.",                   "curve(pts[[X, Y, Z], ...], vecs[[X, Y, Z], ...]) -> String");
	regcmd("box",       &box,       1,1, "Make a box.",                     "box(size[X, Y, Z], pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("sphere",    &sphere,    1,1, "Make a sphere.",                  "sphere(R, pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("cylinder",  &cylinder,  5,0, "Make a cylinder.",                "cylinder(pos[X, Y, Z], normal[X, Y, Z], R, height, angle) -> String");
	regcmd("cone",      &cone,      6,0, "Make a cone.",                    "cone(pos[X, Y, Z], normal[X, Y, Z], R1, R2, height, angle) -> String");
	regcmd("torus",     &torus,     7,0, "Make a torus.",                   "torus(pos[X, Y, Z], normal[X, Y, Z]], R1, R2, angle1, angle2, angle) -> String");
	regcmd("plane",     &plane,     6,0, "Make a plane.",                   "plane(pos[X, Y, Z], normal[X, Y, Z], umin, umax, vmin, vmax) -> String");
	regcmd("wire",			&wire,			1,0, "Make a wire.",										"wire( Ary[edge or wire or comp obj] ) -> String");
	regcmd("sweep",     &sweep,			2,0, "Make a sweep model.",             "sweep( profile obj, vec[X, Y, Z] ) -> String | sweep( profile obj, path obj ) -> String");

	// Convertion commands
	regcmd("wire2pts",  &wire2pts,  1,1, "Convert wire to points.",         "wire2pts(ObjID) -> Ary[[X, Y, Z], ...]");

	// I/O commands
	regcmd("bsave",     &savebrep,  2,0, "Save object to a file.",          "bsave(path, obj) -> nil");
	regcmd("bload",     &loadbrep,  1,0, "Load object from a file.",        "bload(path) -> ID");
	regcmd("isave",     &saveiges,  2,0, "Save object to an IGES.",         "isave(path, obj) -> nil");
	regcmd("iload",     &loadiges,  1,0, "Load object from an IGES.",       "iload(path) -> Ary");

	// デフォルトのグローバル変数定義
	myMirb->user_exec(
		"DRAW=1;"
		"tri10=[10,10,10];"
		"op=[0,0,0];"
		"axx=[1,0,0];"
		"axy=[0,1,0];"
		"axz=[0,0,1];"
		"anx=[-1,0,0];"
		"any=[0,-1,0];"
		"anz=[0,0,-1];"
		);
	//myMirb->user_exec("class Stype;private_class_method :new;COMPOUND=0;COMPSOLID=1;SOLID=2;SHELL=3;FACE=4;WIRE=5;EDGE=6;VERTEX=7;SHAPE=8;end\n");
	myMirb->user_exec("class Stype;COMPOUND=0;COMPSOLID=1;SOLID=2;SHELL=3;FACE=4;WIRE=5;EDGE=6;VERTEX=7;SHAPE=8;end\n");

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

/**
 * \brief 
 */
bool OCCViewer::mruby_cleenup()
{
	if (myMirb)
		free(myMirb);
	return true;
}

/**
 * \brief 
 */
int OCCViewer::mruby_exec(char* command)
{
	std::string errmsg;
	return myMirb->user_exec(command, errmsg);
}

/**
 * \brief 
 */
int OCCViewer::mruby_exec(char* command, std::string& errmsg)
{
	if (!myMirb)
		return -1;

	AISContext = myAISContext;
	if (AISContext.IsNull())
		return -1;
	View = myView;
	if (View.IsNull())
		return -1;

	return myMirb->user_exec(command, errmsg);
}

/**
 * \brief 
 */
int set(const TopoDS_Shape& shape)
{
	return ::set(shape, 1);
}

/**
 * \brief 
 */
int set(const TopoDS_Shape& shape, int draw)
{
	Handle(AIS_Shape) hashape = new AIS_Shape(shape);
	// registration
	int hashcode = shape.HashCode(INT_MAX);
	::Map[hashcode] = hashape;

	// display
	if (AISContext.IsNull()) {
		throw "No AIS Interactive Context.";
	}
	AISContext->SetMaterial(hashape, /*Graphic3d_NameOfMaterial::*/Graphic3d_NOM_DEFAULT);
	AISContext->SetColor(hashape, Quantity_NOC_WHITE, Standard_False);
	AISContext->SetDisplayMode(hashape, 1/* 0:wireframe, 1:shading */, Standard_False);
	AISContext->SetSelected(hashape, Standard_False);

	Handle(Graphic3d_ShaderProgram) myShader;
	myShader = new Graphic3d_ShaderProgram(Graphic3d_ShaderProgram::ShaderName_Phong);
	hashape->Attributes()->ShadingAspect()->Aspect()->SetShaderProgram(myShader);

	if (draw) {
		AISContext->Display(hashape);
		AISContext->UpdateCurrentViewer();
	}
	return hashcode;
}

/**
 * \brief 
 */
void unset(int hashcode)
{
	Handle(AIS_Shape) myShape = ::get(hashcode);
	AISContext->Erase(myShape, Standard_True);
	if (::Map.find(hashcode) == ::Map.end())
		return;
	::Map.erase(hashcode);
	return;
}

/**
 * \brief 
 */
Handle(AIS_Shape) get(int hashcode)
{
	if (::Map.find(hashcode) == ::Map.end())
		return NULL;
	return ::Map[hashcode];
}

/**
 * \brief 
 */
bool has_object(int hashcode)
{
	return ::Map.find(hashcode) != ::Map.end();
}

// ------

/**
 * \brief 
 */
mrb_value update(mrb_state* mrb, mrb_value self)
{
	AISContext->UpdateCurrentViewer();
	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value display(mrb_state* mrb, mrb_value self)
{
	if (AISContext.IsNull())
		return mrb_nil_value();

    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified argument.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	AISContext->Display(hashape, Standard_False);
	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value hide(mrb_state* mrb, mrb_value self)
{
	if (AISContext.IsNull())
		return mrb_nil_value();

    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified argument.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	AISContext->Erase(hashape, Standard_False);
	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value fit(mrb_state* mrb, mrb_value self)
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

/**
 * \brief 
 */
mrb_value color(mrb_state* mrb, mrb_value self)
{
    mrb_int target; 
	mrb_float r, g, b;
	int argc = mrb_get_args(mrb, "ifff", &target, &r, &g, &b);

	Handle(AIS_Shape) hashape = ::get(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	Quantity_Color col =  Quantity_Color(r/255., g/255., b/255., Quantity_TOC_RGB);
    AISContext->SetColor(hashape, col.Name());

	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value bgcolor(mrb_state* mrb, mrb_value self)
{
	mrb_float tr, tg, tb, br, bg, bb;
	int argc = mrb_get_args(mrb, "fff|fff", &tr, &tg, &tb, &br, &bg, &bb);

	if (argc == 6) {
	    Quantity_Color color_top(tr/255, tg/255, tb/255, Quantity_TOC_RGB);
	    Quantity_Color color_btm(br/255, bg/255, bb/255, Quantity_TOC_RGB);
	    View->SetBgGradientColors(color_top, color_btm, Aspect_GFM_VER, Standard_True);
	}
	else if (argc == 3) {
	    Quantity_Color color(tr/255, tg/255, tb/255, Quantity_TOC_RGB);
		View->SetBackgroundColor(color);
		View->Redraw();
	}
	else {
		static const char m[] = "Incorrect number of arguments.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_nil_value();
}

// ------

/**
 * \brief help for commands
 */
mrb_value help(mrb_state* mrb, mrb_value self)
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

// ------

