/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "StdAfx.h"
#include "OCCViewer.h"

#pragma warning(disable : 4800)

/**
 * \brief コンストラクタ
 */
OCCViewer::OCCViewer(void)
{
	myGraphicDriver = NULL;
	viewer = NULL;
	view = NULL;
	aiscxt = NULL;

	mruby_init();
}

/**
 * \brief デストラクタ
 */
OCCViewer::~OCCViewer(void)
{
	view->Remove();
	mruby_cleenup();
}

/**
 * \brief ビューの初期化
 */
void OCCViewer::initViewAppearance(bool grad, bool is_raytracing, bool is_shadow, bool is_antialias, bool is_reflection)
{
    // is_raytracing = true;
    // is_shadow = false;
    // is_antialias = false;
    // is_reflection = false;

    if (is_raytracing) { // Enable ray tracing mode
        view->SetRaytracingMode();
        view->EnableGLLight(Standard_True);
        is_shadow     ? view->EnableRaytracedShadows()      : view->DisableRaytracedShadows();
        is_antialias  ? view->EnableRaytracedAntialiasing() : view->DisableRaytracedAntialiasing();
        is_reflection ? view->EnableRaytracedReflections()  : view->DisableRaytracedReflections();
    }
    else { // OpenGL rasterize rennaring mode
        view->SetRasterizationMode();
    }
	//view->SetShadingModel(V3d_GOURAUD);

    if (grad) { // Background color
#if 0
        Quantity_Color color_top(0.35, 0.35, 0.35, Quantity_TOC_RGB);
        Quantity_Color color_btm(0.10, 0.10, 0.10, Quantity_TOC_RGB);
#else
        Quantity_Color color_top(0.00, 0.50, 0.70, Quantity_TOC_RGB);
        Quantity_Color color_btm(0.00, 0.13, 0.25, Quantity_TOC_RGB);
#endif
        view->SetBgGradientColors(color_top, color_btm, Aspect_GFM_VER, Standard_False);
    }
    else {
        view->SetBackgroundColor(Quantity_NOC_GRAY20);
    }

	// Show trihedron on 3d viewer
    view->TriedronDisplay(Aspect_TOTP_RIGHT_UPPER, Quantity_NOC_WHITE, 0.1, V3d_ZBUFFER);
	//view->ZBufferTriedronSetup();

	// 
	//view->GraduatedTrihedronDisplay();

	//view->TriedronEcho(Aspect_TOTE_AXIS_X);

	// !!!!
	//view->SetViewingVolume();

    // Depth-cueing (空気遠近法)の有効化
 	//view->SetZCueingOn();

	// Viewpoint control
	view->SetAt(0.0, 0.0, 0.0);
	view->SetEye(-1, -1, 1);
	view->SetScale(5.0); // 15.0 for perspective view
	view->SetUp(0.0, 0.0, 1.0);
	view->SetCenter(0.0, 0.0);

	//view->SetAntialiasingOn();
	//view->SetClipPlanes();
	//view->SetFocale(50000);
	//view->SetTransparency(Standard_True);
	//view->Redraw();
	//view->FitAll();

	view->MustBeResized();
	return;
}

/**
 * \brief ビューアの初期化
 */
