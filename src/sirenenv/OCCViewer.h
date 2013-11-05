/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#include "stdafx.h"
#include "mirb.h"

#ifndef _MAX_PATH
#define _MAX_PATH 1024
#endif

static Handle_AIS_InteractiveContext AISContext;
static Handle_V3d_View               View;
static std::map<std::string, Handle(AIS_Shape)> Map;

class OCCViewer
{
public:
	OCCViewer(void);
	~OCCViewer(void);

private:
	void initViewAppearance(void);

	Handle_AIS_InteractiveContext myAISContext;
	Handle_V3d_Viewer myViewer;
	Handle_V3d_View myView;
	Handle_Graphic3d_GraphicDriver myGraphicDriver;

public:
	Mirb* myMirb;
	bool  mruby_init();
	bool  mruby_cleenup();
	int   mruby_exec(char* command);
	static mrb_value box(mrb_state* mrb, mrb_value self);
	static mrb_value fit(mrb_state* mrb, mrb_value self);
	static mrb_value cylinder(mrb_state* mrb, mrb_value self);
	static mrb_value cone(mrb_state* mrb, mrb_value self);
	static mrb_value sphere(mrb_state* mrb, mrb_value self);
	static mrb_value torus(mrb_state* mrb, mrb_value self);

	static void set(std::string name, TopoDS_Shape* shape);
	static void set(std::string name, Handle(AIS_Shape) shape);
	static Handle(AIS_Shape) get(std::string name);

	static mrb_value erase(mrb_state* mrb, mrb_value self);
	static mrb_value common(mrb_state* mrb, mrb_value self);
	static mrb_value test(mrb_state* mrb, mrb_value self);

public:
	bool  InitViewer(void* wnd);
	void  UpdateView(void);
	void  RedrawView(void);
	void  SetDegenerateModeOn(void);
	void  SetDegenerateModeOff(void);
	void  WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax);
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
	void  BackgroundColor(int& r, int& g, int& b);
	void  UpdateCurrentViewer(void);

	void  setProjection(V3d_TypeOfOrientation dir);

	void  ZoomAllView(void);
	float Scale(void);
	void  setScale(double f);
	void  PanGloView(void);
	void  ResetView(void);
	void  SetDisplayMode(int aMode);
	void  SetColor(int r, int g, int b);
	void  ObjectColor(int& r, int& g, int& b);
	void  SetBackgroundColor(int r, int g, int b);
	void  EraseObjects(void);
	float GetVersion(void);
	void  SetMaterial(int theMaterial);
	void  SetTransparency(int theTrans);
	void  SetAntialiasing(bool isOn);
	bool  ImportBRep (wchar_t* filename);
	bool  ImportCsfdb(wchar_t* filename);
	bool  ImportIges (wchar_t* filename);
	bool  ImportStep (wchar_t* filename);
	bool  ExportBRep (wchar_t* filename);
	bool  ExportIges (wchar_t* filename);
	bool  ExpotStep  (wchar_t* filename);
	bool  ExportStl  (wchar_t* filename);
	bool  ExportVrml (wchar_t* filename);
	bool  Dump       (wchar_t* filename);
	bool  IsObjectSelected(void);
	int   DisplayMode(void);
	void  CreateNewView(void* wnd);
	bool  SetAISContext(OCCViewer* Viewer);
	Handle_AIS_InteractiveContext GetAISContext(void);
	int   CharToInt(char symbol);
	void  SetHighlightColor(Quantity_NameOfColor color);
	void  SetSelectionColor(Quantity_NameOfColor color);

	// void         Set(Standard_CString name, TopoDS_Shape& shape);
	// void         Set(int hashcode, TopoDS_Shape& shape);
	// TopoDS_Shape Get(Standard_CString name);
	// TopoDS_Shape Get(int hashcode);

};
