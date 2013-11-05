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

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "test",     &OCCViewer::test,     MRB_ARGS_NONE());

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fit",      &OCCViewer::fit,      MRB_ARGS_NONE());
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "erase",    &OCCViewer::erase,    MRB_ARGS_REQ(1));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "common",   &OCCViewer::common,   MRB_ARGS_REQ(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cut",      &OCCViewer::cut,      MRB_ARGS_REQ(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "fuse",     &OCCViewer::fuse,     MRB_ARGS_REQ(3));

	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "box",      &OCCViewer::box,      MRB_ARGS_REQ(3) | MRB_ARGS_OPT(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cylinder", &OCCViewer::cylinder, MRB_ARGS_REQ(9));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "sphere",   &OCCViewer::sphere,   MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "cone",     &OCCViewer::cone,     MRB_ARGS_REQ(11));
	mrb_define_method(myMirb->mrb, myMirb->mrb->kernel_module, "torus",    &OCCViewer::torus,    MRB_ARGS_REQ(12));

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
    mrb_int _xs, _ys, _zs, _xp, _yp, _zp;
	mrb_value _name;
    int argc = mrb_get_args(mrb, "Siii|iii", &_name, &_xs, &_ys, &_zs, &_xp, &_yp, &_zp);
	if (!mrb_string_p(_name))
		return mrb_nil_value();

	char* name;
	Standard_Real xs, ys, zs, xp = 0, yp = 0, zp = 0;
	switch (argc)
	{
	case 7:
		xp = (Standard_Real)_xp;
		yp = (Standard_Real)_yp;
		zp = (Standard_Real)_zp;
	case 4:
		name = RSTRING_PTR(_name);
		xs = (Standard_Real)_xs;
		ys = (Standard_Real)_ys;
		zs = (Standard_Real)_zs;
		break;
	default:
        mrb_value myexc;
        static const char m[] = "super called outside of method";
        myexc = mrb_exc_new(mrb, E_NOMETHOD_ERROR, m, sizeof(m) - 1);
        mrb->exc = mrb_obj_ptr(myexc);
		return mrb_nil_value();
		//break;
	}
    
	BRepPrimAPI_MakeBox box(gp_Pnt(xp, yp, zp), xs, ys, zs);
    TopoDS_Shape shape = box.Shape();

	OCCViewer::set(name, &shape);

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
        mrb_value myexc;
        static const char m[] = "super called outside of method";
        myexc = mrb_exc_new(mrb, E_NOMETHOD_ERROR, m, sizeof(m) - 1);
        mrb->exc = mrb_obj_ptr(myexc);
		return mrb_nil_value();
		//break;
	}

	BRepPrimAPI_MakeSphere sp(gp_Pnt(x, y, z), r); 
    TopoDS_Shape shape = sp.Shape();

	OCCViewer::set(name, &shape);

	return mrb_nil_value();
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

	return mrb_nil_value();
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

	return mrb_nil_value();
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

	return mrb_nil_value();
}

void OCCViewer::set(const char* name, const TopoDS_Shape* shape)
{
	OCCViewer::set(name, new AIS_Shape(*shape));
	return;
}

void OCCViewer::set(const char* name, Handle(AIS_Shape) shape)
{
	::Map[name] = shape;

	if (AISContext.IsNull())
		throw "No AIS context!";

	AISContext->Display(shape);
	AISContext->UpdateCurrentViewer();
	return;
}

Handle(AIS_Shape) OCCViewer::get(const char* name)
{
	if (::Map.find(name) == ::Map.end())
		return NULL;
	return ::Map[name];
}

mrb_value OCCViewer::erase(mrb_state* mrb, mrb_value self)
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

	AISContext->Erase(myShape, Standard_True, Standard_False);
	AISContext->UpdateCurrentViewer();

	return mrb_nil_value();
}

mrb_value OCCViewer::test(mrb_state* mrb, mrb_value self)
{

	return mrb_nil_value();
}