bool OCCViewer::InitViewer(void* wnd, bool grad, bool is_raytracing, bool is_parsepective)
{
	// init graphic driver
    try {
        Handle(Aspect_DisplayConnection) aDisplayConnection;
        myGraphicDriver = Graphic3d::InitGraphicDriver(aDisplayConnection);
    }
    catch (Standard_Failure) {
        return false;
    }

	// init viewer
    TCollection_ExtendedString a3DName("Visu3D");
    viewer = new V3d_Viewer (myGraphicDriver, a3DName.ToExtString(), "", 1000.0, 
                             V3d_XposYnegZpos, Quantity_NOC_BLACK);
	// default attributes of viewer
	//viewer->SetDefaultVisualization(V3d_ZBUFFER);
	// end of attributes

	// vbo
	Handle(OpenGl_GraphicDriver) aDriver
		= Handle(OpenGl_GraphicDriver)::DownCast(viewer->Driver());
	aDriver->ChangeOptions().vboDisable = Standard_False;

	//viewer->Init();
	viewer->InitDefinedViews();

#if 1
	viewer->SetDefaultLights();
	viewer->SetLightOn();
#else
	Handle(V3d_DirectionalLight) light = new V3d_DirectionalLight(viewer, V3d_Zneg);
	//light->Position(V3d_Coodinate(0, 0, 1000);
	//light->SetHeadlight(Standard_False);
	light->SetHeadlight(Standard_True);
	viewer->SetLightOn(light);
	//viewer->SetDefaultTypeOfView(V3d_TypeOfView::V3d_ORTHOGRAPHIC);
	//viewer->SetPrivilegedPlane(gp_Ax3(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1)));
#endif

	// test for Z-Layer
	//Standard_Integer aLayerId;
	//viewer->AddZLayer(aLayerId);

	// Enable auto control Z buffer for clipping
	viewer->SetZBufferManagment(Standard_True);

	// init AIS context and common appearances
	aiscxt = new AIS_InteractiveContext(viewer);
	// highlight color, selection color
    aiscxt->SetHilightColor(Quantity_NOC_YELLOW);
	aiscxt->SelectionColor(Quantity_NOC_RED);
    aiscxt->SetToHilightSelected(Standard_True);

	// trihedron at origin point
	// Handle(Geom_Axis2Placement) aTrihedronAxis = new Geom_Axis2Placement(gp::XOY());
	// Handle(AIS_Trihedron) aTrihedron = new AIS_Trihedron(aTrihedronAxis);
	// aTrihedron->SetSize(0.5 * 1000);
	// //aiscxt->Display(aTrihedron, 0, -1, Standard_False, Standard_False); 
	// aiscxt->Display(aTrihedron);
	// aiscxt->Deactivate(aTrihedron);

	// ビューの初期化
	//view = new V3d_PerspectiveView(viewer);
	view = viewer->CreateView();

	Handle(WNT_Window) aWNTWindow = new WNT_Window (reinterpret_cast<HWND> (wnd));
	view->SetWindow(aWNTWindow);
	if (!aWNTWindow->IsMapped()) 
		 aWNTWindow->Map();

    initViewAppearance(grad, is_raytracing, true, true, true);


#if 0
    {
        //viewer->Driver()->Text((Standard_CString)"siren", 0.5, 0.5, 120.0);
        Standard_Integer w,h;
        Handle(Aspect_Window) hWin = view->Window();
        hWin->Size(w, h);

        // test for layer
        Handle(Visual3d_Layer) lay
            = new Visual3d_Layer(viewer->Viewer(), Aspect_TOL_OVERLAY, Standard_False);
        lay->Clear();
        lay->Begin();
        lay->SetViewport(w, h);
        lay->SetOrtho( 0, Max(w, h), Max(w, h), 0, Aspect_TOC_TOP_LEFT);
        //lay->SetTextAttributes("Times-Roman", Aspect_TODT_NORMAL, Quantity_Color(Quantity_NOC_ORANGE));
        //lay->SetTextAttributes((Standard_CString)"Arial", Aspect_TODT_NORMAL, Quantity_Color(Quantity_NOC_WHITE));
        lay->SetTextAttributes(Font_NOF_ASCII_MONO, Aspect_TODT_NORMAL, Quantity_NOC_WHITE);
        lay->DrawText((Standard_CString)"A", 0.0, 0.0, 40.0);
        // {
        //     //lay->SetTransparency(0.5);

        //     lay->BeginPolygon(); {
        //         lay->SetColor(Quantity_Color(1., 0., 0., Quantity_TOC_RGB));
        //         lay->AddVertex(.95, -.9);
        //         lay->AddVertex(.95, -.95);
        //         lay->AddVertex(.8, -.95);
        //         lay->AddVertex(.8, -.9);
        //         lay->AddVertex(.95, -.9);
        //     } lay->ClosePrimitive();
        //     lay->BeginPolyline(); {
        //         lay->SetColor(Quantity_Color(1., 1., 1., Quantity_TOC_RGB));
        //         lay->AddVertex(-.95, .9);
        //         lay->AddVertex(-.95, -.5);
        //         lay->AddVertex(-.8, -.5);
        //         lay->AddVertex(-.8, .9);
        //         lay->AddVertex(-.95, .9);
        //     } lay->ClosePrimitive();

        // }
        lay->End();
    }
#endif


#if 1
	// grid
	{
		gp_Pnt p(0, 0, 0);
		gp_Vec v(0, 0, 1);
		gp_Ax3 ax(p, v);
		Quantity_Length XOrigin = 0;
		Quantity_Length YOrigin = 0;
		Quantity_Length XStep = 10;
		Quantity_Length YStep = 10;
		Quantity_Length Rotation = 0;
		Quantity_Length XSize = XStep * 20 + 1.0e-7;
		Quantity_Length YSize = YStep * 20 + 1.0e-7;
		Quantity_Length Offset = 0;
		viewer->SetPrivilegedPlane(ax);
		viewer->SetRectangularGridValues(XOrigin, YOrigin, XStep, YStep, Rotation);
		viewer->SetRectangularGridGraphicValues(XSize, YSize, Offset);
		viewer->ActivateGrid(Aspect_GT_Rectangular, Aspect_GDM_Lines);
	}
#else
	// grid for demo
	{
		gp_Pnt p(0, 0, 0);
		gp_Vec v(0, 0, 1);
		gp_Ax3 ax(p, v);
		Quantity_Length XOrigin = 0;
		Quantity_Length YOrigin = 0;
		Quantity_Length XStep = 10;
		Quantity_Length YStep = 10;
		Quantity_Length Rotation = 0;
		Quantity_Length XSize = XStep * 40 + 1.0e-7;
		Quantity_Length YSize = YStep * 10 + 1.0e-7;
		Quantity_Length Offset = 0;
		viewer->SetPrivilegedPlane(ax);
		viewer->SetRectangularGridValues(XOrigin, YOrigin, XStep, YStep, Rotation);
		viewer->SetRectangularGridGraphicValues(XSize, YSize, Offset);
		viewer->ActivateGrid(Aspect_GT_Rectangular, Aspect_GDM_Lines);
	}
#endif

	aiscxt->UpdateCurrentViewer();

	return true;
}

