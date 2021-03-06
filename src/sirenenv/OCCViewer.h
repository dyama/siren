/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
* WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
* IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
* ---------------------------------------------------------
* AUTHOR: dyama <dyama@member.fsf.org>
*/

#pragma once
#ifndef _OCCVIEWER_H_
#define _OCCVIEWER_H_

#include "Stdafx.h"

class OCCViewer
{
public:
	OCCViewer(void);
	~OCCViewer(void);

public:
	void initViewAppearance(bool grad, bool is_raytracing, bool is_shadow, bool is_antialias, bool is_reflection);
	Handle(AIS_InteractiveContext)  aiscxt;
	Handle(V3d_Viewer)              viewer;
	Handle(V3d_View)                view;
	Handle(Graphic3d_GraphicDriver) myGraphicDriver;

	// Object manager
	std::map<int, TopoDS_Shape> shapeman;
	// Clipping plane manager
	std::map<int, Handle(Graphic3d_ClipPlane)> clipman;
	// std::map<int, Graphic3d_SequenceOfHClipPlane*> clipmans;

public: // Ruby
	Mirb* myMirb;
	bool  mruby_init();
	bool  mruby_cleenup();
#if 1
	int   mruby_exec(char* command, std::string& errmsg);
#endif
	void  regcmd(const char* name, mrb_func_t func, int arg_req, int arg_opt, const char* desc, const char* usage);

public: // View, Viewer
	bool  InitViewer(void* wnd, bool grad, bool is_raytracing, bool is_parsepective);
	void  CreateNewView(void* wnd, bool grad, bool is_raytracing);
	bool  SetAISContext(OCCViewer* Viewer);
	Handle(AIS_InteractiveContext) GetAISContext(void);
	void  MustBeResized(void);
	void  Redraw(void);
	void  Redraw(int x, int y, int w, int h);
	void  UpdateCurrentViewer(void);
	void  WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax);
	void  setProjection(V3d_TypeOfOrientation dir);
	void  ZoomAllView(void);
	void  ZFitAll(void);
	void  PanGloView(void);
	void  ResetView(void);
	void  SetDisplayMode(int aMode);

public: // Information
	int   DisplayMode(void);
	bool  IsObjectSelected(void);
	int   NbSelected(void);

public: // Shape apperance
	void  SetAntialiasing(bool isOn);
	void  SetHighlightColor(Quantity_NameOfColor color);
	void  SetSelectionColor(Quantity_NameOfColor color);
	void  ObjectColor(int& r, int& g, int& b);

public: // Mouse events bindings
	float Scale(void);
	void  setScale(double f);
	void  SetComputedMode(bool value);
	void  Zoom(int x1, int y1, int x2, int y2);
	void  Pan(int x, int y);
	void  Rotation(int x, int y);
	void  StartRotation(int x, int y);
	void  Select(int x1, int y1, int x2, int y2);
	void  Select(void);
	void  MoveTo(int x, int y);
	void  ShiftSelect(int x1, int y1, int x2, int y2);
	void  ShiftSelect(void);

public: // Common functions
	int   CharToInt(char symbol);
	bool  xy2xyz(int Xs, int Ys, double& X, double& Y, double& Z, bool usePrecision);

};

#endif // _OCCVIEWER_H_