mrb_value OCCViewer::common(mrb_state* mrb, mrb_value self)
{
    mrb_value _a, _b, _c;
	int argc = mrb_get_args(mrb, "SSS", &_a, &_b, &_c);
	if (!mrb_string_p(_a) || !mrb_string_p(_b) || !mrb_string_p(_c))
		return mrb_nil_value();

	char* a = RSTRING_PTR(_a);
	char* b = RSTRING_PTR(_b);
	char* c = RSTRING_PTR(_c);

	Handle(AIS_Shape) B = OCCViewer::get(b);
	Handle(AIS_Shape) C = OCCViewer::get(c);
	
	TopoDS_Shape BB = B->Shape();
	TopoDS_Shape CC = C->Shape();

	// ブーリアン演算オブジェクトを s1 と s2 で作成
	BRepAlgoAPI_Common bo(BB, CC);

	// ブーリアン演算オブジェクトのオペレーションを指定
	// BOPAlgo_COMMON:  s1 と s2 の共通部分を得る
	// BOPAlgo_FUSE:    s1 と s2 を結合したものを得る
	// BOPAlgo_CUT:     s1 を s2 でカットしたものを得る
	// BOPAlgo_CUT21:   s1 で s1 をカットしたものを得る
	// BOPAlgo_SECTION: s1 と s2 のセクションを得る
	bo.SetOperation(BOPAlgo_COMMON);

	// 計算の実行
	bo.Build();

	// エラーが発生していなかったら
	if (!bo.ErrorStatus()) {
	    TopoDS_Shape S = bo.Shape();
		OCCViewer::set(a, &S);
	}
	
	return mrb_nil_value();	
}

mrb_value OCCViewer::cut(mrb_state* mrb, mrb_value self)
{
    mrb_value _a, _b, _c;
	int argc = mrb_get_args(mrb, "SSS", &_a, &_b, &_c);
	if (!mrb_string_p(_a) || !mrb_string_p(_b) || !mrb_string_p(_c))
		return mrb_nil_value();

	char* a = RSTRING_PTR(_a);
	char* b = RSTRING_PTR(_b);
	char* c = RSTRING_PTR(_c);

	Handle(AIS_Shape) B = OCCViewer::get(b);
	Handle(AIS_Shape) C = OCCViewer::get(c);
	
	TopoDS_Shape BB = B->Shape();
	TopoDS_Shape CC = C->Shape();

	// ブーリアン演算オブジェクトを s1 と s2 で作成
	BRepAlgoAPI_Common bo(BB, CC);

	// ブーリアン演算オブジェクトのオペレーションを指定
	// BOPAlgo_COMMON:  s1 と s2 の共通部分を得る
	// BOPAlgo_FUSE:    s1 と s2 を結合したものを得る
	// BOPAlgo_CUT:     s1 を s2 でカットしたものを得る
	// BOPAlgo_CUT21:   s1 で s1 をカットしたものを得る
	// BOPAlgo_SECTION: s1 と s2 のセクションを得る
	bo.SetOperation(BOPAlgo_CUT);

	// 計算の実行
	bo.Build();

	// エラーが発生していなかったら
	if (!bo.ErrorStatus()) {
	    TopoDS_Shape S = bo.Shape();
		OCCViewer::set(a, &S);
	}
	
	return mrb_nil_value();	
}

mrb_value OCCViewer::fuse(mrb_state* mrb, mrb_value self)
{
    mrb_value _a, _b, _c;
	int argc = mrb_get_args(mrb, "SSS", &_a, &_b, &_c);
	if (!mrb_string_p(_a) || !mrb_string_p(_b) || !mrb_string_p(_c))
		return mrb_nil_value();

	char* a = RSTRING_PTR(_a);
	char* b = RSTRING_PTR(_b);
	char* c = RSTRING_PTR(_c);

	Handle(AIS_Shape) B = OCCViewer::get(b);
	Handle(AIS_Shape) C = OCCViewer::get(c);
	
	TopoDS_Shape BB = B->Shape();
	TopoDS_Shape CC = C->Shape();

	// ブーリアン演算オブジェクトを s1 と s2 で作成
	BRepAlgoAPI_Common bo(BB, CC);

	// ブーリアン演算オブジェクトのオペレーションを指定
	// BOPAlgo_COMMON:  s1 と s2 の共通部分を得る
	// BOPAlgo_FUSE:    s1 と s2 を結合したものを得る
	// BOPAlgo_CUT:     s1 を s2 でカットしたものを得る
	// BOPAlgo_CUT21:   s1 で s1 をカットしたものを得る
	// BOPAlgo_SECTION: s1 と s2 のセクションを得る
	bo.SetOperation(BOPAlgo_FUSE);

	// 計算の実行
	bo.Build();

	// エラーが発生していなかったら
	if (!bo.ErrorStatus()) {
	    TopoDS_Shape S = bo.Shape();
		OCCViewer::set(a, &S);
	}
	
	return mrb_nil_value();	
}