void OCCViewer::SetHighlightColor(Quantity_NameOfColor color)
{
	aiscxt->SetHilightColor(color);
	return;
}

void OCCViewer::SetSelectionColor(Quantity_NameOfColor color)
{
	aiscxt->SelectionColor(color);
	return;
}

void OCCViewer::MustBeResized(void)
{
	if (!view.IsNull())
		view->MustBeResized();
}

void OCCViewer::Redraw(void)
{
	if (!view.IsNull())
		view->Redraw();
}

void OCCViewer::Redraw(int x, int y, int w, int h)
{
	if (!view.IsNull())
		view->Redraw(x, y, w, h);
}

void OCCViewer::UpdateCurrentViewer(void)
{
	if (!aiscxt.IsNull())
		aiscxt->UpdateCurrentViewer();
}

void OCCViewer::SetAntialiasing(bool isOn)
{
	if (!view.IsNull()) {
		if (isOn)
		    view->SetAntialiasingOn();
		else
		    view->SetAntialiasingOff();
	}
}

void OCCViewer::SetComputedMode(bool value)
{
	if (!view.IsNull())
		view->SetComputedMode(value ? Standard_True : Standard_False);
}

void OCCViewer::WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax)
{
	if (!view.IsNull())
		view->WindowFitAll(Xmin, Ymin, Xmax, Ymax);
}

void OCCViewer::Zoom(int x1, int y1, int x2, int y2)
{
	if (!view.IsNull())
		view->Zoom(x1, y1, x2, y2);
}

void OCCViewer::Pan(int x, int y)
{
	if (!view.IsNull())
		view->Pan(x, y);
}

void OCCViewer::Rotation(int x, int y)
{
	if (!view.IsNull())
		view->Rotation(x, y);
}

void OCCViewer::StartRotation(int x, int y)
{
	if (!view.IsNull())
		view->StartRotation(x, y);
}

void OCCViewer::Select(int x1, int y1, int x2, int y2)
{
	if (!aiscxt.IsNull()) {
		aiscxt->Select(x1, y1, x2, y2, view);
	}

}

void OCCViewer::Select(void)
{
	if (!aiscxt.IsNull()) {
		aiscxt->Select();
	}
}

void OCCViewer::MoveTo(int x, int y)
{
	if ((!aiscxt.IsNull()) && (!view.IsNull()))
		aiscxt->MoveTo(x, y, view);
}

