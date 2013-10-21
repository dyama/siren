/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#include "stdafx.h"

class OCCViewer
{
public:
	OCCViewer(void);
	~OCCViewer(void);
private:
	Handle_V3d_Viewer myViewer;
	Handle_V3d_View myView;
	Handle_AIS_InteractiveContext myAISContext;
	Handle_Graphic3d_GraphicDriver myGraphicDriver;
private:
	// std::map<Standard_CString, AIS_Shape*>* myMap;
	//std::map<int, AIS_Shape*>* myMap;
	//std::map<Standard_CString, int>* myMap2;

private:
	void initViewAppearance(void);

public:
	bool InitViewer(void* wnd);
	bool ImportBRep(char* filename);
	void UpdateView(void);
	void RedrawView(void);
	void SetDegenerateModeOn(void);
	void SetDegenerateModeOff(void);
	void WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax);
	void Place(int x, int y, float zoomFactor);
	void Zoom(int x1, int y1, int x2, int y2);
	void Pan(int x, int y);
	void Rotation(int x, int y);
	void StartRotation(int x, int y);
	void Select(int x1, int y1, int x2, int y2);
	void Select(void);
	void MoveTo(int x, int y);
	void ShiftSelect(int x1, int y1, int x2, int y2);
	void ShiftSelect(void);
	void BackgroundColor(int& r, int& g, int& b);
	void UpdateCurrentViewer(void);
	void FrontView(void);
	void TopView(void);
	void LeftView(void);
	void BackView(void);
	void RightView(void);
	void BottomView(void);
	void AxoView(void);
	void ZoomAllView(void);
	float Scale(void);
	void setScale(double f);
	void PanGloView(void);
	void ResetView(void);
	void SetDisplayMode(int aMode);
	void SetColor(int r, int g, int b);
	void ObjectColor(int& r, int& g, int& b);
	void SetBackgroundColor(int r, int g, int b);
	void EraseObjects(void);
	float GetVersion(void);
	void SetMaterial(int theMaterial);
	void SetTransparency(int theTrans);
	bool ImportCsfdb(char* filename);
	bool ImportIges(char* filename);
	bool ImportStep(char* filename);
	bool ExportBRep(char* filename);
	bool ExportIges(char* filename);
	bool ExpotStep(char* filename);
	bool ExportStl(char* filename);
	bool ExportVrml(char* filename);
	bool Dump(char* filename);
	bool IsObjectSelected(void);
	int DisplayMode(void);
	void CreateNewView(void* wnd);
	bool SetAISContext(OCCViewer* Viewer);
	Handle_AIS_InteractiveContext GetAISContext(void);
	int CharToInt(char symbol);
	int Debug(void);

	// void         Set(Standard_CString name, TopoDS_Shape& shape);
	// void         Set(int hashcode, TopoDS_Shape& shape);
	// TopoDS_Shape Get(Standard_CString name);
	// TopoDS_Shape Get(int hashcode);
};
