/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "StdAfx.h"
#include "OCCViewer.h"

bool OCCViewer::mruby_init()
{
	// init mruby interpretor
	myMirb = new Mirb();

	// コマンドの登録
	// mrb_define_method(ステータス, 登録先, コマンド名, 関数, コマンドが受け取る引数の情報);

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "test",     &OCCViewer::test,     MRB_ARGS_NONE());

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fit",      &OCCViewer::fit,      MRB_ARGS_NONE());
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "erase",    &OCCViewer::erase,    MRB_ARGS_REQ(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "rename",    &OCCViewer::rename,    MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "display",  &OCCViewer::display,  MRB_ARGS_REQ(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "update",   &OCCViewer::update,   MRB_ARGS_NONE());
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "color",    &OCCViewer::color,    MRB_ARGS_REQ(4));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "common",   &OCCViewer::common,   MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cut",      &OCCViewer::cut,      MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fuse",     &OCCViewer::fuse,     MRB_ARGS_REQ(2) | MRB_ARGS_OPT(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "vertex",   &OCCViewer::vertex,   MRB_ARGS_REQ(3) | MRB_ARGS_OPT(1));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "box",      &OCCViewer::box,      MRB_ARGS_REQ(3) | MRB_ARGS_OPT(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cylinder", &OCCViewer::cylinder, MRB_ARGS_REQ(9));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "sphere",   &OCCViewer::sphere,   MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cone",     &OCCViewer::cone,     MRB_ARGS_REQ(11));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "torus",    &OCCViewer::torus,    MRB_ARGS_REQ(12));

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

