/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"
#include "OCCViewer.h"

#define USECLASS 0

/**
 * \brief 
 */
bool OCCViewer::mruby_init()
{
	// init mruby interpretor
	myMirb = new Mirb();

	// コマンドの登録

    // 実装予定コマンド
    // arc                  ... 円弧曲線を作成する
    // circle               ... 円曲線を作成する。内部的にはarcと同じ？
    // 視点制御系コマンド
    // ビュー管理系コマンド

	// General commands
	regcmd("help",      &help,      1,0, "Display help of command.",        "help(cmd) -> String[][name, dest, usage]");
	regcmd("version",   &version,   0,0, "",                                "version() -> String");
	regcmd("debug",     &debug,     0,1, "",                                "");
    regcmd("all",       &all,       0,0, "Get an array of all objects.",    "all() -> Ary[ObjID, ...]");

	// Infomation/Status commands
	regcmd("bndbox",    &bndbox,    1,0, "Get area of object exist.",       "bndbox(ObjID) -> Ary[min[X,Y,Z], max[X,Y,Z]]");
	regcmd("selected",  &selected,  0,0, "Get name of selected objects.",   "selected() -> Ary[ObjID, ...]");
	regcmd("type",      &type,      1,0, "Get type of object.",             "type(ObjID) -> Type");
	regcmd("exist",     &exist,     1,0, "Check exist.",                    "exist(ObjID) -> Boolean");
	regcmd("location",  &location,  1,1, "Get/Set location of shape in WCS.","location(ObjID, [X,Y,Z]) -> Ary[X,Y,Z]");
    regcmd("cparam",    &cparam,    2,0, "Get curve parameter at a point.", "cparam(obj, [X, Y, Z]) -> [int index, float param]");
    regcmd("cpoint",    &cpoint,    2,0, "Get point from parameter.",       "cpoint(obj, cparam) -> [X, Y, Z]");
    regcmd("ccurvature",&ccurvature,2,0, "Get curvature vector.",           "ccurvature(obj, cparam) -> [X, Y, Z]");
    regcmd("ctangent",  &ctangent  ,2,0, "Get tangent vector.",             "ctangent(obj, cparam) -> [X, Y, Z]");

	// Edit object commands
	regcmd("copy",      &copy,      1,0, "Copy specified object.",          "copy(ObjID) -> ObjID");
	regcmd("erase",     &erase,     1,0, "Erase specified object.",         "erase(ObjID) -> nil");
	regcmd("close",		&close,		1,0, "Close a wire.",                   "close( ObjID ) -> ObjID");

	// Group commands
	regcmd("compound",  &compound,  1,0, "Make compound model by objects.", "compound([ObjID, ObjID, ...]) -> ObjID");
	regcmd("sew",       &sew,       1,1, "Make shell model by objects.",    "sew([ObjID, ObjID, ...]) -> ObjID");
	regcmd("explode",   &explode,   2,0, "Explode object to children.",     "explode(type, ObjID) -> Ary");

	// Transform commands
	regcmd("translate", &translate, 2,0, "Translate specified object.",     "translate(obj, vector[X, Y, Z]) -> ObjID");
	regcmd("rotate",    &rotate,    4,0, "Rotate specified object.",        "rotate(obj, center[X, Y, Z], normal[X, Y, Z], angle) -> ObjID"); 
	regcmd("scale",     &scale,     3,0, "Scale specified object.",         "scale(obj, scale, center[X, Y, Z] = [0, 0, 0]) -> ObjID");
	regcmd("mirror",    &mirror,    3,0, "Mirror copy specified object.",   "mirror(obj, center[X, Y, Z], normal[X, Y, Z]) -> ObjID");

	// Visualization commands
	regcmd("display",   &display,   1,1, "Dislay object.",                  "display(obj, activate = true) -> nil");
	regcmd("hide",      &hide,      1,0, "Hide object.",                    "hide(obj) -> nil");
	regcmd("fit",       &fit,       0,0, "Fit view to objects",             "fit() -> nil");
	regcmd("update",    &update,    0,0, "Update current viewer.",          "update() -> nil");
	regcmd("color",     &color,     1,3, "Set/Get color of shape.",         "color(obj, R, G, B) -> nil");
    regcmd("material",  &material,  1,1, "Set/Get material of shape.",      "material(obj, material_no) -> nil|material_no");
	regcmd("bgcolor",   &bgcolor,   3,3, "Set color of background.",        "bgcolor(topR, topG, topB, btmR, btmG, btmB) -> nil");
	regcmd("transparency", &transparency, 2,0, "Set transparency of object.", "transparency(obj, value = 0.0(non-clear) to 1.0(clear)) -> nil");
	regcmd("select",    &select,    1,0, "Select an object.",               "select(ObjID) -> nil");
	regcmd("clipon",    &clipon,    3,1, "",                                "clipon(name, pos[x, y, z], dir[x, y, z]) -> nil");
	regcmd("clipoff",   &clipoff,   1,0, "",                                "clipoff(name) -> nil");
    regcmd("activate",  &activate,  1,0, "",                                "");

	// Boolean operation commands
	regcmd("common",    &common,    2,1, "Common boolean operation.",       "common(obj1, obj2) -> String");
	regcmd("cut",       &cut,       2,1, "Cut boolean operation.",          "cut(obj1, obj2) -> String");
	regcmd("fuse",      &fuse,      2,1, "Fuse boolean operation.",         "fuse(obj1, obj2) -> String");
	regcmd("volume",    &volume,    1,0, "Get volume of object.",           "volume(obj) -> float");
	regcmd("cog",       &cog,       1,0, "Get center position of gravity",  "cog(obj) -> float[X, Y, Z]");
	regcmd("area",      &area,      1,0, "Get square measure of surface.",  "area(obj) -> float");
	regcmd("intersect", &intersect, 2,0, "Get intersection line.",          "intersect(obj1, obj2) -> ObjID");
	regcmd("intcs",     &intcs,     2,1, "Intersection Curve x Surface",    "intcs(obj_curve, obj_surf, with_normal) -> [float[X, Y, Z], ...]");
	regcmd("intfe",     &intfe,     2,1, "Intersection Face x Edge",        "intfe(face, edge) -> [float[X, Y, Z], ...]");
    regcmd("isin",      &isin,      2,0, "Check a point located in a solid.","isin([X, Y, Z], solid) -> 0/1/-1");

	regcmd("split",     &split,     2,0, "",                                "");

	// Make object commands
	regcmd("vertex",    &vertex,    3,0, "Make a vertex.",                  "vertex(X, Y, Z) -> Shape");
	regcmd("line",      &line,      2,0, "Make a line.",                    "line([X, Y, Z], [X, Y, Z]) -> Shape");
	regcmd("polyline",  &polyline,  1,0, "Make a polyline.",                "polyline(pts[[X, Y, Z], ...]) -> String");
	regcmd("curve",     &curve,     1,1, "Make a curve.",                   "curve(pts[[X, Y, Z], ...], vecs[[X, Y, Z], ...]) -> String");
	regcmd("box",       &box,       1,1, "Make a box.",                     "box(size[X, Y, Z], pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("sphere",    &sphere,    1,1, "Make a sphere.",                  "sphere(R, pos[X, Y, Z] = [0, 0, 0]) -> String");
	regcmd("cylinder",  &cylinder,  5,0, "Make a cylinder.",                "cylinder(pos[X, Y, Z], normal[X, Y, Z], R, height, angle) -> String");
	regcmd("cone",      &cone,      6,0, "Make a cone.",                    "cone(pos[X, Y, Z], normal[X, Y, Z], R1, R2, height, angle) -> String");
	regcmd("torus",     &torus,     7,0, "Make a torus.",                   "torus(pos[X, Y, Z], normal[X, Y, Z], R1, R2, angle) -> String");
    regcmd("plane",     &plane,     7,0, "Make a plane.",                   "plane(pos[X, Y, Z], normal[X, Y, Z], umin, umax, vmin, vmax) -> String");
	regcmd("polygon",   &polygon,   1,0, "Make a plane by contour points.", "");
	regcmd("wire",	    &wire,      1,0, "Make a wire.",                    "wire( Ary[edge or wire or comp obj] ) -> String");
	regcmd("sweepv",    &sweepv,    2,0, "Make a sweep model with vector.", "sweepv(profile obj, vec[X, Y, Z]) -> objID");
	regcmd("sweepp",    &sweepp,    2,4, "Make a sweep model with path.",   "sweepp(profile obj, path obj) -> objID");
	regcmd("loft",      &loft,      1,0, "Make a loft surface.",            "loft(Array[obj]) -> ObjID");
    regcmd("bscurve",   &bscurve,   0,0, "Make a B-spline curve.",          "");
    regcmd("bzsurf",    &bzsurf,    1,1, "Make a bezier surface.",          "bzsurf([[pu, ...], [pv, ...]], [[wu, ...], [wv, ...]]) -> ObjID");
    regcmd("bssurf",    &bssurf,    0,0, "Make a B-spline surface.",        "");
    regcmd("offset",    &offset,    1,1, "Make an offset surface.",         "offset(surface, offset_value) -> ObjID");
    regcmd("thick",     &thick,     2,0, "Make a thicknessed solid.",        "thick(surface, offset_value) -> ObjID");

    regcmd("projw",     &projw,     3,0, "Make a cylindrical projection of wire on surface.", "");

	// Convertion commands
	regcmd("wire2pts",  &wire2pts,  1,1, "Convert wire to points.",         "wire2pts(ObjID) -> Ary[[X, Y, Z], ...]");
	regcmd("wire2face", &wire2face, 1,1, "Make a face with boundary wire.", "wire2face(wire, is_plane = false) -> String");
	regcmd("shell2solid",&shell2solid,1,0, "Make a solid by shell.",        "shell2solid(ObjID) -> ObjID");
    regcmd("triangle",  &triangle,  1,2, "Make triangle mesh from face.",   "triangle(ObjID, Deflection, Angle) -> ObjID");

	// I/O commands
	regcmd("brepsave",  &savebrep,  2,0, "Save object to a file.",          "brepsave(path, obj) -> nil");
	regcmd("brepload",  &loadbrep,  1,0, "Load object from a file.",        "brepload(path) -> Shape");
	regcmd("igessave",  &saveiges,  2,0, "Save object to an IGES.",         "igessave(path, obj) -> nil");
	regcmd("igesload",  &loadiges,  1,0, "Load object from an IGES.",       "igesload(path) -> Shape");
	regcmd("stlload",   &loadstl,   1,0, "Load object from an STL file.",   "stlload(path) -> Shape");
	regcmd("stlsave",   &savestl,   2,0, "Save object to an STL file.",     "stlsave(obj, path) -> nil");
    regcmd("vrmlsave",  &savevrml,  2,0, "Save object to a VRML file.",     "vrmlsave(obj, path) -> nil");

	// regcmd("selmode",   &selmode,   1,0, "Change selection mode.",          "");

	// デフォルトのグローバル変数定義
	myMirb->user_exec(
		"$DRAW = true;"
		"$ACTIVE = true;"
		"$DIST = 10;"
		"$ANG = 15;"
		"$SUP = 1.25;"
		"$SDOWN = 0.75;"
		"$tri10 = [10,10,10];"
        "def is_draw; $DRAW; end;"
        "def is_active; $ACTIVE; end;"
		);

    // バイトコードのロード
    loadbc(myMirb->mrb);

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

	cur = this;
	if (cur == NULL)
		return -1;

#if 0
	cur->aiscxt = aiscxt;
	if (cur->aiscxt.IsNull())
		return -1;
	cur->view = view;
	if (cur->view.IsNull())
		return -1;
#endif

	int res = myMirb->user_exec(command, errmsg);

	return res;
}

/**
 * \brief 
 */
int set(const TopoDS_Shape& shape, const mrb_value& self)
{
    int code = shape.HashCode(INT_MAX);
    cur->shapeman.insert(std::pair<int, TopoDS_Shape>(code, shape));

    mrb_value r = mrb_funcall(cur->myMirb->mrb, self, "is_draw", 0);
    mrb_value a = mrb_funcall(cur->myMirb->mrb, self, "is_active", 0);
    if (mrb_bool(r)) {
        display(shape, mrb_bool(a), true);
    }

    return code;
	// return shape.HashCode(INT_MAX);
}

#if USECLASS
int regist(const TopoDS_Shape& shape, mrb_value& result, bool drawnow = true)
{
	if (cur->aiscxt.IsNull()) {
		throw "No AIS Interactive Context.";
	}
	Handle(AIS_Shape) hashape = new AIS_Shape(shape);

	Handle(Graphic3d_ShaderProgram) myShader;
	myShader = new Graphic3d_ShaderProgram(Graphic3d_ShaderProgram::ShaderName_Phong);
	hashape->Attributes()->ShadingAspect()->Aspect()->SetShaderProgram(myShader);

	cur->aiscxt->SetMaterial(hashape, /*Graphic3d_NameOfMaterial::*/Graphic3d_NOM_DEFAULT);
	cur->aiscxt->SetColor(hashape, Quantity_NOC_WHITE, Standard_False);
	cur->aiscxt->SetDisplayMode(hashape, 1/* 0:wireframe, 1:shading */, Standard_False);

	cur->aiscxt->Display(hashape);
	cur->aiscxt->SetSelected(hashape, Standard_False);
	cur->aiscxt->UpdateCurrentViewer();

    int hashcode = shape.HashCode(INT_MAX);

    int m = cur->myMirb->mrb->live;

    const char* ivname = "@id";
    RClass* prclass = mrb_class_get(cur->myMirb->mrb, "Shape");

    result = mrb_class_new_instance(cur->myMirb->mrb, 0, NULL, prclass);

    RObject* pobj = mrb_obj_ptr(result);
    mrb_sym sym = mrb_intern(cur->myMirb->mrb, ivname, strlen(ivname));
    mrb_obj_iv_set(cur->myMirb->mrb, pobj, sym, mrb_fixnum_value(hashcode));

    int n = cur->myMirb->mrb->live;

    return 0;
}
#endif

TopoDS_Shape& getTopoDSShape(int hashcode)
{
    if (cur->shapeman.count(hashcode) == 0) {
        throw;
    }
    return cur->shapeman[hashcode];
}

int updateTopoDSShape(int oldhashcode, const TopoDS_Shape& shape)
{
    if (cur->shapeman.count(oldhashcode) > 0) {
        cur->shapeman.erase(oldhashcode);
    }

    int code = shape.HashCode(INT_MAX);
    cur->shapeman.insert(std::pair<int, TopoDS_Shape>(code, shape));

    return code;
}

/**
 * \brief 
 */
Handle(AIS_Shape) getAISShape(int hashcode)
{
#if 0
	// これだと選択されたものから探すので
    cur->aiscxt->InitCurrent();
    for (; cur->aiscxt->MoreCurrent(); cur->aiscxt->NextCurrent()) {
		Handle(AIS_InteractiveObject) aisobj = cur->aiscxt->Current();
		Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(aisobj);
        if (hashcode == hashape->Shape().HashCode(INT_MAX))
            return hashape;
    }
    return NULL;
#else

        // こっちが正解
        AIS_ListOfInteractive ar;
        cur->aiscxt->ObjectsInside(ar);
        AIS_ListIteratorOfListOfInteractive it(ar);
        for (; it.More(); it.Next()) {
            Handle(AIS_InteractiveObject) aisobj = it.Value();
            Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(aisobj);
            if (hashcode == hashape->Shape().HashCode(INT_MAX))
                return hashape;
        }

	return NULL;
#endif
}

#if USECLASS
Handle(AIS_Shape) get(mrb_value obj)
{
    const char* ivname = "@id"; 
    RObject* pobj = mrb_obj_ptr(obj);
    mrb_sym sym = mrb_intern(cur->myMirb->mrb, ivname, strlen(ivname));
    mrb_value val = mrb_obj_iv_get(cur->myMirb->mrb, pobj, sym);
    int hashcode;
	if (mrb_fixnum_p(val))
		hashcode = mrb_fixnum(val);
    else
        return NULL;

	AIS_ListOfInteractive ar;
	cur->aiscxt->ObjectsInside(ar);
	AIS_ListIteratorOfListOfInteractive it(ar);
	for (; it.More(); it.Next()) {
		Handle(AIS_InteractiveObject) aisobj = it.Value();
		Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(aisobj);
        if (hashcode == hashape->Shape().HashCode(INT_MAX))
            return hashape;
	}
	return NULL;
}
#endif

/**
 * \brief 
 */
void unset(int hashcode)
{
	Handle(AIS_Shape) hashape = ::getAISShape(hashcode);
    if (!hashape.IsNull()) {
    	cur->aiscxt->Erase(hashape, Standard_False);
    }
    if (cur->shapeman.count(hashcode) > 0) {
        cur->shapeman[hashcode].Nullify();
        cur->shapeman.erase(hashcode);
    }
	return;
}

/**
 * \brief 
 */
bool has_object(int hashcode)
{
	TopoDS_Shape shape = getTopoDSShape(hashcode);
	return !shape.IsNull();
}

/**
 * \brief 
 */
void redisplay(const Handle(AIS_Shape)& hashape)
{
	cur->aiscxt->Redisplay(hashape, Standard_True);
}

// ------

/**
 * \brief 
 */
mrb_value update(mrb_state* mrb, mrb_value self)
{
	cur->aiscxt->UpdateCurrentViewer();
	return mrb_nil_value();
}

/**
 * \brief 
 */
void display(const TopoDS_Shape& shape, bool activate, bool shaded)
{
	if (cur->aiscxt.IsNull()) {
		throw "No AIS Interactive Context.";
	}

	Handle(AIS_Shape) hashape = new AIS_Shape(shape);
    TopAbs_ShapeEnum type = shape.ShapeType();

    if (type == TopAbs_COMPOUND || type == TopAbs_SOLID || type == TopAbs_SHELL || type == TopAbs_FACE) {

    	//Handle(Graphic3d_ShaderProgram) myShader;
    	//myShader = new Graphic3d_ShaderProgram(Graphic3d_ShaderProgram::ShaderName_Phong);
    	//hashape->Attributes()->ShadingAspect()->Aspect()->SetShaderProgram(myShader);

    	cur->aiscxt->SetMaterial(hashape, /*Graphic3d_NameOfMaterial::*/Graphic3d_NOM_DEFAULT);
        if (shaded)
        	cur->aiscxt->SetDisplayMode(hashape, 1/* 0:wireframe, 1:shading */, Standard_False);
        else
        	cur->aiscxt->SetDisplayMode(hashape, 0/* 0:wireframe, 1:shading */, Standard_False);
    }
	cur->aiscxt->SetColor(hashape, Quantity_NOC_WHITE, Standard_False);

	cur->aiscxt->Display(hashape);

    if (activate) {
        cur->aiscxt->Activate(hashape);
    	cur->aiscxt->SetSelected(hashape, Standard_False);
    }
    else {
        cur->aiscxt->Deactivate(hashape);
    }

    return;
}

/**
 * \brief 
 */
mrb_value display(mrb_state* mrb, mrb_value self)
{
	if (cur->aiscxt.IsNull())
		return mrb_nil_value();

    mrb_value obj;
    mrb_bool is_active;
    mrb_bool is_shaded;
    int argc = mrb_get_args(mrb, "o|bb", &obj, &is_active, &is_shaded);
    if (mrb_fixnum_p(obj)) {
    	Handle(AIS_Shape) hashape = ::getAISShape(mrb_fixnum(obj));
    	if (!hashape.IsNull())
            redisplay(hashape);
        else
            display(cur->shapeman[mrb_fixnum(obj)], (bool)is_active, (bool)is_shaded);
    }
    else if (mrb_array_p(obj)) {
        for (int i=0; i<mrb_ary_len(mrb, obj); i++) {
            mrb_value item = mrb_ary_ref(mrb, obj, i);
            mrb_int hc = mrb_fixnum(item);
            Handle(AIS_Shape) hashape = ::getAISShape(hc);
            if (!hashape.IsNull())
                redisplay(hashape);
            else
                display(cur->shapeman[hc], (bool)is_active, (bool)is_shaded);
        }
    }
    else {
        static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }
	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value hide(mrb_state* mrb, mrb_value self)
{
	if (cur->aiscxt.IsNull())
		return mrb_nil_value();

    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	Handle(AIS_Shape) hashape = ::getAISShape(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified argument.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	cur->aiscxt->Erase(hashape, Standard_True);

	return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value fit(mrb_state* mrb, mrb_value self)
{
	if (!cur->view.IsNull()) {
		cur->view->FitAll();
		cur->view->ZFitAll();
	}
	else {
		static const char m[] = "cur->view is NULL object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_nil_value();
}

/**
 * \brief Set/Get color of shape.
 */
mrb_value color(mrb_state* mrb, mrb_value self)
{
    mrb_int target; 
	mrb_float r, g, b;
	int argc = mrb_get_args(mrb, "i|fff", &target, &r, &g, &b);

	Handle(AIS_Shape) hashape = ::getAISShape(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    if (argc == 4) {
        // Set color
    	Quantity_Color col =  Quantity_Color(
            (Standard_Real)(r / 255.0),
            (Standard_Real)(g / 255.0),
            (Standard_Real)(b / 255.0),
            Quantity_TOC_RGB);
    	Quantity_NameOfColor colname = col.Name();
    	cur->aiscxt->SetColor(hashape, colname, Standard_True);
    	return mrb_nil_value();
    }
    else {
        // Get color
        if (!hashape->HasColor())
        	return mrb_nil_value();

        Quantity_Parameter R, G, B;
        Quantity_Color col = cur->aiscxt->Color(hashape);
        col.Values(R, G, B, Quantity_TOC_RGB);

        mrb_value res = mrb_ary_new(mrb);
        mrb_ary_push(mrb, res, mrb_fixnum_value((int)(R * 255.0)));
        mrb_ary_push(mrb, res, mrb_fixnum_value((int)(G * 255.0)));
        mrb_ary_push(mrb, res, mrb_fixnum_value((int)(B * 255.0)));
        return res;
    }

	return mrb_nil_value();
}

/**
 * \brief Set/Get material of shape.
 */
mrb_value material(mrb_state* mrb, mrb_value self)
{
    mrb_int target, mno;
	int argc = mrb_get_args(mrb, "i|i", &target, &mno);

	Handle(AIS_Shape) hashape = ::getAISShape(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    if (argc == 2) {
        // Set material by material no.
        cur->aiscxt->SetMaterial(hashape, (Graphic3d_NameOfMaterial)mno);
    }
    else {
        // Get material no of shape.
        return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
    }
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
	    cur->view->SetBgGradientColors(color_top, color_btm, Aspect_GFM_VER, Standard_True);
	}
	else if (argc == 3) {
	    Quantity_Color color(tr/255, tg/255, tb/255, Quantity_TOC_RGB);
		cur->view->SetBackgroundColor(color);
		cur->view->Redraw();
	}
	else {
		static const char m[] = "Incorrect number of arguments.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return mrb_nil_value();
}

mrb_value transparency(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	mrb_float value;
	int argc = mrb_get_args(mrb, "if", &target, &value);

    Handle(AIS_Shape) hashape = ::getAISShape(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified argument.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    Standard_Real t = (Standard_Real)value;
    if (t < 0.0)
        t = 0.0;
    else if (t > 1.0)
        t = 1.0;

	cur->aiscxt->SetTransparency(hashape, t);
	return mrb_nil_value();
}

/**
 * \brief Select an object by ID
 */
mrb_value select(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

    Handle(AIS_Shape) hashape = ::getAISShape(target);
	if (hashape.IsNull()) {
		static const char m[] = "No such object name of specified argument.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    cur->aiscxt->SetSelected(hashape, Standard_True);

    return mrb_nil_value();
}

/**
 * \brief Add and enable a clipping plane.
 */
mrb_value clipon(mrb_state* mrb, mrb_value self)
{
    mrb_int index;
    mrb_value pos, dir;
    mrb_bool use_cap;
	int argc = mrb_get_args(mrb, "iAA|b", &index, &pos, &dir, &use_cap);

    gp_Pnt gpos = *ar2pnt(mrb, pos);
    gp_Dir gdir = *ar2dir(mrb, dir);

    Handle(Graphic3d_ClipPlane) p = new Graphic3d_ClipPlane(gp_Pln(gpos, gdir));

    if (use_cap) {
        p->SetCapping(Standard_True);
        p->SetCappingMaterial(Graphic3d_MaterialAspect(Graphic3d_NOM_STONE));
        //p->SetCappingHatch(Aspect_HS_DIAGONAL_45_WIDE);
        //p->SetCappingHatchOn();
    }
    else {
        p->SetCapping(Standard_False);
    }

    if (cur->clipman.find(index) != cur->clipman.end()) {
        // Update when the index already exists.
        cur->clipman.erase(index);
    }
    cur->clipman.insert(std::pair<int, Handle(Graphic3d_ClipPlane)>(index, p));

    Graphic3d_SequenceOfHClipPlane ary;
    std::map<int, Handle(Graphic3d_ClipPlane)>::iterator it = cur->clipman.begin();
    for (; it != cur->clipman.end(); it++) {
        Handle(Graphic3d_ClipPlane) pp = (*it).second;
        pp->SetOn(Standard_True);
        ary.Append(pp);
    }
    cur->view->SetClipPlanes(ary);
    // hashape->SetClipPlanes(ary);

    mrb_load_string(mrb, "update");
    return mrb_nil_value();
}

/**
 * \brief Remove and disable a clipping plane.
 */
mrb_value clipoff(mrb_state* mrb, mrb_value self)
{
    mrb_int index;
	int argc = mrb_get_args(mrb, "i", &index);

    std::map<int, Handle(Graphic3d_ClipPlane)>::iterator it
        = cur->clipman.find(index);

    if (it == cur->clipman.end()) {
		static const char m[] = "No such index of clipping plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    Handle(Graphic3d_ClipPlane) pp = (*it).second;
    pp->SetOn(Standard_False);
    cur->clipman.erase((*it).first);
    
    mrb_load_string(mrb, "update");

    return mrb_nil_value();
}

mrb_value activate(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
    mrb_bool is_true;
    int argc = mrb_get_args(mrb, "ib", &target, &is_true);

    Handle(AIS_Shape) hashape = ::getAISShape(target);
    if (hashape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    if (is_true) {
        cur->aiscxt->Activate(hashape);
    }
    else {
        cur->aiscxt->Deactivate(hashape);
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

#ifdef _REGEX_
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
#else
	mrb_value ar = mrb_ary_new(mrb);

	std::map<std::string, structHelp*>::iterator it = Help.begin();

	char* target = RSTRING_PTR(name);
	for (; it != Help.end(); it++) {
		// 前方一致検索
		const char* current = it->first.c_str();
		if (strlen(target) > strlen(current))
			continue;
		bool is_match = true;
		for (int i = 0; i<(signed int)strlen(target); i++) {
			if (current[i] != target[i]) {
				is_match = false;
				break;
			}
		}
		// 一致していた場合
		if (is_match) {
			mrb_value tar[3];
			tar[0] = mrb_str_new(mrb, it->first.c_str(), strlen(it->first.c_str()));
			tar[1] = mrb_str_new(mrb, it->second->desc->c_str(), strlen(it->second->desc->c_str()));
			tar[2] = mrb_str_new(mrb, it->second->usage->c_str(), strlen(it->second->usage->c_str()));
			mrb_ary_push(mrb, ar, mrb_ary_new_from_values(mrb, 3, tar));
		}
	}

#endif
	if ((int)mrb_ary_len(mrb, ar))
		return ar;
	else
		return mrb_nil_value();
}

// ------


/**
 * \brief Get selected object
 */
mrb_value selected(mrb_state* mrb, mrb_value self)
{
	mrb_value ar = mrb_ary_new(mrb);
	char* aname = NULL;

	cur->aiscxt->InitCurrent();
	for (; cur->aiscxt->MoreCurrent(); cur->aiscxt->NextCurrent()) {
		Handle(AIS_InteractiveObject) anIO = cur->aiscxt->Current();
		Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(anIO);
		TopoDS_Shape shape = hashape->Shape();
		mrb_ary_push(mrb, ar, mrb_fixnum_value(shape.HashCode(INT_MAX)));
	}

	if ((int)mrb_ary_len(mrb, ar))
		return ar;
	else
		return mrb_nil_value();
}

/**
 * \brief 
 */
mrb_value selmode(mrb_state* mrb, mrb_value self)
{
	mrb_int type;
	int argc = mrb_get_args(mrb, "i", &type);

    cur->aiscxt->CloseAllContexts();
    cur->aiscxt->OpenLocalContext();
    cur->aiscxt->ActivateStandardMode((TopAbs_ShapeEnum)type);

    if (type == TopAbs_SHAPE) {
        cur->aiscxt->CloseAllContexts();
    }

    return mrb_nil_value();
}

/**
 * \brief Translate object
 */
mrb_value translate(mrb_state* mrb, mrb_value self)
{
	mrb_value vec;
    mrb_int target;
	int argc = mrb_get_args(mrb, "iA", &target, &vec);

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	gp_Pnt pvec = *ar2pnt(mrb, vec);
	gp_Vec myvec(pvec.X(), pvec.Y(), pvec.Z());
	gp_Trsf trsf;
	trsf.SetTranslation(myvec);
    shape.Move(trsf);

    mrb_value r = mrb_funcall(cur->myMirb->mrb, self, "is_draw", 0);
    if (mrb_bool(r)) {
        Handle(AIS_Shape) hashape = ::getAISShape(target);
        if (!hashape.IsNull()) {
            hashape->Set(shape);
            redisplay(hashape);
        }
    }

    return mrb_fixnum_value(updateTopoDSShape(target, shape));
}

/**
 * \brief Ratate object
 */
mrb_value rotate(mrb_state* mrb, mrb_value self)
{
	mrb_float a;
	mrb_value pos, norm;
    mrb_int target;
	int argc = mrb_get_args(mrb, "iAAf", &target, &pos, &norm, &a);

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	Standard_Real ang = (double)a * (M_PI / 180.0);
	gp_Ax1 ax = *ar2ax1(mrb, pos, norm);
	gp_Trsf trsf;
    trsf.SetRotation(ax, ang);
    shape.Move(trsf);

    mrb_value r = mrb_funcall(cur->myMirb->mrb, self, "is_draw", 0);
    if (mrb_bool(r)) {
        Handle(AIS_Shape) hashape = ::getAISShape(target);
        if (!hashape.IsNull()) {
            hashape->Set(shape);
            redisplay(hashape);
        }
    }

    return mrb_fixnum_value(updateTopoDSShape(target, shape));
}

/**
 * \brief Scale object
 */
mrb_value scale(mrb_state* mrb, mrb_value self)
{
	mrb_value pos;
	mrb_float s;
    mrb_int target;
	int argc = mrb_get_args(mrb, "ifA", &target, &s, &pos);

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    gp_Pnt p = (argc == 2) ? gp_Pnt(0, 0, 0) : *ar2pnt(mrb, pos);
	gp_Trsf trsf;
    trsf.SetScale(p, (Standard_Real)s);
    shape.Move(trsf);

    mrb_value r = mrb_funcall(cur->myMirb->mrb, self, "is_draw", 0);
    if (mrb_bool(r)) {
        Handle(AIS_Shape) hashape = ::getAISShape(target);
        if (!hashape.IsNull()) {
            hashape->Set(shape);
            redisplay(hashape);
        }
    }

    return mrb_fixnum_value(updateTopoDSShape(target, shape));
}

/**
 * \brief Mirror
 */
mrb_value mirror(mrb_state* mrb, mrb_value self)
{
    mrb_value pos, norm;
	mrb_int target;
	int argc = mrb_get_args(mrb, "iAA", &target, &pos, &norm);

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);
	gp_Trsf trsf;
    trsf.SetMirror(ax);
    shape.Move(trsf);

    mrb_value r = mrb_funcall(cur->myMirb->mrb, self, "is_draw", 0);
    if (mrb_bool(r)) {
        Handle(AIS_Shape) hashape = ::getAISShape(target);
        if (!hashape.IsNull()) {
            hashape->Set(shape);
            redisplay(hashape);
        }
    }
    return mrb_fixnum_value(updateTopoDSShape(target, shape));
}

/**
 * \brief make vertex
 */
mrb_value vertex(mrb_state* mrb, mrb_value self)
{
	mrb_float x, y, z;
	int argc = mrb_get_args(mrb, "fff", &x, &y, &z);

	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	TopoDS_Vertex v = BRepBuilderAPI_MakeVertex(p);

#if USECLASS
    mrb_value result;
    ::regist(v, result);
	return result;
#else
    return mrb_fixnum_value(::set(v, self));
#endif
}

/**
 * \brief make line
 */
mrb_value line(mrb_state* mrb, mrb_value self)
{
    mrb_value sp, tp;
    int argc = mrb_get_args(mrb, "AA", &sp, &tp);

	gp_Pnt _sp = *ar2pnt(mrb, sp);
	gp_Pnt _tp = *ar2pnt(mrb, tp);

	BRepBuilderAPI_MakeEdge line(_sp, _tp);
    TopoDS_Shape shape = line.Shape();

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make polyline
 */
mrb_value polyline(mrb_state* mrb, mrb_value self)
{
  mrb_value pts;
  int argc = mrb_get_args(mrb, "A", &pts);
	int psize = mrb_ary_len(mrb, pts);

	BRepBuilderAPI_MakePolygon poly;
	TopoDS_Shape shape;
	try {
		for (int i=0; i<psize; i++) {
			mrb_value pt = mrb_ary_ref(mrb, pts, i);
			gp_Pnt pnt = *ar2pnt(mrb, pt);
			poly.Add(pnt);
		}
		poly.Build();
        if (poly.IsDone()) {
            shape = poly.Wire();
        }

	}
    catch (...) {
		static const char m[] = "Failed to make a polyline.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if ( shape.IsNull() ) {
		static const char m[] = "Failed to make a polyline.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make arc
 */
mrb_value arc(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

/**
 * \brief make curve
 */
mrb_value curve(mrb_state* mrb, mrb_value self)
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
	}

    intp.Perform();
    Handle(Geom_BSplineCurve) geSpl = intp.Curve();
    TopoDS_Edge e = BRepBuilderAPI_MakeEdge(geSpl);
    TopoDS_Wire w = BRepBuilderAPI_MakeWire(e);

	delete(pary);

#if USECLASS
    mrb_value result;
    ::regist(w, result);
	return result;
#else
    return mrb_fixnum_value(::set(w, self));
#endif
}

/**
 * \brief make box
 */
mrb_value box(mrb_state* mrb, mrb_value self)
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

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make sphere
 */
mrb_value sphere(mrb_state* mrb, mrb_value self)
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

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make cylinder
 */
mrb_value cylinder(mrb_state* mrb, mrb_value self)
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

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make cone
 */
mrb_value cone(mrb_state* mrb, mrb_value self)
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

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make torus
 */
mrb_value torus(mrb_state* mrb, mrb_value self)
{
	mrb_float r1, r2, ang;
	mrb_value pos, norm;
	int argc = mrb_get_args(mrb, "AAfff", &pos, &norm, &r1, &r2, &ang);

	gp_Ax2 ax = *ar2ax2(mrb, pos, norm);

	TopoDS_Shape shape;
	try {
		BRepPrimAPI_MakeTorus prm(ax, (Standard_Real)r1, (Standard_Real)r2, (Standard_Real)ang);
	    shape = prm.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a torus.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make rectangle plane
 */
mrb_value plane(mrb_state* mrb, mrb_value self)
{
	mrb_value pos, norm, vdir;
	mrb_float umin, umax, vmin, vmax;
	int argc = mrb_get_args(mrb, "AAAffff", &pos, &norm, &vdir, &umin, &umax, &vmin, &vmax);

	gp_Pnt _pos = *ar2pnt(mrb, pos);
	gp_Dir _norm = *ar2dir(mrb, norm);
    gp_Dir _vdir = *ar2dir(mrb, vdir);
    gp_Ax3 ax(_pos, _norm, _vdir);
	gp_Pln _pln(ax);

	TopoDS_Shape shape;
	try {
		BRepBuilderAPI_MakeFace face(_pln, (Standard_Real)umin, (Standard_Real)umax, (Standard_Real)vmin, (Standard_Real)vmax);
	    shape = face.Shape();
	}
	catch (...) {
		static const char m[] = "Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make plane from contour points
 */
mrb_value polygon(mrb_state* mrb, mrb_value self)
{
    mrb_value pts;
	int argc = mrb_get_args(mrb, "A", &pts);
    
	BRepBuilderAPI_MakePolygon mp;

    for (int i=0; i<mrb_ary_len(mrb, pts); i++) {
        mrb_value p = mrb_ary_ref(mrb, pts, i);
		gp_Pnt pp = *ar2pnt(mrb, p);
        mp.Add(pp);
    }

    mp.Close();

	BRepBuilderAPI_MakeFace mf(mp.Wire(), true);

	mf.Build();

	if (!mf.IsDone()) {
		static const char m[] = "Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    TopoDS_Shape shape = mf.Shape();

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make surface by profile object and a vector
 */
mrb_value sweepv(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	mrb_value vec;
	int argc = mrb_get_args(mrb, "iA", &target, &vec);

    TopoDS_Shape profile = ::getTopoDSShape(target);
	if (profile.IsNull() ) {
		static const char m[] = "No such profile object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape;
	TopoDS_Wire path;

	try {
        gp_Pnt _vec = *ar2pnt(mrb, vec);
        gp_Pnt _pt = gp_Pnt(0., 0., 0.).Transformed(profile.Location());
        TopoDS_Edge pe = BRepBuilderAPI_MakeEdge(_pt, _vec);
        path = BRepBuilderAPI_MakeWire(pe);

		BRepOffsetAPI_MakePipe mp(path, profile);
		mp.Build();
		shape = mp.Shape();

		if (shape.IsNull()) {
			static const char m[] = "Failed to make a sweep model.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}
	catch (...) {
		static const char m[] = "Failed to make a sweep model.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make surface by profile-wire and path-wire
 */
mrb_value sweepp(mrb_state* mrb, mrb_value self)
{
	mrb_int target, pathwire;
    mrb_value cont, corr;
    mrb_float scale_first, scale_last;
	int argc = mrb_get_args(mrb, "ii|ooff", &target, &pathwire, &cont, &corr, &scale_first, &scale_last);

	TopoDS_Shape shape_profile = ::getTopoDSShape(target);
	if (shape_profile.IsNull() ) {
		static const char m[] = "No such profile object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    TopoDS_Shape shape_path = ::getTopoDSShape(pathwire);
    if (shape_path.IsNull()) {
        static const char m[] = "No such path object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	TopoDS_Shape shape;
	TopoDS_Wire path;

    if (shape_path.ShapeType() == TopAbs_EDGE) {
        path = BRepBuilderAPI_MakeWire(TopoDS::Edge(shape_path));
    }
    else if (shape_path.ShapeType() == TopAbs_WIRE) {
        path = TopoDS::Wire(shape_path);
    }
    else {
        static const char m[] = "Path object is not Edge or Wire.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	try {
        if (argc >= 3 && argc <= 6) {

            Standard_Boolean withContact = (Standard_Boolean)mrb_test(cont);
            Standard_Boolean withCorrection = (Standard_Boolean)mrb_test(corr);

            BRepOffsetAPI_MakePipeShell ps(path);

            // get params
            Standard_Real fparam, lparam;
            {
                BRepAdaptor_CompCurve cc(path);
                fparam = cc.FirstParameter();
                lparam = cc.LastParameter();
            }

            if (argc < 6) {
                scale_last  = 1.0;
                if (argc < 5) {
                    scale_first = 1.0;
                }
            }

            //Handle(Law_Linear) law = new Law_Linear();
            //law->Set(fparam, scale_first, lparam, scale_last);

            Handle(Law_S) law = new Law_S();
            law->Set(fparam, scale_first, lparam, scale_last);

            //Handle(Law_Composite) law = new Law_Composite(fparam, lparam, 1.0e-6);

            // get start point
            TopoDS_Vertex pfirst; {
                TopoDS_Vertex plast;
                TopExp::Vertices(path, pfirst, plast);
            }

            ps.SetLaw(
                shape_profile, // セクションプロファイル
                law,           // 掃引規則
                pfirst,        // 開始点
                withContact,   // セクションプロファイルを開始点に移動して掃引する
                withCorrection // セクションプロファイルをパスに応じて回転する
                );

            ps.Build();
            shape = ps.Shape();
        }
        else {
    		BRepOffsetAPI_MakePipe mp(path, shape_profile);
    		mp.Build();
    		shape = mp.Shape();
        }
		if (shape.IsNull()) {
			static const char m[] = "Failed to make a sweep model.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}
	catch (...) {
		static const char m[] = "Failed to make a sweep model.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief make wire by Edge, Wire, Compound object
 */
mrb_value wire(mrb_state* mrb, mrb_value self)
{
	mrb_value objs;
	int argc = mrb_get_args(mrb, "A", &objs);
	int osize = mrb_ary_len(mrb, objs);
	
	ShapeFix_Wire sfw;
	Handle(ShapeExtend_WireData) wd = new ShapeExtend_WireData;
	BRepBuilderAPI_MakeWire mw;
	TopoDS_Shape shape;
	Standard_Real tol = 0.01;
	ShapeFix_ShapeTolerance FTol;
	try {
		for (int i = 0; i < osize ; i++) {

			mrb_value id = mrb_ary_ref(mrb, objs, i);
			TopoDS_Shape s = ::getTopoDSShape(mrb_fixnum(id));

			if (s.IsNull())
                continue;

			TopAbs_ShapeEnum se = s.ShapeType();

			if (se != TopAbs_COMPOUND && se != TopAbs_EDGE && se != TopAbs_WIRE)
                continue;

			for (TopExp_Explorer exp(s, TopAbs_EDGE); exp.More(); exp.Next()) {
				if (!exp.Current().IsNull())
                    wd->Add(TopoDS::Edge(exp.Current()));
			}
		}
		sfw.Load(wd);
		sfw.Perform();
		for (int i = 1; i <= sfw.NbEdges(); i ++) {
			TopoDS_Edge e = sfw.WireData()->Edge(i);
			FTol.SetTolerance(e, tol, TopAbs_VERTEX);
			mw.Add(e);
		}
		shape = mw.Shape();
		if (shape.IsNull()) {
			delete(wd);
			static const char m[] = "Failed to make a wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}
    catch (...) {
		delete(wd);
		static const char m[] = "Failed to make a wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

mrb_value loft(mrb_state* mrb, mrb_value self)
{
	mrb_value objs;
	int argc = mrb_get_args(mrb, "A", &objs);
    int lsize = mrb_ary_len(mrb, objs);

    if (lsize < 2) {
        static const char m[] = "Number of objects must be over 2 lines.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    BRepOffsetAPI_ThruSections ts(/* isSolid = */ Standard_False, /* isRuled = */ Standard_True);

    for (int i=0; i<lsize; i++) {
		mrb_value line = mrb_ary_ref(mrb, objs, i);
        mrb_int target = mrb_fixnum(line);
    	TopoDS_Shape shape = ::getTopoDSShape(target);
    	if (shape.IsNull()) {
    		static const char m[] = "No such profile object.";
            return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    	}
        TopAbs_ShapeEnum type = shape.ShapeType();

        // ↓ TopExp_Explorer で WIRE を掘ってやったほうが親切
        //////////////////////////
        if (type == TopAbs_WIRE) {
            TopoDS_Wire w = TopoDS::Wire(shape);
            ts.AddWire(w);
        }
        else {
            // EdgeやCompoundなEdgeの場合
            // Wireを作る？
        }
        //////////////////////////
    }

    mrb_value result;
    TopoDS_Shape shape;
    try {
        ts.SetSmoothing(Standard_True);
        ts.Build();
		shape = ts.Shape();
#if USECLASS
        ::regist(shape, result);
#else
        result = mrb_fixnum_value(::set(shape, self));
#endif
    }
    catch (...) {
		static const char m[] = "Internal error.";
        result = mrb_exc_new(mrb, E_RUNTIME_ERROR, m, sizeof(m) - 1);
    }
    return result;
}

/**
* \brief 
*/
// bsplinesurf s   1 2 0 2 1 2   2 3 0 3 1 1 2 3   0 0 0 1  10 0 5 1   0 10 2 1  10 10 3 1   0 20 10 1  10 20 20 1   0 30 0 1  10 30 0 1
//                 u n u u u u   v n v v v v v v   x y z w  x  y z w   x y  z w  x  y  z w   x y  z  w  x  y  z  w   x y  z w  x  y  z w
//                 d k k m k m   d k k m k m k m   POLES ...
// bssurf 1,[[0,2],[1,2]],2,[[0,3],[1,1],[2,3]],[[[0,0,0,1],[10,0,5,1]],[[0,10,2,1],[10,10,3,1]],[[0,20,10,1],[10,20,20,1]],[[0,30,0,1],[10,30,0,1]]]
mrb_value bscurve(mrb_state* mrb, mrb_value self)
{
    // bsplinecurve name degree nbknots knot, umult pole, weight
    // bsplinecurve bc   2      3       0,3  1,1  2,3  10 0 7 1    7 0 7 1    3 0 8 1    0 0 7 1

    TColgp_Array1OfPnt poles(0, 3);
    poles.SetValue(0, gp_Pnt(100,  0,  0));
    poles.SetValue(1, gp_Pnt( 70,-10, 10));
    poles.SetValue(2, gp_Pnt( 30, 40, 10));
    poles.SetValue(3, gp_Pnt(  0,  0,  0));

    TColStd_Array1OfReal weights(0, 3);
    weights.SetValue(0, 1.0);
    weights.SetValue(1, 1.0);
    weights.SetValue(2, 1.2);
    weights.SetValue(3, 1.0);

    TColStd_Array1OfReal knots(0, 2);
    knots.SetValue(0, 0);
    knots.SetValue(1, 1);
    knots.SetValue(2, 2);

    TColStd_Array1OfInteger mults(0, 2);
    mults.SetValue(0, 3);
    mults.SetValue(1, 1);
    mults.SetValue(2, 3);

    Handle(Geom_BSplineCurve) hgeom_bscurve = new Geom_BSplineCurve(
        poles, weights, knots, mults, 2, Standard_False);

    TopoDS_Edge e = BRepBuilderAPI_MakeEdge(hgeom_bscurve);
    return mrb_fixnum_value(::set(e, self));
}

/**
 * \brief ポールとウェイトを指定してベジエ曲面を作成する
 */
mrb_value bzsurf(mrb_state* mrb, mrb_value self)
{
	mrb_value ptary, wtary;
	int argc = mrb_get_args(mrb, "A|A", &ptary, &wtary);

    int rlen = mrb_ary_len(mrb, ptary);
    int clen = mrb_ary_len(mrb, mrb_ary_ref(mrb, ptary, 0));

    TColgp_Array2OfPnt poles(0, rlen-1, 0, clen-1);

    for (int r=0; r<rlen; r++) {
        mrb_value ar = mrb_ary_ref(mrb, ptary, r);
        for (int c=0; c<clen; c++) {
            mrb_value p = mrb_ary_ref(mrb, ar, c);
            gp_Pnt pp = *::ar2pnt(mrb, p);
            poles.SetValue(r, c, pp);
        }
    }

    Handle(Geom_BezierSurface) s = NULL;

    if (argc == 2) {
        // ウェイトが指定された場合
        TColStd_Array2OfReal weights(0, rlen-1, 0, clen-1);

        for (int r=0; r<rlen; r++) {
            mrb_value ar = mrb_ary_ref(mrb, wtary, r);
            for (int c=0; c<clen; c++) {
                mrb_value val = mrb_ary_ref(mrb, ar, c);
                double value = mrb_float(val);
                weights.SetValue(r, c, (Standard_Real)value);
            }
        }
        s = new Geom_BezierSurface(poles, weights);
    }
    else {
        s = new Geom_BezierSurface(poles);
    }

    TopoDS_Face f = BRepBuilderAPI_MakeFace(s, 1.0e-7);

#if USECLASS
    mrb_value result;
    ::regist(f, result);
	return result;
#else
    return mrb_fixnum_value(::set(f, self));
#endif
}

/**
 * \brief Bスプライン曲面を作成する
 */
mrb_value bssurf(mrb_state* mrb, mrb_value self)
{
    // bsplinesurf s   1 2 0 2 1 2   2 3 0 3 1 1 2 3   0 0 0 1  10 0 5 1   0 10 2 1  10 10 3 1   0 20 10 1  10 20 20 1   0 30 0 1  10 30 0 1
    //                 u n u u u u   v n v v v v v v   x y z w  x  y z w   x y  z w  x  y  z w   x y  z  w  x  y  z  w   x y  z w  x  y  z w
    //                 d k k m k m   d k k m k m k m   POLES ...
    // bssurf 1,[[0,2],[1,2]],2,[[0,3],[1,1],[2,3]],[[[0,0,0,1],[10,0,5,1]],[[0,10,2,1],[10,10,3,1]],[[0,20,10,1],[10,20,20,1]],[[0,30,0,1],[10,30,0,1]]]

    // Poles
    // [[u1, u2], [u1, u2], [u1, u2], ... ]

    mrb_int _udeg, _vdeg;
    mrb_value _ar_ukm, _ar_vkm;
    mrb_value _pol;
	int argc = mrb_get_args(mrb, "iAiAA", &_udeg, &_ar_ukm, &_vdeg, &_ar_vkm, &_pol);

    Standard_Integer udeg = _udeg;
    Standard_Integer nbuknots = mrb_ary_len(mrb, _ar_ukm);
    Standard_Integer nbuknots_pure = 0;
    TColStd_Array1OfReal uknots(1, nbuknots);
    TColStd_Array1OfInteger umults(1, nbuknots);
    for (int i=1; i<=nbuknots; i++) {
        mrb_value item = mrb_ary_ref(mrb, _ar_ukm, i - 1);
        mrb_value knot = mrb_ary_ref(mrb, item, 0);
        mrb_value mult = mrb_ary_ref(mrb, item, 1);
        uknots(i) = mrb_fixnum(knot);
        umults(i) = mrb_fixnum(mult);
        nbuknots_pure += umults(i);
    }
    Standard_Integer nbupoles = nbuknots_pure - udeg - 1;

    Standard_Integer vdeg = _vdeg;
    Standard_Integer nbvknots = mrb_ary_len(mrb, _ar_vkm);
    Standard_Integer nbvknots_pure = 0;
    TColStd_Array1OfReal vknots(1, nbvknots);
    TColStd_Array1OfInteger vmults(1, nbvknots);
    for (int i=1; i<=nbvknots; i++) {
        mrb_value item = mrb_ary_ref(mrb, _ar_vkm, i - 1);
        mrb_value knot = mrb_ary_ref(mrb, item, 0);
        mrb_value mult = mrb_ary_ref(mrb, item, 1);
        vknots(i) = mrb_fixnum(knot);
        vmults(i) = mrb_fixnum(mult);
        nbvknots_pure += vmults(i);
    }
    Standard_Integer nbvpoles = nbvknots_pure - vdeg - 1;

    TColgp_Array2OfPnt   poles  (1, nbupoles, 1, nbvpoles);
    TColStd_Array2OfReal weights(1, nbupoles, 1, nbvpoles);

	for (int v=1; v <= nbvpoles; v++) {
        mrb_value vitem = mrb_ary_ref(mrb, _pol, v - 1);
    	for (int u=1; u <= nbupoles; u++) {
            mrb_value uitem = mrb_ary_ref(mrb, vitem, u - 1);

            double x = ar2double(mrb, uitem, 0);
            double y = ar2double(mrb, uitem, 1);
            double z = ar2double(mrb, uitem, 2);
            double w = ar2double(mrb, uitem, 3);

            poles.SetValue(u, v, gp_Pnt(x, y, z));
            weights.SetValue(u, v, w);
            // cout << x << "," << y << "," << z << "," << w << endl;
		}
        // std::cout << std::endl;
	}

    Handle(Geom_BSplineSurface) hg_bssurf = new Geom_BSplineSurface(poles, weights, uknots, vknots, umults, vmults, udeg, vdeg);
    TopoDS_Shell shape = BRepBuilderAPI_MakeShell(hg_bssurf);

#if 0
    Standard_Integer udeg = 1;
    Standard_Integer nbuknots = 2;
    Standard_Integer nbuknots_pure = 0;
    TColStd_Array1OfReal uknots(1, nbuknots);
    TColStd_Array1OfInteger umults(1, nbuknots);
    uknots(1) = 0; umults(1) = 2;
    uknots(2) = 1; umults(2) = 2;
    for (int i=1; i<=umults.Length(); i++) {
        nbuknots_pure += umults(i);
    }
    Standard_Integer nbupoles = nbuknots_pure - udeg - 1; // 4 - 1 - 1 = 2

    Standard_Integer vdeg = 2;
    Standard_Integer nbvknots = 3;
    Standard_Integer nbvknots_pure = 0;
    TColStd_Array1OfReal vknots(1, nbvknots);
    TColStd_Array1OfInteger vmults(1, nbvknots);
    vknots(1) = 0; vmults(1) = 3;
    vknots(2) = 1; vmults(2) = 1;
    vknots(3) = 2; vmults(3) = 3;
    for (int i=1; i<=vmults.Length(); i++) {
        nbvknots_pure += vmults(i);
    }
    Standard_Integer nbvpoles = nbvknots_pure - vdeg - 1; // 7 - 2 - 1 = 4

    TColgp_Array2OfPnt poles(1, nbupoles, 1, nbvpoles);
    TColStd_Array2OfReal weights(1, nbupoles, 1, nbvpoles);
    poles.SetValue(1, 1, gp_Pnt(0., 0., 0.));    weights.SetValue(1, 1, 1.);
    poles.SetValue(2, 1, gp_Pnt(10., 0., 5.));   weights.SetValue(2, 1, 1.);
    poles.SetValue(1, 2, gp_Pnt(0., 10., 2.));   weights.SetValue(1, 2, 1.);
    poles.SetValue(2, 2, gp_Pnt(10., 10., 3.));  weights.SetValue(2, 2, 1.);
    poles.SetValue(1, 3, gp_Pnt(0., 20., 10.));  weights.SetValue(1, 3, 1.);
    poles.SetValue(2, 3, gp_Pnt(10., 20., 20.)); weights.SetValue(2, 3, 1.);
    poles.SetValue(1, 4, gp_Pnt(0., 30., 0.));   weights.SetValue(1, 4, 1.);
    poles.SetValue(2, 4, gp_Pnt(10., 30., 0.));  weights.SetValue(2, 4, 1.);

    Handle(Geom_BSplineSurface) hg_bssurf = new Geom_BSplineSurface(poles, weights, uknots, vknots, umults, vmults, udeg, vdeg);
    TopoDS_Shell shape = BRepBuilderAPI_MakeShell(hg_bssurf);

#endif

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
	return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

/**
 * \brief オフセット曲面を作成する
 */
mrb_value offset(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	mrb_float offset;
	int argc = mrb_get_args(mrb, "if", &target, &offset);

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull() ) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	TopoDS_Compound	comp;
	BRep_Builder B;
	B.MakeCompound(comp);

    TopExp_Explorer exp(shape, TopAbs_FACE);

    for (; exp.More(); exp.Next()) {
        TopoDS_Face face = TopoDS::Face(exp.Current());
        Handle(Geom_Surface) gs = BRep_Tool::Surface(face);
        Handle(Geom_OffsetSurface) gos = new Geom_OffsetSurface(gs, (Standard_Real)offset);
        TopoDS_Face newface = BRepBuilderAPI_MakeFace(gos, 1.0e-7);        
        B.Add(comp, newface);
    }

#if USECLASS
    mrb_value result;
    ::regist(comp, result);
    return result;
#else
    return mrb_fixnum_value(::set(comp, self));
#endif
}

/**
 * \brief サーフェスから板厚を指定してソリッドを作成する
 */
mrb_value thick(mrb_state* mrb, mrb_value self)
{
	mrb_int target;
	mrb_float offset;
	int argc = mrb_get_args(mrb, "if", &target, &offset);

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull() ) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    // gp_Ax1 axis(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1));
    // TopoDS_Shape dish = BRepPrimAPI_MakeRevol(shape, axis).Shape();

    //TopTools_ListOfShape closing_faces;
    //TopExp_Explorer ex(dish, TopAbs_FACE);
    //closing_faces.Append(ex.Current());

    //BRepOffsetAPI_MakeThickSolid mts(dish, closing_faces, (Standard_Real)offset, 1.0);
    //TopoDS_Shape rshape = mts.Shape();
    //TopoDS_Shape rshape = dish;

     //TopoDS_Shape S1 = BRepPrimAPI_MakeBox(100,100,100);
     //TopTools_ListOfShape aList;
     //TopExp_Explorer Ex(S1,TopAbs_FACE);
     //for(int i=0;i<5;i++)
     //{
     //     TopoDS_Shape aFace = Ex.Current();
     //     Ex.Next();
     //     aList.Append(aFace);
     //}
     //     
     //TopoDS_Shape aThickSolid = BRepOffsetAPI_MakeThickSolid(S1,aList,10,0.01);
     //return mrb_fixnum_value(::set(aThickSolid, self));

    TopoDS_Shape rshape = BRepPrimAPI_MakePrism(shape, gp_Vec(0, 0, 5));

    return mrb_fixnum_value(::set(rshape, self));
}

/**
 * \brief Cylindrical projection of wire on shape
 */
mrb_value projw(mrb_state* mrb, mrb_value self)
{
	mrb_int w, f;
    mrb_value v;
	int argc = mrb_get_args(mrb, "iiA", &w, &f, &v);

	TopoDS_Shape wire = ::getTopoDSShape(w);
	if (wire.IsNull() ) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape face = ::getTopoDSShape(f);
	if (face.IsNull() ) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
    gp_Vec* vec = ::ar2vec(mrb, v);

    TopoDS_Shape shape;
    BRepProj_Projection bpp(wire, face, *vec);

    shape = bpp.Shape();

#if USECLASS
    mrb_value result;
    ::regist(shape, result);
    return result;
#else
    return mrb_fixnum_value(::set(shape, self));
#endif
}

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

    Handle(AIS_Shape) hashape = ::getAISShape(target);
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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    int type = (int)shape.ShapeType();

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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    Bnd_Box box;
    BRepBndLib::Add(shape, box);
    Standard_Real xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);

#if 0
    mrb_value rmin = ::pnt2ar(mrb, gp_Pnt(xmin, ymin, zmin));
    mrb_value rmax = ::pnt2ar(mrb, gp_Pnt(xmax, ymax, zmax));
#else
    RClass* prVec = mrb_class_get(mrb, "Vec");

    mrb_value arg[3];

    arg[0] = mrb_float_value(mrb, xmin);
    arg[1] = mrb_float_value(mrb, ymin);
    arg[2] = mrb_float_value(mrb, zmin);
    mrb_value rmin = mrb_class_new_instance(mrb, 3, arg, prVec);

    arg[0] = mrb_float_value(mrb, xmax);
    arg[1] = mrb_float_value(mrb, ymax);
    arg[2] = mrb_float_value(mrb, zmax);
    mrb_value rmax = mrb_class_new_instance(mrb, 3, arg, prVec);
#endif

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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }
    gp_Pnt p = *::ar2pnt(mrb, xyz);

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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

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

    TopoDS_Shape shape = ::getTopoDSShape(target);
    if (shape.IsNull()) {
        static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

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

/**
 * \brief Make coupound from multiple objects.
 */
mrb_value compound(mrb_state* mrb, mrb_value self)
{
	mrb_value ar;
	int argc = mrb_get_args(mrb, "A", &ar);

	TopoDS_Compound	comp;
	BRep_Builder B;
	B.MakeCompound(comp);

	int psize = mrb_ary_len(mrb, ar);
	for (int i=0; i<psize; i++) {
		mrb_value item = mrb_ary_ref(mrb, ar, i);
		if (!mrb_fixnum_p(item)) {
			static const char m[] = "Incorrect argument specified.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		mrb_int target = mrb_fixnum(item);
		TopoDS_Shape shape = ::getTopoDSShape(target);
		if (shape.IsNull()) {
			static const char m[] = "No such object name of specified at first.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		B.Add(comp, shape);
        ::unset(target);
	}
	return mrb_fixnum_value(::set(comp, self));
}

/**
 * \brief Sew objects to shell.
 */
mrb_value sew(mrb_state* mrb, mrb_value self)
{
	mrb_value ar;
	mrb_float tol;
	int argc = mrb_get_args(mrb, "A|f", &ar, &tol);

	BRepBuilderAPI_Sewing sewer;
	sewer.Init();
	if (argc == 2 && tol >= 0)
		sewer.SetTolerance(tol);

	int psize = mrb_ary_len(mrb, ar);
	for (int i=0; i<psize; i++) {
		mrb_value item = mrb_ary_ref(mrb, ar, i);
		if (!mrb_fixnum_p(item)) {
			static const char m[] = "Incorrect argument specified.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		mrb_int target = mrb_fixnum(item);
		TopoDS_Shape shape = ::getTopoDSShape(target);
		if (shape.IsNull()) {
#if 0
			static const char m[] = "No such object name of specified at first.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
#else
            continue;
#endif
		}
        TopExp_Explorer ex(shape, TopAbs_FACE);
        for (; ex.More(); ex.Next()) {
            sewer.Add(ex.Current());
        }
	}

	TopoDS_Shape result;
	try {
		sewer.Perform();
		result = sewer.SewedShape();
	}
	catch (...) {
		static const char m[] = "Failed to sew objects.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return mrb_fixnum_value(::set(result, self));
}

/**
 * \brief Explode object to child elements.
 */
mrb_value explode(mrb_state* mrb, mrb_value self)
{
	mrb_int type;
	mrb_int target;
	int argc = mrb_get_args(mrb, "ii", &type, &target);

	if (type < 0 || type > (int)TopAbs_VERTEX) {
		static const char m[] = "Incorrect type specified.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopAbs_ShapeEnum shapetype = (TopAbs_ShapeEnum)type;

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	mrb_value ar = mrb_ary_new(mrb);
    TopExp_Explorer ex(shape, shapetype);

    for (; ex.More(); ex.Next()) {
        const TopoDS_Shape& Sx = ex.Current();
		mrb_value hc = mrb_fixnum_value(::set(Sx, self));
		mrb_ary_push(mrb, ar, hc);
    }

    ::unset(target);

	return ar;
}

/**
 * \brief Erase object
 */
mrb_value erase(mrb_state* mrb, mrb_value self)
{
    mrb_value obj;
    int argc = mrb_get_args(mrb, "o", &obj);
    if (mrb_fixnum_p(obj)) {
    	::unset(mrb_fixnum(obj));
    }
    else if (mrb_array_p(obj)) {
        for (int i=0; i<mrb_ary_len(mrb, obj); i++) {
            mrb_value item = mrb_ary_ref(mrb, obj, i);
            mrb_int hc = mrb_fixnum(item);
        	::unset(hc);
        }
    }
    else {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }
    cur->aiscxt->UpdateCurrentViewer();
	return mrb_nil_value();
}

/**
 * \brief copy object
 */
mrb_value copy(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	TopoDS_Shape shape = ::getTopoDSShape(src);
	if (shape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(shape);

    if (!Builder.IsDone()) {
		static const char m[] = "Internal error.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }
    TopoDS_Shape rshape = Builder.Shape();
    if (rshape.IsNull()) {
		static const char m[] = "Internal error.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    int shape_code = shape.HashCode(INT_MAX);
    int rshape_code = rshape.HashCode(INT_MAX);

	return mrb_fixnum_value(::set(rshape, self));
}

/**
 * \brief close wire / edge object
 */
mrb_value close(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	TopoDS_Shape shape = ::getTopoDSShape(src);
	if (shape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopAbs_ShapeEnum se = shape.ShapeType();
	if ( se != TopAbs_WIRE && se != TopAbs_EDGE && se != TopAbs_COMPOUND ) {
		static const char m[] = "Failed to make a closed wire.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape rshape;
	TopoDS_Shape sThis = shape;
	try {
		BRepBuilderAPI_MakeWire mw;
		// find first point
		BRepAdaptor_Curve ac;
		gp_Pnt sp, ep;
		TopExp_Explorer exp( sThis, TopAbs_EDGE );
		double tol = 0.01;
		TopoDS_Edge e = TopoDS::Edge( exp.Current() );
		ac.Initialize( e );
		sp = ac.Value( ac.FirstParameter() );
		ep = ac.Value( ac.LastParameter() );
		mw.Add( e );
		if ( e.Orientation() == TopAbs_REVERSED ) sp = ep;
		//find last point
		int count = 0;
		for ( ; exp.More(); exp.Next() )
		{
			if ( exp.Current().IsNull() ) continue;
			e = TopoDS::Edge( exp.Current() );
			mw.Add( e );
			ac.Initialize( e );
			if (e.Orientation() == TopAbs_FORWARD )
				ep = ac.Value( ac.LastParameter() );
			else if (e.Orientation() == TopAbs_REVERSED )
				ep = ac.Value( ac.FirstParameter() );
		}
		if ( !sp.IsEqual( ep, tol ) ) {
			e = BRepBuilderAPI_MakeEdge( ep, sp );
			mw.Add(e);
		}
		ShapeFix_Wire sfw;
		sfw.Load( mw.Wire() );
		sfw.FixClosed();
		rshape = sfw.Wire();
		if ( rshape.IsNull() )
		{
			static const char m[] = "Failed to make a closed wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a closed wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(rshape, self));
#if 0

        double qTolerance = 0.1e-3;

	Handle( ShapeExtend_WireData ) wd1 = new ShapeExtend_WireData(); //バッファ1
	gp_Pnt wsp,wep; //全体の終始点
	gp_Pnt sp,ep; //点
	gp_Pnt sp2,ep2; //点
	BRepAdaptor_Curve c1, c2; //カーブ
	int is = 0; //最初のEdgeのIndex
	int ie = 0;
	int num = 0; //エッジ総数
	int all = 0; //中線の数
	int hit = 0; //片方が繋がっていないEdgeの数
	bool fs, fe; //繋がっているかのフラグ

	//まずは全体の終始点を取得
	for ( TopExp_Explorer exp(sThis, TopAbs_EDGE ); exp.More(); exp.Next() )
	{
		TopoDS_Edge e = TopoDS::Edge(exp.Current());
		fs = false;
		fe = false;
		c1.Initialize( e );
		sp = c1.Value(c1.FirstParameter());
		ep = c1.Value(c1.LastParameter());
		for ( TopExp_Explorer exp2(sThis, TopAbs_EDGE ); exp2.More(); exp2.Next() )
		{
			//自身以外を検査
			if ( !e.IsEqual(exp2.Current()) )
			{
				const TopoDS_Edge e2 = TopoDS::Edge(exp2.Current());
				c2.Initialize( e2 );
				sp2 = c2.Value(c2.FirstParameter());
				ep2 = c2.Value(c2.LastParameter());
				if ( sp.IsEqual( sp2, qTolerance ) || sp.IsEqual( ep2, qTolerance ) ) fs = true;
				if ( ep.IsEqual( sp2, qTolerance ) || ep.IsEqual( ep2, qTolerance ) ) fe = true;
				if ( fs && fe ) { all++; break; }
			}
		}
		
		if (hit < 2 && ((!fs && fe) || (fs && !fe)) )
		{// hitカウンタが2未満なら設定
			if (!hit) {
				if (!fs && fe) wsp = sp; else wsp = ep; 
				is = num;
				hit++;
			} else {
				if (!fs && fe) wep = sp; else wep = ep; 
				ie = num;
				hit++;
			}
		}

		// 1本以外で独立したedgeの場合error
		if (num && !fs && !fe)
		{
            printf("");;
		}
		num++;
		e.Orientation( TopAbs_FORWARD ); //向きを統一しておく
		wd1->Add(e);
	}

	//総数が一本だけの場合はそのままセット
	if( num == 1 )
	{
        printf("");;
	}
	
	//修正点がない場合は閉区画として適当な位置から探す
	if( hit < 1 && num == all ) { wsp = sp; is = num; }

	//最初のEdgeを取得
	TopoDS_Edge se = wd1->Edge(is + 1); //!! OCCの要素は1からカウント !!
	num = wd1->NbEdges() - 1;
	BRepAdaptor_Curve sc( se );
	sp = sc.Value(sc.FirstParameter());
	ep = sc.Value(sc.LastParameter());
	//FirstParameterと始点が反転してたら逆にする
	if ( !wsp.IsEqual( sp, qTolerance ) && wsp.IsEqual( ep, qTolerance ) )
	{
		if (se.Orientation() == TopAbs_FORWARD )
		{
			se.Orientation( TopAbs_REVERSED );
		} else {
			se.Orientation( TopAbs_FORWARD );
		}
		gp_Pnt bak = sp;
		sp = ep;
		ep = bak;
	}
	Handle( ShapeExtend_WireData ) wd2 = new ShapeExtend_WireData(); //バッファ2
	wd2->Add( se, 1 );
	bool r; //エッジの反転フラグ
	bool h;
	hit = 0;
	//連続性のある順番で格納していく
	while ( num > 0 )
	{
		for ( int i=1; i <= wd1->NbEdges(); i++ )
		{
			r = false;
			h = false;
			TopoDS_Edge e = wd1->Edge( i );
			if ( !wd2->Index(e) )
			{ //すでに格納したエッジ以外を検査
				c1.Initialize( e );
				sp2 = c1.Value(c1.FirstParameter());
				ep2 = c1.Value(c1.LastParameter());
				if ( ep.IsEqual( sp2, qTolerance ) ) { h = true; }
				else if ( ep.IsEqual( ep2, qTolerance ) )	{ h = true; r = true; }

				if (h) //見つかった
				{
					if (r)
					{ //反転処理
						e.Orientation( TopAbs_REVERSED );
						gp_Pnt bak = sp2;
						sp2 = ep2;
						ep2 = bak;
					} 
					cout << sp.X() << "\t" << sp.Y() << "\t" << sp.Z() << endl;
					cout << ep.X() << "\t" << ep.Y() << "\t" << ep.Z() << "\t" << e.Orientation() << "\t" << r << endl;

					wd2->Add( e ); //バッファに追加
					sp = sp2;	//次に検査する値にセット
					ep = ep2;
					num--; //ひとつ減らす
					break; //for文を抜ける
				}
			}
		}
	hit++;
	if ( hit > 10 ) break; //無限ループ解除
	}
	shape = wd2->Wire();
	if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a closed wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a closed wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
#endif
}

/**
 * \brief wire to points
 */
mrb_value wire2pts(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	mrb_float deflect;
	int argc = mrb_get_args(mrb, "i|f", &src, &deflect);

	TopoDS_Shape shape = ::getTopoDSShape(src);
	if (shape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	if (argc != 2)
		deflect = 1.0e-1;

	mrb_value result = mrb_ary_new(mrb);
	double first_param, last_param;

	TopExp_Explorer	exp(shape, TopAbs_EDGE);
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
 * \brief wire to face
 */
mrb_value wire2face(mrb_state* mrb, mrb_value self)
{
	//!!Curveを含んだWireには未対応!!
	mrb_int src;
    mrb_bool is_pln;
	int argc = mrb_get_args(mrb, "i|b", &src, &is_pln);

    Standard_Boolean is_plane;
    if (argc == 2) {
        is_plane = is_pln ? Standard_True : Standard_False;
    }
    else {
        is_plane = Standard_False;
    }

	TopoDS_Shape shape = ::getTopoDSShape(src);
	if (shape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if (shape.ShapeType() != TopAbs_WIRE) {
		static const char m[] = "Specified shape is not wire. Failed to make a plane.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	TopoDS_Shape rshape;
	try {
		TopoDS_Wire w = TopoDS::Wire(shape);
		BRepBuilderAPI_MakeFace mf(w, is_plane);
		mf.Build();
		if (  !mf.IsDone() ) {
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		rshape = mf.Shape();
		//TopAbs_ShapeEnum se = shape.ShapeType();
		if ( rshape.IsNull() )
		{
			static const char m[] = "Failed to make a plane.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a plane.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(rshape, self));
}

/**
 * \brief Make a solid by shell.
 */
mrb_value shell2solid(mrb_state* mrb, mrb_value self)
{
    mrb_int obj;
	int argc = mrb_get_args(mrb, "i", &obj);

	TopoDS_Shape shape = ::getTopoDSShape(obj);
	if (shape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    mrb_value result;

    TopoDS_Solid solid;
    BRepBuilderAPI_MakeSolid solid_maker;
    
	for (TopExp_Explorer ex(shape, TopAbs_SHELL); ex.More(); ex.Next()) {
		TopoDS_Shell shell = TopoDS::Shell(ex.Current());
        solid_maker.Add(shell);
	}
	if (solid_maker.IsDone()) {
		solid = solid_maker.Solid();
        result = mrb_fixnum_value(::set(solid, self));
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

	Handle(AIS_Shape) hashape = ::getAISShape(obj);
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
 * \brief get across area of s1 by s2
 */
mrb_value common(mrb_state* mrb, mrb_value self)
{
	mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	TopoDS_Shape S1 = ::getTopoDSShape(s1);
	if (S1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape S2 = ::getTopoDSShape(s2);
	if (S2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(S1, S2);
	bo.SetOperation(BOPAlgo_COMMON);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape, self));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief cut object (s1 by s2)
 */
mrb_value cut(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	TopoDS_Shape S1 = ::getTopoDSShape(s1);
	if (S1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape S2 = ::getTopoDSShape(s2);
	if (S2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(S1, S2);
	bo.SetOperation(BOPAlgo_CUT);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape, self));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief add object
 */
mrb_value fuse(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	TopoDS_Shape S1 = ::getTopoDSShape(s1);
	if (S1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape S2 = ::getTopoDSShape(s2);
	if (S2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(S1, S2);
	bo.SetOperation(BOPAlgo_FUSE);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		result = mrb_fixnum_value(::set(shape, self));
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

/**
 * \brief get volume of solid object
 */
mrb_value volume(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(shape, gprops);
	Standard_Real vol = gprops.Mass();

	return mrb_float_value(mrb, (mrb_float)vol);
}

/**
 * \brief get point of center of gravity
 */
mrb_value cog(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(shape, gprops);
	gp_Pnt cog = gprops.CentreOfMass();

	return ::pnt2ar(mrb, cog);
}

/**
 * \brief Get square measure of a face
 */
mrb_value area(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	TopoDS_Shape shape = ::getTopoDSShape(target);
	if (shape.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    GProp_GProps System;
    BRepGProp::SurfaceProperties(shape, System);
    Standard_Real Area = System.Mass();

    return mrb_float_value(mrb, Area);
}

/**
 * \brief 2つのオブジェクトの交線を求め、作成する
 */
mrb_value intersect(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	TopoDS_Shape S1 = ::getTopoDSShape(s1);
	if (S1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape S2 = ::getTopoDSShape(s2);
	if (S2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Section	sect(S1, S2, Standard_False );
	sect.ComputePCurveOn1(Standard_True);
	sect.Approximation(Standard_True);
	sect.Build();

	if (!sect.IsDone()) {
		static const char m[] = "Failed to intersection.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	TopoDS_Shape shape = sect.Shape();

	return mrb_fixnum_value(::set(shape, self));
}

/**
 * \brief 分割する
 */
mrb_value split(mrb_state* mrb, mrb_value self)
{
    mrb_int s1, s2;
	int argc = mrb_get_args(mrb, "ii", &s1, &s2);

	TopoDS_Shape S1 = ::getTopoDSShape(s1);
	if (S1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape S2 = ::getTopoDSShape(s2);
	if (S2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    // Intersection
    BRepAlgoAPI_Section asect(S1, S2, FALSE);
    asect.ComputePCurveOn1(TRUE);
    asect.Approximation(TRUE);
    asect.Build();
    if(!asect.IsDone())
        return mrb_nil_value();
    TopoDS_Shape curve = asect.Shape();

    BRepFeat_SplitShape splitter(S1);
    TopExp_Explorer exp(curve, TopAbs_EDGE);

    for (; exp.More(); exp.Next()) {
        TopoDS_Shape e = exp.Current();     
        TopoDS_Shape f;
        if (asect.HasAncestorFaceOn1(e, f)) {
             TopoDS_Edge ee = TopoDS::Edge(e);
             TopoDS_Face ff = TopoDS::Face(f);
             splitter.Add(ee, ff);
        }
    }
    try {
        splitter.Build();
    	if (!splitter.IsDone()) {
    		static const char m[] = "Failed to intersection.";
            return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    	}
    }
    catch (...) {
		static const char m[] = "Failed to intersection.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

	TopoDS_Shape shape = splitter.Shape();
	return mrb_fixnum_value(::set(shape, self));
}

/**
 * \brief サーフェスとカーブの交点を得る
 *
 * \note サーフェスの外形を考慮せず無限曲面の交点を得る
 */
/*
 * GeomAPI_IntCS
 * IntCurvesFace_ShapeIntersector
 * IntCurvesFace_Intersector
 */
mrb_value intcs(mrb_state* mrb, mrb_value self)
{
    mrb_int c, s;
    mrb_bool with_normal = FALSE;
	int argc = mrb_get_args(mrb, "ii|b", &c, &s, &with_normal);

	Handle(AIS_Shape) hacurve = ::getAISShape(c);
	if (hacurve.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) hasurf = ::getAISShape(s);
	if (hasurf.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    mrb_value result = mrb_ary_new(mrb);

    Standard_Real first, last;
    TopExp_Explorer exc, exs;

    for (exc.Init(hacurve->Shape(), TopAbs_EDGE); exc.More(); exc.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exc.Current());
        Handle(Geom_Curve) gcurve = BRep_Tool::Curve(edge, first, last);

        for (exs.Init(hasurf->Shape(), TopAbs_FACE); exs.More(); exs.Next()) {
            TopoDS_Face face = TopoDS::Face(exs.Current());
            Handle(Geom_Surface) gsurf  = BRep_Tool::Surface(face);
            GeomAPI_IntCS isc = GeomAPI_IntCS(gcurve, gsurf);
            if (!isc.IsDone())
                continue;
            for (int i = 1; i <= isc.NbPoints() ; i++ ) {
               // Intersect point
               gp_Pnt p = isc.Point(i);
               mrb_value item = pnt2ar(mrb, p);
        	   mrb_ary_push(mrb, result, item);

               // Normal vector on a point
               if (with_normal) {
                   Quantity_Parameter u, v, w;
                   isc.Parameters(i, u, v, w);
                   BRepAdaptor_Surface aSurface(face);
                   gp_Vec ut, vt;
                   gp_Pnt pt;
                   aSurface.D1(u, v, pt, ut, vt);
                   gp_Vec normal = ut.Crossed(vt);
                   normal.Normalize();
                   gp_Pnt np(normal.X(), normal.Y(), normal.Z());
                   mrb_value a = pnt2ar(mrb, np);
            	   mrb_ary_push(mrb, result, a);
               }
            }
        }
    }

    return result;
}

/**
 * \brief フェイスとエッジの交点を得る
 */
mrb_value intfe(mrb_state* mrb, mrb_value self)
{
    mrb_int c, s;
    mrb_bool with_normal = FALSE;
	int argc = mrb_get_args(mrb, "ii|b", &s, &c, &with_normal);

	TopoDS_Shape curve = ::getTopoDSShape(c);
	if (curve.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape surf = ::getTopoDSShape(s);
	if (surf.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    mrb_value result = mrb_ary_new(mrb);

    TopExp_Explorer exc, exs;

    for (exc.Init(curve, TopAbs_EDGE); exc.More(); exc.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exc.Current());

        for (exs.Init(surf, TopAbs_FACE); exs.More(); exs.Next()) {
            TopoDS_Face face = TopoDS::Face(exs.Current());

            TopOpeBRep_FaceEdgeIntersector feint;
            feint.Perform(face, edge);

            for (feint.InitPoint(); feint.MorePoint(); feint.NextPoint()) {
                gp_Pnt p = feint.Value();

                mrb_value item = pnt2ar(mrb, p);
        	    mrb_ary_push(mrb, result, item);
            }
        }
    }

    return result;
}

/**
 * \brief Check point location at In/Out side of a object
 */
mrb_value isin(mrb_state* mrb, mrb_value self)
{
    mrb_value point;
    mrb_int target;
	int argc = mrb_get_args(mrb, "Ai", &point, &target);

	Handle(AIS_Shape) hashape = ::getAISShape((int)target);
	if (hashape.IsNull()) {
		static const char m[] = "No such named object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    TopoDS_Solid solid = TopoDS::Solid(hashape->Shape());
    if (solid.IsNull()) {
		static const char m[] = "Specified object is not SOLID.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    gp_Pnt p = *::ar2pnt(mrb, point);

    mrb_value result;

    BRepClass3d_SolidClassifier sc;
    sc.Load(solid);
    sc.Perform(p, 1.0);

    switch (sc.State()) {
    case TopAbs_IN:
        result = mrb_fixnum_value(1);
        break;
    case TopAbs_ON:
        result = mrb_fixnum_value(-1);
        break;
    case TopAbs_OUT:
        result = mrb_fixnum_value(0);
        break;
    }

    return result;
}

/**
 * \brief Save object to BRep file
 */
mrb_value savebrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	mrb_int target; 
	int argc = mrb_get_args(mrb, "Si", &path, &target);

	mrb_value result;

	TopoDS_Shape shape = ::getTopoDSShape((int)target);

	if (shape.IsNull()) {
		static const char m[] = "No such named object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	else {
		Standard_Boolean res = BRepTools::Write(shape, (Standard_CString)RSTRING_PTR(path));

		if (res) {
			result = mrb_nil_value();
		}
		else {
			static const char m[] = "Failed to save BRep file.";
	        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}

	return result;
}

/**
 * \brief Load object from BRep file
 */
mrb_value loadbrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	int argc = mrb_get_args(mrb, "S", &path);

	TopoDS_Shape shape;
    BRep_Builder aBuilder;
    Standard_Boolean res = BRepTools::Read(shape, (Standard_CString)RSTRING_PTR(path), aBuilder);

	mrb_value result;

	if (res) {
#if USECLASS
        ::regist(shape, result, true);
#else
        result = mrb_fixnum_value(::set(shape, self));
#endif
	}
	else {
		static const char m[] = "Failed to load BRep file.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief Save object to IGES file
 */
mrb_value saveiges(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
    mrb_value path;
	int argc = mrb_get_args(mrb, "iS", &target, &path);

	TopoDS_Shape shape = ::getTopoDSShape((int)target);
	if (shape.IsNull()) {
		static const char m[] = "No such named object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	IGESControl_Controller::Init();
	IGESControl_Writer writer(Interface_Static::CVal("XSTEP.iges.unit"),
                               Interface_Static::IVal("XSTEP.iges.writebrep.mode"));
 
	writer.AddShape(shape);
	writer.ComputeModel();

    if (writer.Write((Standard_CString)RSTRING_PTR(path)) == Standard_False) {
		static const char m[] = "Save error.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }

    return mrb_nil_value();
}

/**
 * \brief Load object from IGES file
 */
mrb_value loadiges(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	int argc = mrb_get_args(mrb, "S", &path);

    IGESControl_Reader iges_reader;
    int stat = iges_reader.ReadFile((Standard_CString)RSTRING_PTR(path));
	mrb_value result;

    if (stat == IFSelect_RetDone) {
	    iges_reader.TransferRoots();
	    TopoDS_Shape shape = iges_reader.OneShape();
#if USECLASS
        ::regist(shape, result, true);
#else
        result = mrb_fixnum_value(::set(shape, self));
#endif
	}
	else {
		static const char m[] = "Failed to load IGES file.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
    return result;
}

/**
 * \brief Save object to STEP file
 */
mrb_value savestep(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

/**
 * \brief Load object from STEP file
 */
mrb_value loadstep(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

/**
 * \brief Load object from STL file
 */
mrb_value loadstl(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	int argc = mrb_get_args(mrb, "S", &path);

    TopoDS_Shape shape;
    StlAPI_Reader reader;
    reader.Read(shape, (Standard_CString)RSTRING_PTR(path));

    mrb_value result;
    if (shape.IsNull()) {
	 	static const char m[] = "Failed to load STL file.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
    }
    else {
#if USECLASS
        ::regist(shape, result, true);
#else
        result = mrb_fixnum_value(::set(shape, self));
#endif
    }

    return result;
}

/**
 * \brief Save object to STL file
 */
mrb_value savestl(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
    mrb_value path;
	int argc = mrb_get_args(mrb, "iS", &target, &path);

	Handle(AIS_Shape) hashape = ::getAISShape((int)target);
	if (hashape.IsNull()) {
		static const char m[] = "No such index of shape.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    StlAPI_Writer writer;
    writer.Write(hashape->Shape(), (Standard_CString)RSTRING_PTR(path));

    return mrb_nil_value();
}

/**
 * \brief Save object to VRML file
 */
mrb_value savevrml(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
    mrb_value path;
	int argc = mrb_get_args(mrb, "iS", &target, &path);

	Handle(AIS_Shape) hashape = ::getAISShape((int)target);
	if (hashape.IsNull()) {
		static const char m[] = "No such index of shape.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

    VrmlAPI_Writer writer;
    writer.Write(hashape->Shape(), (Standard_CString)RSTRING_PTR(path));

    return mrb_nil_value();
}

/**
 * \brief version information
 */
mrb_value version(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

mrb_value all(mrb_state* mrb, mrb_value self)
{
    mrb_value result = mrb_ary_new(mrb);

    std::map<int, TopoDS_Shape>::iterator it = cur->shapeman.begin();
    for (; it != cur->shapeman.end(); it++) {
        int id = (int)(it->first);
        mrb_ary_push(mrb, result, mrb_fixnum_value(id));
    }
    if (mrb_ary_len(mrb, result) == 0)
        return mrb_nil_value();
    else
        return result;
}

mrb_value debug2(mrb_state* mrb, mrb_value self)
{
    return mrb_fixnum_value(123);
}

/**
 * \brief debug command
 */
#include <Prs3d_Root.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_AspectText3d.hxx>
mrb_value debug(mrb_state* mrb, mrb_value self)
{
    return mrb_nil_value();

////    TColgp_Array2OfPnt poles(0, 3, 0, 3);
 ///    poles.SetValue(0, 0, gp_Pnt( 0,  0, 20));
 ///    poles.SetValue(0, 1, gp_Pnt( 0, 10, 20));
 ///    poles.SetValue(0, 2, gp_Pnt( 0, 20, 20));
 ///    poles.SetValue(0, 3, gp_Pnt( 0, 30, 20));
 ///    poles.SetValue(1, 0, gp_Pnt(10,  0, 10));
 ///    poles.SetValue(1, 1, gp_Pnt(10, 10, 10));
 ///    poles.SetValue(1, 2, gp_Pnt(10, 20,  5));
 ///    poles.SetValue(1, 3, gp_Pnt(10, 30,  0));
 ///    poles.SetValue(2, 0, gp_Pnt(20,  0,  0));
 ///    poles.SetValue(2, 1, gp_Pnt(20, 10,  5));
 ///    poles.SetValue(2, 2, gp_Pnt(20, 20, 10));
 ///    poles.SetValue(2, 3, gp_Pnt(20, 30, 10));
 ///    poles.SetValue(3, 0, gp_Pnt(30,  0, 20));
 ///    poles.SetValue(3, 1, gp_Pnt(30, 10, 20));
 ///    poles.SetValue(3, 2, gp_Pnt(30, 20, 20));
 ///    poles.SetValue(3, 3, gp_Pnt(30, 30, 20));
 ///
 ///    Handle(Geom_BezierSurface) s = NULL;
 ///    //if (argc == 2) {
 ///    //    // ウェイトが指定された場合
 ///    //    TColStd_Array2OfReal weights(0, rlen-1, 0, clen-1);
 ///    //    for (int r=0; r<rlen; r++) {
 ///    //        mrb_value ar = mrb_ary_ref(mrb, wtary, r);
 ///    //        for (int c=0; c<clen; c++) {
 ///    //            mrb_value val = mrb_ary_ref(mrb, ar, c);
 ///    //            double value = mrb_float(val);
 ///    //            weights.SetValue(r, c, (Standard_Real)value);
 ///    //        }
 ///    //    }
 ///    //    s = new Geom_BezierSurface(poles, weights);
 ///    //}
 ///    //else {
 ///        s = new Geom_BezierSurface(poles);
 ///    //}
 ///    TopoDS_Face f = BRepBuilderAPI_MakeFace(s, 1.0e-7);
 ///    return mrb_fixnum_value(::set(f, self));

    // BRepBuilderAPI_MakePolygon mp;
    // mp.Add(gp_Pnt(0, 0, 0));
    // mp.Add(gp_Pnt(10, 0, 0));
    // mp.Add(gp_Pnt(10, 5, 0));
    // mp.Add(gp_Pnt(20, 5, 0));
    // mp.Add(gp_Pnt(20, 15, 0));
    // mp.Add(gp_Pnt(15, 12, 0));
    // mp.Add(gp_Pnt(5, 12, 0));
    // mp.Add(gp_Pnt(3, 10, 0));
    // mp.Add(gp_Pnt(0, 0, 0));

    // mp.Build();

    // if (mp.IsDone()) {
    //     TopoDS_Wire w = mp.Wire();
	// 	BRepBuilderAPI_MakeFace mf(w, Standard_True);
	// 	mf.Build();
	// 	if (mf.IsDone()) {
    //         TopoDS_Face f = mf.Face();
    //         return mrb_fixnum_value(::set(f, self));
	// 	}
    // }
    //return mrb_nil_value();
// #if 0
//     Handle(Prs3d_Presentation) aPrs;
//     // get the group
//     Handle (Graphic3d_Group) aGroup = Prs3d_Root::CurrentGroup (aPrs);
//     // change the text aspect
//     Handle(Graphic3d_AspectText3d) aTextAspect = new Graphic3d_AspectText3d ();
//     aTextAspect->SetTextZoomable (Standard_True);
//     aTextAspect->SetTextAngle (45.0);
//     aGroup->SetPrimitivesAspect (aTextAspect);
//     
//     // add a text primitive to the structure
//     Graphic3d_Vertex aPoint (1, 1, 1);
//     aGroup->Text (Standard_CString ("Text"), aPoint, 16.0);
// 
//     return mrb_nil_value();
// #endif
//     mrb_int target;
// 	int argc = mrb_get_args(mrb, "i", &target);
// 
// 	Handle(AIS_Shape) hashape = ::getAISShape((int)target);
// 
//     {
//         //cur->view->SetZClippingType(V3d_TypeOfZclipping::V3d_OFF);
//         // NCollection_Vec4<Standard_Real> eq(0., 0., 1., 1.);
// 
//         gp_Pln pln(gp_Pnt(0, 0, 0), gp_Dir(0, 1, 0));
//         Handle(Graphic3d_ClipPlane) thePlane = new Graphic3d_ClipPlane(pln);
// 
//         thePlane->SetCappingHatch(Aspect_HS_DIAGONAL_45);
//         thePlane->SetCappingHatchOn();
//         thePlane->SetCapping(Standard_True);
//         thePlane->SetOn(Standard_True);
// 
//         hashape->AddClipPlane(thePlane);
//         hashape->Redisplay();
// 
//         //cur->aiscxt->Display(hashape);
// 
//         //cur->view->AddClipPlane(thePlane);
//         //cur->view->Redraw();
//         //cur->aiscxt->Update(hashape);
//         //cur->aiscxt->UpdateCurrent();
//         //cur->aiscxt->UpdateCurrentViewer();
//     }
//     return mrb_nil_value();
// 
// #if 0
//     //RClass* my_class = mrb_define_class(mrb, "Shape", mrb->object_class);
//     //mrb_define_method(mrb, my_class, "type", debug2, ARGS_NONE());
//     //RClass* a_class = mrb_class_get(myMirb->mrb, "MyClass");
//     // mrb_value args[2];
//     // args[0] = mrb_fixnum_value(LED_ORANGE);     //pin Number
//     // args[1] = mrb_fixnum_value(1000);   //interval
// 
//     //return mrb_funcall(mrb, a_obj, "type", 0);
// 
//     //  mrb_funcall(mrb, blinker_obj,"run",0);
//     // return a_obj;
// 
//     RClass* my_class = mrb_define_class(mrb, "Test", mrb->object_class);
//     mrb_value obj = mrb_class_new_instance(mrb, 0, NULL, my_class);
//     mrb_sym sym = mrb_intern(mrb, "asdf", strlen("asdf"));
//     RObject* pobj = mrb_obj_ptr(obj);
//     mrb_obj_iv_set(mrb, pobj, sym, mrb_fixnum_value(1244));
//     return mrb_obj_iv_get(mrb, pobj, sym);
// #endif
}