void OCCViewer::ShiftSelect(int x1, int y1, int x2, int y2)
{
	if ((!aiscxt.IsNull()) && (!view.IsNull())) {
		aiscxt->ShiftSelect(x1, y1, x2, y2, view);
	}
}

void OCCViewer::ShiftSelect(void)
{
	if (!aiscxt.IsNull()) {
		aiscxt->ShiftSelect();
	}
}

void OCCViewer::setProjection(V3d_TypeOfOrientation dir)
{
	if (!view.IsNull()) {	
		view->SetProj(dir); 
	}
}

void OCCViewer::ZoomAllView(void)
{
	if (!view.IsNull()) {
		view->FitAll();
		view->ZFitAll();
	}
}

void OCCViewer::ZFitAll(void)
{
    if (!view.IsNull())
        view->ZFitAll();
}

float OCCViewer::Scale(void)
{
	if (view.IsNull())
		return -1;
	else
		return (float)view->Scale();
}

void OCCViewer::setScale(double f)
{
	if (!view.IsNull())
		view->SetScale((Quantity_Factor)f);
}

void OCCViewer::ResetView(void)
{
	if (!view.IsNull())
		view->Reset();
}

void OCCViewer::SetDisplayMode(int aMode)
{
	if (aiscxt.IsNull())
		return;
	AIS_DisplayMode CurrentMode;
	if (aMode == 0) 
		CurrentMode=AIS_WireFrame;
	else
		CurrentMode=AIS_Shaded;
    if(aiscxt->NbCurrents()==0 || aiscxt->NbSelected()==0)
       aiscxt->SetDisplayMode(CurrentMode);
    else 
	{
       for(aiscxt->InitCurrent();aiscxt->MoreCurrent();aiscxt->NextCurrent())
	           aiscxt->SetDisplayMode(aiscxt->Current(),aMode,Standard_False);
	         
	}
	 aiscxt->UpdateCurrentViewer();
}

void OCCViewer::ObjectColor(int& r, int& g, int& b)
{
	if (aiscxt.IsNull())
		return;
	r = 255;
	g = 255;
	b = 255;
	Handle_AIS_InteractiveObject Current ;
	Quantity_Color ObjCol;
	aiscxt->InitCurrent();
	if (!aiscxt->MoreCurrent())
		return;
    Current = aiscxt->Current();
	if (Current->HasColor()) {
      ObjCol = aiscxt->Color(aiscxt->Current());
	  Quantity_Parameter r1, r2, r3;
	  ObjCol.Values(r1, r2, r3, Quantity_TOC_RGB);
		r = (int)r1*255;
		g = (int)r2*255;
		b = (int)r3*255;
  	}
}

/*
bool OCCViewer::ImportStep(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	Standard_CString aFileName = (Standard_CString) fname;
	STEPControl_Reader aReader;
	IFSelect_ReturnStatus status = aReader.ReadFile(aFileName);
	if (status == IFSelect_RetDone)
    {
	    bool failsonly = false;
	    aReader.PrintCheckLoad(failsonly, IFSelect_ItemsByEntity);

	    int nbr = aReader.NbRootsForTransfer();
	    aReader.PrintCheckTransfer(failsonly, IFSelect_ItemsByEntity);
	    for (Standard_Integer n = 1; n <= nbr; n++)
	    {
	        Standard_Boolean ok = aReader.TransferRoot(n);
	        int nbs = aReader.NbShapes();
	        if (nbs > 0)
            {
	            for (int i = 1; i <= nbs; i++)
                {
		            TopoDS_Shape shape = aReader.Shape(i);
		            aiscxt->Display(new AIS_Shape(shape));
	            }
            }
        }
	} else
		return false;
	return true;
}

bool OCCViewer::ExportStep(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
    STEPControl_StepModelType type = STEPControl_AsIs;
    IFSelect_ReturnStatus status;
    STEPControl_Writer writer;
	for (aiscxt->InitCurrent(); aiscxt->MoreCurrent(); aiscxt->NextCurrent())
    {
		Handle_AIS_InteractiveObject anIO = aiscxt->Current();
		Handle_AIS_Shape anIS=Handle_AIS_Shape::DownCast(anIO);
		TopoDS_Shape shape = anIS->Shape();
		status = writer.Transfer(shape , type);
        if (status != IFSelect_RetDone)
            return false;
    }

    status = writer.Write((Standard_CString)fname);
    if (status != IFSelect_RetDone)
            return false;
	return true;
}
*/
bool OCCViewer::IsObjectSelected(void)
{
	if (aiscxt.IsNull())
		return false;
	aiscxt->InitCurrent();
	return (bool)aiscxt->MoreCurrent();
}