mrb_value OCCViewer::box(mrb_state* mrb, mrb_value self)
{
	// ruby から引数を取得してくる
    mrb_int _xs, _ys, _zs, _xp, _yp, _zp;
	mrb_value _name;
    int argc = mrb_get_args(mrb, "Siii|iii", &_name, &_xs, &_ys, &_zs, &_xp, &_yp, &_zp);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	// 引数をOpenCASCADEの型にキャスト
	char* name;
	Standard_Real xs, ys, zs, xp = 0, yp = 0, zp = 0;
	switch (argc)
	{
	case 7:
		// 引数が7個だった場合
		xp = (Standard_Real)_xp;
		yp = (Standard_Real)_yp;
		zp = (Standard_Real)_zp;
	case 4:
		// 引数が4個だった場合(位置の値が省略)
		name = RSTRING_PTR(_name);
		xs = (Standard_Real)_xs;
		ys = (Standard_Real)_ys;
		zs = (Standard_Real)_zs;
		break;
	default:
		static const char m[] = "usage: box name, sizex, sizey, sizez[, posx, posy, posz]";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
    
	// OpenCASCADE で box を作成
	BRepPrimAPI_MakeBox box(gp_Pnt(xp, yp, zp), xs, ys, zs);
    TopoDS_Shape shape = box.Shape();

	// 名前を付けて管理構造体につっこむ＆自動描画
	OCCViewer::set(name, &shape);

	return mrb_str_new(mrb, name, strlen(name));
}


mrb_value OCCViewer::sphere(mrb_state* mrb, mrb_value self)
{
    mrb_int _r, _x, _y, _z;
	mrb_value _name;
    int argc = mrb_get_args(mrb, "Si|iii", &_name, &_r, &_x, &_y, &_z);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name;
	Standard_Real r, x = 0, y = 0, z = 0;
	switch (argc) {
	case 5:
		x = (Standard_Real)_x;
		y = (Standard_Real)_y;
		z = (Standard_Real)_z;
	case 2:
		name = RSTRING_PTR(_name);
		r = (Standard_Real)_r;
		break;
	default:
		static const char m[] = "usage: sphere name, R[, posx, posy, posz]";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepPrimAPI_MakeSphere sp(gp_Pnt(x, y, z), r); 
    TopoDS_Shape shape = sp.Shape();

	OCCViewer::set(name, &shape);

	return mrb_str_new(mrb, name, strlen(name));
}

mrb_value OCCViewer::cylinder(mrb_state* mrb, mrb_value self)
{
    mrb_int _px, _py, _pz, _nx, _ny, _nz, _r, _h, _a;
	mrb_value _name;
	int argc = mrb_get_args(mrb, "Siiiiiiiii", &_name, &_px, &_py, &_pz, &_nx, &_ny, &_nz, &_r, &_h, &_a);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name;
	Standard_Real px, py, pz, nx, ny, nz, r, h, a;

	name = RSTRING_PTR(_name);
	px = (Standard_Real)_px;
	py = (Standard_Real)_py;
	pz = (Standard_Real)_pz;
	nx = (Standard_Real)_nx;
	ny = (Standard_Real)_ny;
	nz = (Standard_Real)_nz;
	r = (Standard_Real)_r;
	h = (Standard_Real)_h;
	a = (Standard_Real)_a;

	gp_Pnt pnt(px, py, pz);
	gp_Dir dir(nx, ny, nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCylinder cy(ax, r, h, a);
    TopoDS_Shape shape = cy.Shape();

	OCCViewer::set(name, &shape);

	return mrb_str_new(mrb, name, strlen(name));
}

mrb_value OCCViewer::cone(mrb_state* mrb, mrb_value self)
{
	mrb_int _px, _py, _pz, _nx, _ny, _nz, _r1, _r2, _h, _ang;
	mrb_value _name;
	int argc = mrb_get_args(mrb, "Siiiiiiiiii", &_name, &_px, &_py, &_pz, &_nx, &_ny, &_nz, &_r1, &_r2, &_h, &_ang);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name;
	name = RSTRING_PTR(_name);
	Standard_Real px = (Standard_Real)_px;
	Standard_Real py = (Standard_Real)_py;
	Standard_Real pz = (Standard_Real)_pz;
	Standard_Real nx = (Standard_Real)_nx;
	Standard_Real ny = (Standard_Real)_ny;
	Standard_Real nz = (Standard_Real)_nz;
	Standard_Real r1 = (Standard_Real)_r1;
	Standard_Real r2 = (Standard_Real)_r2;
	Standard_Real h  = (Standard_Real)_h;
	Standard_Real ang = (Standard_Real)_ang;

	gp_Pnt pnt(px, py, pz);
	gp_Dir dir(nx, ny, nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeCone prm(ax, r1, r2, h, ang);
    TopoDS_Shape shape = prm.Shape();

	OCCViewer::set(name, &shape);

	return mrb_str_new(mrb, name, strlen(name));
}

mrb_value OCCViewer::torus(mrb_state* mrb, mrb_value self)
{
	mrb_int _px, _py, _pz, _nx, _ny, _nz, _r1, _r2, _a1, _a2, _ang;
	mrb_value _name;
	int argc = mrb_get_args(mrb, "Siiiiiiiiiii", &_name, &_px, &_py, &_pz, &_nx, &_ny, &_nz, &_r1, &_r2, &_a1, &_a2, &_ang);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name;
	name = RSTRING_PTR(_name);
	Standard_Real px = (Standard_Real)_px;
	Standard_Real py = (Standard_Real)_py;
	Standard_Real pz = (Standard_Real)_pz;
	Standard_Real nx = (Standard_Real)_nx;
	Standard_Real ny = (Standard_Real)_ny;
	Standard_Real nz = (Standard_Real)_nz;
	Standard_Real r1 = (Standard_Real)_r1;
	Standard_Real r2 = (Standard_Real)_r2;
	Standard_Real a1 = (Standard_Real)_a1;
	Standard_Real a2 = (Standard_Real)_a2;
	Standard_Real ang = (Standard_Real)_ang;

	gp_Pnt pnt(px, py, pz);
	gp_Dir dir(nx, ny, nz);
	gp_Ax2 ax(pnt, dir);

	BRepPrimAPI_MakeTorus prm(ax, r1, r2, a1, a2, ang);
    TopoDS_Shape shape = prm.Shape();

	OCCViewer::set(name, &shape);

	return mrb_str_new(mrb, name, strlen(name));
}

void OCCViewer::set(const char* name, const TopoDS_Shape* shape)
{
	OCCViewer::set(name, new AIS_Shape(*shape));
	return;
}

void OCCViewer::set(const char* name, Handle(AIS_Shape) shape)
{
	::Map[std::string(name)] = shape;

	if (AISContext.IsNull()) {
		throw "No AIS Interactive Context.";
	}
	AISContext->Display(shape);
	AISContext->UpdateCurrentViewer();

	return;
}

Handle(AIS_Shape) OCCViewer::get(const char* name)
{
	if (::Map.find(std::string(name)) == ::Map.end())
		return NULL;
	return ::Map[name];
}

mrb_value OCCViewer::erase(mrb_state* mrb, mrb_value self)
{

    mrb_value name;

	int argc = mrb_get_args(mrb, "S", &name);

	if (!mrb_string_p(name)) {
		static const char m[] = "Invalid specified name.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	Handle(AIS_Shape) myShape = OCCViewer::get(RSTRING_PTR(name));
	if (myShape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	AISContext->Erase(myShape, Standard_True, Standard_False);
	//AISContext->UpdateCurrentViewer();
	Map.erase(RSTRING_PTR(name));

	return mrb_nil_value();
}

mrb_value OCCViewer::display(mrb_state* mrb, mrb_value self)
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

mrb_value OCCViewer::color(mrb_state* mrb, mrb_value self)
{
	if (AISContext.IsNull())
		return mrb_nil_value();

    mrb_value _name;
	mrb_float _r, _g, _b;
	int argc = mrb_get_args(mrb, "Sfff", &_name, &_r, &_g, &_b);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name = RSTRING_PTR(_name);
	Standard_Real r = (Standard_Real)_r;
	Standard_Real g = (Standard_Real)_g;
	Standard_Real b = (Standard_Real)_b;

	Handle(AIS_Shape) myShape = OCCViewer::get(name);
	if (myShape.IsNull())
		return mrb_nil_value();

	Quantity_Color col =  Quantity_Color(r/255., g/255., b/255., Quantity_TOC_RGB);
    AISContext->SetColor(myShape, col.Name());

	return mrb_str_new(mrb, name, strlen(name));
}

mrb_value OCCViewer::update(mrb_state* mrb, mrb_value self)
{
	AISContext->UpdateCurrentViewer();
	return mrb_nil_value();
}

mrb_value OCCViewer::fit(mrb_state* mrb, mrb_value self)
{
	if (!View.IsNull()) {
		View->FitAll();
		View->ZFitAll();
	}
	return mrb_nil_value();
}

mrb_value OCCViewer::test(mrb_state* mrb, mrb_value self)
{

	return mrb_nil_value();
}

mrb_value OCCViewer::common(mrb_state* mrb, mrb_value self)
{
	return mrb_nil_value();	
    mrb_value s1, s2, name;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	if (!mrb_string_p(s1) || !mrb_string_p(s2)) {
		static const char m[] = "Invalid specified name at first or second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if (argc == 3) {
		if (!mrb_string_p(name)) {
			static const char m[] = "Invalid specified name at last.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_COMMON);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		if (hasname) {
			OCCViewer::set(RSTRING_PTR(name), &shape);
			result = name;
		}
		else {
			char aname[16];
			sprintf(aname, "%X", shape.HashCode(INT_MAX));
			OCCViewer::set(aname, &shape);
			result = mrb_str_new(mrb, aname, strlen(aname));
		}
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

mrb_value OCCViewer::cut(mrb_state* mrb, mrb_value self)
{
	return mrb_nil_value();	
    mrb_value s1, s2, name;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	if (!mrb_string_p(s1) || !mrb_string_p(s2)) {
		static const char m[] = "Invalid specified name at first or second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if (argc == 3) {
		if (!mrb_string_p(name)) {
			static const char m[] = "Invalid specified name at last.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_CUT);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		if (hasname) {
			OCCViewer::set(RSTRING_PTR(name), &shape);
			result = name;
		}
		else {
			char aname[16];
			sprintf(aname, "%X", shape.HashCode(INT_MAX));
			OCCViewer::set(aname, &shape);
			result = mrb_str_new(mrb, aname, strlen(aname));
		}
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

mrb_value OCCViewer::fuse(mrb_state* mrb, mrb_value self)
{
    mrb_value s1, s2, name;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "SS|S", &s1, &s2, &name);

	if (!mrb_string_p(s1) || !mrb_string_p(s2)) {
		static const char m[] = "Invalid specified name at first or second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if (argc == 3) {
		if (!mrb_string_p(name)) {
			static const char m[] = "Invalid specified name at last.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}

	Handle(AIS_Shape) haS1 = OCCViewer::get(RSTRING_PTR(s1));
	if (haS1.IsNull()) {
		static const char m[] = "No such object name of specified at first.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	Handle(AIS_Shape) haS2 = OCCViewer::get(RSTRING_PTR(s2));
	if (haS2.IsNull()) {
		static const char m[] = "No such object name of specified at second.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	BRepAlgoAPI_Common bo(haS1->Shape(), haS2->Shape());
	bo.SetOperation(BOPAlgo_FUSE);
	bo.Build();

	mrb_value result;

	if (!bo.ErrorStatus()) {
	    TopoDS_Shape shape = bo.Shape();
		if (hasname) {
			OCCViewer::set(RSTRING_PTR(name), &shape);
			result = name;
		}
		else {
			char aname[16];
			sprintf(aname, "%X", shape.HashCode(INT_MAX));
			OCCViewer::set(aname, &shape);
			result = mrb_str_new(mrb, aname, strlen(aname));
		}
	}
	else {
		static const char m[] = "Failed to fuse operation of boolean.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	
	return result;
}

mrb_value OCCViewer::savebrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path, name;
	int argc = mrb_get_args(mrb, "SS", &path, &name);
	if (!mrb_string_p(name) || !mrb_string_p(path)) {
		static const char m[] = "Invalid specified name or path.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	mrb_value result;

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(name));

	if (hashape.IsNull()) {
		static const char m[] = "No such named object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	else {
		Standard_Boolean res = BRepTools::Write(hashape->Shape(), (Standard_CString)RSTRING_PTR(path));

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

mrb_value OCCViewer::loadbrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path, name;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "S|S", &path, &name);

	if (!mrb_string_p(path)) {
		static const char m[] = "Invalid specified path.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	if (argc == 2) {
		if (!mrb_string_p(name)) {
			static const char m[] = "Invalid specified name.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}

	TopoDS_Shape shape;
    BRep_Builder aBuilder;
    Standard_Boolean res = BRepTools::Read(shape, (Standard_CString)RSTRING_PTR(path), aBuilder);

	mrb_value result;

	if (res) {
		if(AISContext->HasOpenedContext())
			AISContext->CloseLocalContext();
		if (hasname) {
			OCCViewer::set(RSTRING_PTR(name), &shape);
			result = name;
		}
		else {
			char aname[16];
			sprintf(aname, "%X", shape.HashCode(INT_MAX));
			OCCViewer::set(aname, &shape);
			result = mrb_str_new(mrb, aname, strlen(aname));
		}
	}
	else {
		static const char m[] = "Failed to read BRep file.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

mrb_value OCCViewer::vertex(mrb_state* mrb, mrb_value self)
{
	mrb_float x, y, z;
	mrb_value name;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "fff|S", &x, &y, &z, &name);
	if (argc == 4) {
		if (!mrb_string_p(name)) {
			static const char m[] = "Invalid specified name.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}

	gp_Pnt p((Standard_Real)x, (Standard_Real)y, (Standard_Real)z);
	TopoDS_Vertex v = BRepBuilderAPI_MakeVertex(p);

	mrb_value result;

	if (hasname) {
		OCCViewer::set(RSTRING_PTR(name), &v);
		result = name;
	}
	else {
		char aname[16];
		sprintf(aname, "%X", v.HashCode(INT_MAX));
		OCCViewer::set(aname, &v);
		result = mrb_str_new(mrb, aname, strlen(aname));
	}

	// mrb_value r[3];
	// r[0] = mrb_float_value(mrb, _x);
	// r[1] = mrb_float_value(mrb, _y);
	// r[2] = mrb_float_value(mrb, _z);
	// mrb_value res = mrb_ary_new_from_values(mrb, 3, r);

	return result;
}

mrb_value OCCViewer::rename(mrb_state* mrb, mrb_value self)
{
	mrb_value src, dest;
	bool hasname = false;

	int argc = mrb_get_args(mrb, "S|S", &src, &dest);
	if (argc == 2) {
		if (!mrb_string_p(dest)) {
			static const char m[] = "Invalid specified name of dest.";
	        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
		hasname = true;
	}
	if (!mrb_string_p(src)) {
		static const char m[] = "Invalid specified name of src.";
	    return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	Handle(AIS_Shape) hashape = OCCViewer::get(RSTRING_PTR(src));
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	Map.erase(RSTRING_PTR(dest));
    TopoDS_Shape shape = hashape->Shape();

    mrb_value result;

	if (hasname) {
		OCCViewer::set(RSTRING_PTR(dest), &shape);
		result = dest;
	}
	else {
		char aname[16];
		sprintf(aname, "%X", shape.HashCode(INT_MAX));
		OCCViewer::set(aname, &shape);
		result = mrb_str_new(mrb, aname, strlen(aname));
	}

	return result;
}
