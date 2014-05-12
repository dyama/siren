/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
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
    void initViewAppearance(bool is_raytracing, bool is_shadow, bool is_antialias, bool is_reflection);
	Handle(AIS_InteractiveContext)  aiscxt;
	Handle(V3d_Viewer)              viewer;
	Handle(V3d_View)                view;
	Handle(Graphic3d_GraphicDriver) myGraphicDriver;

public: // Ruby
	Mirb* myMirb;
	bool  mruby_init();
	bool  mruby_cleenup();
	int   mruby_exec(char* cmd);
	int   mruby_exec(char* command, std::string& errmsg);
	void  regcmd(const char* name, mrb_func_t func, int arg_req, int arg_opt, const char* desc, const char* usage);

public: // View, Viewer
    bool  InitViewer(void* wnd, bool is_raytracing, bool is_parsepective);
    void  CreateNewView(void* wnd, bool is_raytracing);
	bool  SetAISContext(OCCViewer* Viewer);
	Handle_AIS_InteractiveContext GetAISContext(void);
	void  UpdateView(void);
	void  RedrawView(void);
	void  WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax);
	void  UpdateCurrentViewer(void);
	void  setProjection(V3d_TypeOfOrientation dir);
	void  ZoomAllView(void);
	void  PanGloView(void);
	void  ResetView(void);
	void  SetDisplayMode(int aMode);

public: // Information
	float GetVersion(void);
	int   DisplayMode(void);
	bool  IsObjectSelected(void);
    int   NbSelected(void);

public: // Shape apperance
	void  SetMaterial(int theMaterial);
	void  SetTransparency(int theTrans);
	void  SetAntialiasing(bool isOn);
	void  SetHighlightColor(Quantity_NameOfColor color);
	void  SetSelectionColor(Quantity_NameOfColor color);
	void  SetColor(int r, int g, int b);
	void  ObjectColor(int& r, int& g, int& b);
	void  BackgroundColor(int& r, int& g, int& b);
	void  SetBackgroundColor(int r, int g, int b);
	void  EraseObjects(void);

public: // Mouse events bindings
	float Scale(void);
	void  setScale(double f);
	void  SetDegenerateModeOn(void);
	void  SetDegenerateModeOff(void);
	void  Place(int x, int y, float zoomFactor);
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

public: // I/O
	// bool  ImportCsfdb(wchar_t* filename);
	// bool  ImportIges (wchar_t* filename);
	// bool  ImportStep (wchar_t* filename);
	// bool  ExportIges (wchar_t* filename);
	// bool  ExportStep  (wchar_t* filename);
	// bool  ExportStl  (wchar_t* filename);
	// bool  ExportVrml (wchar_t* filename);
	// bool  Dump       (wchar_t* filename);

};

#endif // _OCCVIEWER_H_