int OCCViewer::NbSelected(void)
{
	if (aiscxt.IsNull())
		return false;
    aiscxt->UpdateSelected(Standard_False);
    return (int)aiscxt->NbSelected();
}

int OCCViewer::DisplayMode(void)
{
	if (aiscxt.IsNull())
		return -1;
	int mode = -1;
	bool OneOrMoreInShading=false;
	bool OneOrMoreInWireframe=false;
	for (aiscxt->InitCurrent(); aiscxt->MoreCurrent(); aiscxt->NextCurrent())
	{
		if (aiscxt->IsDisplayed(aiscxt->Current(), 1))
             OneOrMoreInShading = true;
        if (aiscxt->IsDisplayed(aiscxt->Current(), 0))
             OneOrMoreInWireframe = true;
	}
	if (OneOrMoreInShading&&OneOrMoreInWireframe)
		mode=10;
	else if(OneOrMoreInShading)
		mode=1;
	else if (OneOrMoreInWireframe)
		mode=0;
	return mode;
}

void OCCViewer::CreateNewView(void* wnd, bool grad, bool is_raytracing)
{
	if (aiscxt.IsNull())
		return;
	view = aiscxt->CurrentViewer()->CreateView();
	if (myGraphicDriver.IsNull())
    {
      Handle(Aspect_DisplayConnection) aDisplayConnection;
      myGraphicDriver = Graphic3d::InitGraphicDriver(aDisplayConnection);
    }
	Handle(WNT_Window) aWNTWindow = new WNT_Window(reinterpret_cast<HWND> (wnd));
	view->SetWindow(aWNTWindow);
	Standard_Integer w = 100, h = 100;
	aWNTWindow->Size(w,h);
	if (!aWNTWindow->IsMapped()) 
		 aWNTWindow->Map();
    initViewAppearance(grad, is_raytracing, false, false, false);
}

bool OCCViewer::SetAISContext(OCCViewer* Viewer)
{
	aiscxt = Viewer->GetAISContext();
	if (aiscxt.IsNull())
		return false;
	return true;
}

Handle_AIS_InteractiveContext OCCViewer::GetAISContext(void)
{
	return aiscxt;
}

int OCCViewer::CharToInt(char symbol)
{
	TCollection_AsciiString msg = symbol;
	return msg.IntegerValue();
}

bool OCCViewer::xy2xyz(int Xs, int Ys, double& X, double& Y, double& Z, bool usePrecision)
{
	Standard_Real myPrecision = 1.0;
    Standard_Real Xp = Xs, Yp = Ys;
    Standard_Real Xv, Yv, Zv;
    Standard_Real Vx, Vy, Vz;

    gp_Pln aPlane(view->Viewer()->PrivilegedPlane());
    view->Convert((Standard_Integer)Xp, (Standard_Integer)Yp, Xv, Yv, Zv);
    view->Proj(Vx, Vy, Vz);
    gp_Lin aLine(gp_Pnt(Xv, Yv, Zv), gp_Dir(Vx, Vy, Vz));
    IntAna_IntConicQuad intersec(aLine, aPlane, Precision::Angular());

    if (!intersec.IsDone())
		return false;
    if (intersec.IsParallel() || !intersec.NbPoints())
		return false;

    gp_Pnt p(intersec.Point(1));
    X = p.X();
    Y = p.Y();
    Z = p.Z();

    if (usePrecision) {
         X = (X < 0. ? -1 : (X > 0. ? 1 : 0.)) * floor((abs(X)) / myPrecision) * myPrecision;
         Y = (Y < 0. ? -1 : (Y > 0. ? 1 : 0.)) * floor((abs(Y)) / myPrecision) * myPrecision;
         Z = (Z < 0. ? -1 : (Z > 0. ? 1 : 0.)) * floor((abs(Z)) / myPrecision) * myPrecision;
    }

    return true;
}
