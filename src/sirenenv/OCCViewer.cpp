/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "StdAfx.h"
#include "OCCViewer.h"

#pragma warning(disable : 4800)
OCCViewer::OCCViewer(void)
{
	myGraphicDriver = NULL;
	myViewer = NULL;
	myView = NULL;
	myAISContext = NULL;
}

OCCViewer::~OCCViewer(void)
{
	myView->Remove();
	mruby_cleenup();
}

void OCCViewer::initViewAppearance()
{

	// Show trihedron on 3d viewer
    myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_WHITE, 0.1, V3d_ZBUFFER);

	// Background color
	myView->SetBgGradientStyle(Aspect_GFM_VER);
    Quantity_Color color1(0., 0.0, 0.25, Quantity_TOC_RGB);
    Quantity_Color color2(0., 0.4, 0.60, Quantity_TOC_RGB);
    // myView->SetBackgroundColor(Quantity_TOC_RGB, R, G, B);
    myView->SetBgGradientColors(color1, color2);

    // Depth-cueing (‹ó‹C‰“‹ß–@)‚Ì—LŒø‰»
 	//myView->SetZCueingOn();

	// Viewpoint control
	myView->SetAt(0.0, 0.0, 0.0);
	myView->SetEye(-1, -1, 1);
	myView->SetScale(5.0);
	myView->SetUp(0.0, 0.0, 1.0);
	myView->SetCenter(0.0, 0.0);

#if 0
	// test for layer
	Handle(Visual3d_Layer) lay
		= new Visual3d_Layer(myViewer->Viewer(), Aspect_TOL_OVERLAY, Standard_False);
	lay->Clear();
	lay->Begin();
		lay->SetViewport(800, 600);
		lay->SetTransparency(0.5);
		lay->BeginPolygon();
			lay->SetColor(Quantity_Color(1., 1., 1., Quantity_TOC_RGB));
			lay->AddVertex(.95, -.9);
			lay->AddVertex(.95, -.95);
			lay->AddVertex(.8, -.95);
			lay->AddVertex(.8, -.9);
			lay->AddVertex(.95, -.9);
		lay->ClosePrimitive();
		lay->BeginPolyline();
			lay->SetColor(Quantity_Color(1., 1., 1., Quantity_TOC_RGB));
			lay->AddVertex(-.95, .9);
			lay->AddVertex(-.95, -.5);
			lay->AddVertex(-.8, -.5);
			lay->AddVertex(-.8, .9);
			lay->AddVertex(-.95, .9);
		lay->ClosePrimitive();
		lay->DrawText((Standard_CString)"siren", 0, 0, 120);
		//
	lay->End();
#endif

	//myView->SetTransparency();

	// Enable ray tracing mode
	myView->SetRaytracingMode();
	myView->SetRasterizationMode(); // OpenGL rasterize rennaring mode
	myView->EnableRaytracedShadows();
	myView->EnableRaytracedAntialiasing();
	myView->EnableRaytracedReflections();

	//myView->Redraw();
	//myView->SetAntialiasingOn();

	myView->FitAll();
    myView->Update();
}

bool OCCViewer::InitViewer(void* wnd)
{
	// init graphic driver
    try {
        Handle(Aspect_DisplayConnection) aDisplayConnection;
        myGraphicDriver = Graphic3d::InitGraphicDriver (aDisplayConnection);
    }
    catch (Standard_Failure) {
        return false;
    }

	// init viewer
    TCollection_ExtendedString a3DName("Visu3D");
    myViewer = new V3d_Viewer (myGraphicDriver, a3DName.ToExtString(),"", 1000.0, 
                             V3d_XposYnegZpos, Quantity_NOC_GRAY30,
                             V3d_ZBUFFER,V3d_GOURAUD, V3d_WAIT, 
                             Standard_True, Standard_False);
#if 0
	myViewer->Init();
	myViewer->SetDefaultLights();
	myViewer->SetLightOn();
#else
	myViewer->InitDefinedViews();
	Handle(V3d_DirectionalLight) light = new V3d_DirectionalLight(myViewer, V3d_Zneg);
	//light->Position(V3d_Coodinate(0, 0, 1000);
	light->SetHeadlight(Standard_True);
	myViewer->SetLightOn(light);
#endif


	myViewer->SetDefaultVisualization(V3d_ZBUFFER);
	Standard_Integer aLayerId;
	myViewer->AddZLayer(aLayerId);
	myViewer->SetZBufferManagment(Standard_True);

	// init AIS context and common appearances
	myAISContext = new AIS_InteractiveContext(myViewer);

	// trihedron at origin point
	// Handle(Geom_Axis2Placement) aTrihedronAxis = new Geom_Axis2Placement(gp::XOY());
	// Handle(AIS_Trihedron) aTrihedron = new AIS_Trihedron(aTrihedronAxis);
	// aTrihedron->SetSize(0.5 * 1000);
	// //myAISContext->Display(aTrihedron, 0, -1, Standard_False, Standard_False); 
	// myAISContext->Display(aTrihedron);
	// myAISContext->Deactivate(aTrihedron);

	// highlight color, selection color
    myAISContext->SetHilightColor(Quantity_NOC_YELLOW);
	myAISContext->SelectionColor(Quantity_NOC_RED);

	Handle(OpenGl_GraphicDriver) aDriver
		= Handle(OpenGl_GraphicDriver)::DownCast(myViewer->Driver());
	aDriver->ChangeOptions().vboDisable = Standard_False;
		
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
		Quantity_Length XSize = XStep * 10 + 1.0e-7;
		Quantity_Length YSize = YStep * 10 + 1.0e-7;
		Quantity_Length Offset = 0;
		myViewer->SetPrivilegedPlane(ax);
		myViewer->SetRectangularGridValues(XOrigin, YOrigin, XStep, YStep, Rotation);
		myViewer->SetRectangularGridGraphicValues(XSize, YSize, Offset);
		myViewer->ActivateGrid(Aspect_GT_Rectangular, Aspect_GDM_Lines);
	}

	// init current view
#ifdef PARSEPECTIVE
	myView = new V3d_PerspectiveView(myViewer);
#else
	myView = myViewer->CreateView();
#endif
	Handle(WNT_Window) aWNTWindow = new WNT_Window (reinterpret_cast<HWND> (wnd));
	myView->SetWindow(aWNTWindow);
	if (!aWNTWindow->IsMapped()) 
		 aWNTWindow->Map();
	initViewAppearance();
	myView->Redraw();
	myView->MustBeResized();
	myAISContext->UpdateCurrentViewer();

	mruby_init();

	return true;
}

void OCCViewer::SetHighlightColor(Quantity_NameOfColor color)
{
	myAISContext->SetHilightColor(color);
	return;
}

void OCCViewer::SetSelectionColor(Quantity_NameOfColor color)
{
	myAISContext->SelectionColor(color);
	return;
}

void OCCViewer::UpdateView(void)
{
	if (!myView.IsNull())
		myView->MustBeResized();
}

void OCCViewer::RedrawView(void)
{
	if (!myView.IsNull())
		myView->Redraw();
}

void OCCViewer::SetAntialiasing(bool isOn)
{
	if (!myView.IsNull()) {
		if (isOn)
		    myView->SetAntialiasingOn();
		else
		    myView->SetAntialiasingOff();
	}
}

void OCCViewer::SetDegenerateModeOn(void)
{
	if (!myView.IsNull())
		myView->SetComputedMode (Standard_False);
}

void OCCViewer::SetDegenerateModeOff(void)
{
	if (!myView.IsNull())
		myView->SetComputedMode (Standard_True);
}

void OCCViewer::WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax)
{
	if (!myView.IsNull())
		myView->WindowFitAll(Xmin, Ymin, Xmax, Ymax);
}

void OCCViewer::Place(int x, int y, float zoomFactor)
{
	Quantity_Factor aZoomFactor = zoomFactor;
	if (!myView.IsNull())
		myView->Place(x, y, aZoomFactor);
}

void OCCViewer::Zoom(int x1, int y1, int x2, int y2)
{
	if (!myView.IsNull())
		myView->Zoom(x1, y1, x2, y2);
}

void OCCViewer::Pan(int x, int y)
{
	if (!myView.IsNull())
		myView->Pan(x, y);
}

void OCCViewer::Rotation(int x, int y)
{
	if (!myView.IsNull())
		myView->Rotation(x, y);
}

void OCCViewer::StartRotation(int x, int y)
{
	if (!myView.IsNull())
		myView->StartRotation(x, y);
}

void OCCViewer::Select(int x1, int y1, int x2, int y2)
{
	if (!myAISContext.IsNull()) {
		myAISContext->Select(x1, y1, x2, y2, myView);
#ifdef _DEBUG
		myAISContext->InitCurrent();
		for (;myAISContext->MoreCurrent ();myAISContext->NextCurrent ()) {
			Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(myAISContext->Current());
			if (!hashape.IsNull()) {
				TopoDS_Shape shape = hashape->Shape();	
				if (!shape.IsNull()) {
					int t = shape.ShapeType();
					int h = shape.HashCode(INT_MAX);
					printf("hash=%X type=%d\n", h, t);
				}
			}
		}
#endif
	}

}

void OCCViewer::Select(void)
{
	if (!myAISContext.IsNull()) {
		myAISContext->Select();
#ifdef _DEBUG
		myAISContext->InitCurrent();
		for (;myAISContext->MoreCurrent ();myAISContext->NextCurrent ()) {
			Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(myAISContext->Current());
			if (!hashape.IsNull()) {
				TopoDS_Shape shape = hashape->Shape();	
				if (!shape.IsNull()) {
					int t = shape.ShapeType();
					int h = shape.HashCode(INT_MAX);
					printf("hash=%X type=%d\n", h, t);
				}
			}
		}
#endif
	}
}

void OCCViewer::MoveTo(int x, int y)
{
	if ((!myAISContext.IsNull()) && (!myView.IsNull()))
		myAISContext->MoveTo(x, y, myView);
}

void OCCViewer::ShiftSelect(int x1, int y1, int x2, int y2)
{
	if ((!myAISContext.IsNull()) && (!myView.IsNull())) {
		myAISContext->ShiftSelect(x1, y1, x2, y2, myView);
#ifdef _DEBUG
		myAISContext->InitCurrent();
		for (;myAISContext->MoreCurrent ();myAISContext->NextCurrent ()) {
			Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(myAISContext->Current());
			if (!hashape.IsNull()) {
				TopoDS_Shape shape = hashape->Shape();	
				if (!shape.IsNull()) {
					int t = shape.ShapeType();
					int h = shape.HashCode(INT_MAX);
					printf("hash=%X type=%d\n", h, t);
				}
			}
		}
#endif
	}
}

void OCCViewer::ShiftSelect(void)
{
	if (!myAISContext.IsNull()) {
		myAISContext->ShiftSelect();
#ifdef _DEBUG
		myAISContext->InitCurrent();
		for (;myAISContext->MoreCurrent ();myAISContext->NextCurrent ()) {
			Handle(AIS_Shape) hashape = Handle(AIS_Shape)::DownCast(myAISContext->Current());
			if (!hashape.IsNull()) {
				TopoDS_Shape shape = hashape->Shape();	
				if (!shape.IsNull()) {
					int t = shape.ShapeType();
					int h = shape.HashCode(INT_MAX);
					printf("hash=%X type=%d\n", h, t);
				}
			}
		}
#endif
	}
}

void OCCViewer::BackgroundColor(int& r, int& g, int& b)
{
	Standard_Real R1;
	Standard_Real G1;
	Standard_Real B1;
	if (!myView.IsNull())
		myView->BackgroundColor(Quantity_TOC_RGB,R1,G1,B1);
	r = (int)R1*255;
	g = (int)G1*255;
	b = (int)B1*255;
}

void OCCViewer::UpdateCurrentViewer(void)
{
	if (!myAISContext.IsNull())
		myAISContext->UpdateCurrentViewer();
}

void OCCViewer::setProjection(V3d_TypeOfOrientation dir)
{
	if (!myView.IsNull()) {	
		myView->SetProj(dir); 
	}
}

void OCCViewer::ZoomAllView(void)
{
	if (!myView.IsNull())
	{
		myView->FitAll();
		myView->ZFitAll();
	}
}

float OCCViewer::Scale(void)
{
	if (myView.IsNull())
		return -1;
	else
		return (float)myView->Scale();
}

void OCCViewer::setScale(double f)
{
	if (!myView.IsNull())
		myView->SetScale((Quantity_Factor)f);
}

void OCCViewer::ResetView(void)
{
	if (!myView.IsNull())
		myView->Reset();
}

void OCCViewer::SetDisplayMode(int aMode)
{
	if (myAISContext.IsNull())
		return;
	AIS_DisplayMode CurrentMode;
	if (aMode == 0) 
		CurrentMode=AIS_WireFrame;
	else
		CurrentMode=AIS_Shaded;
    if(myAISContext->NbCurrents()==0 || myAISContext->NbSelected()==0)
       myAISContext->SetDisplayMode(CurrentMode);
    else 
	{
       for(myAISContext->InitCurrent();myAISContext->MoreCurrent();myAISContext->NextCurrent())
	           myAISContext->SetDisplayMode(myAISContext->Current(),aMode,Standard_False);
	         
	}
	 myAISContext->UpdateCurrentViewer();
}

void OCCViewer::SetColor(int r, int g, int b)
{
	if (myAISContext.IsNull())
		return;
	Quantity_Color col =  Quantity_Color(r/255.,g/255.,b/255.,Quantity_TOC_RGB);
	for (;myAISContext->MoreCurrent ();myAISContext->NextCurrent ())
	          myAISContext->SetColor (myAISContext->Current(),col.Name());
}

void OCCViewer::ObjectColor(int& r, int& g, int& b)
{
	if (myAISContext.IsNull())
		return;
	r = 255;
	g = 255;
	b = 255;
	Handle_AIS_InteractiveObject Current ;
	Quantity_Color ObjCol;
	myAISContext->InitCurrent();
	if (!myAISContext->MoreCurrent())
		return;
    Current = myAISContext->Current();
	if (Current->HasColor()) {
      ObjCol = myAISContext->Color(myAISContext->Current());
	  Quantity_Parameter r1, r2, r3;
	  ObjCol.Values(r1, r2, r3, Quantity_TOC_RGB);
		r = (int)r1*255;
		g = (int)r2*255;
		b = (int)r3*255;
  	}
}

void OCCViewer::SetBackgroundColor(int r, int g, int b)
{
	if (!myView.IsNull())
		myView->SetBackgroundColor(Quantity_TOC_RGB,r/255.,g/255.,b/255.);
}

void OCCViewer::EraseObjects(void)
{
	if (myAISContext.IsNull())
		return;
	for(myAISContext->InitCurrent();myAISContext->MoreCurrent();myAISContext->NextCurrent())
        myAISContext->Erase(myAISContext->Current(),Standard_True);
	myAISContext->ClearCurrents();
}

float OCCViewer::GetVersion(void)
{
	return (float)OCC_VERSION;
}

void OCCViewer::SetMaterial(int theMaterial)
{
	if (myAISContext.IsNull())
		return;
    for (myAISContext->InitCurrent(); myAISContext->MoreCurrent (); myAISContext->NextCurrent ())
        myAISContext->SetMaterial(myAISContext->Current(), (Graphic3d_NameOfMaterial)theMaterial);
	myAISContext->UpdateCurrentViewer();
}

void OCCViewer::SetTransparency(int theTrans)
{
	if (myAISContext.IsNull())
		return;
	for(myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextSelected())
		myAISContext->SetTransparency(myAISContext->Current(), ((Standard_Real)theTrans) / 10.0);
}

bool OCCViewer::ImportBRep(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	Standard_CString aFileName = (Standard_CString) fname;
	TopoDS_Shape aShape;
    BRep_Builder aBuilder;
    Standard_Boolean result = BRepTools::Read(aShape,aFileName,aBuilder);
	if (!result)
		return false;
	if(myAISContext->HasOpenedContext())
		myAISContext->CloseLocalContext();
	myAISContext->Display(new AIS_Shape(aShape));
	return true;
}

bool OCCViewer::ImportCsfdb(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}

	Standard_CString aFileName = (Standard_CString) fname;
    if (FSD_File::IsGoodFileType(aFileName) != Storage_VSOk)
	    return false;

    static FSD_File fileDriver;
    TCollection_AsciiString aName(aFileName);
    if (fileDriver.Open(aName, Storage_VSRead) != Storage_VSOk)
        return false;

    Handle(ShapeSchema) schema = new ShapeSchema();
    Handle(Storage_Data) data  = schema->Read(fileDriver);
    if (data->ErrorStatus() != Storage_VSOk)
        return false;
    fileDriver.Close();

    Handle(Storage_HSeqOfRoot) roots = data->Roots();
    for (int i = 1; i <= roots->Length() ; i++)
    {
        Handle(Storage_Root) r = roots->Value(i);
        Handle(Standard_Persistent) p = r->Object();
        Handle(PTopoDS_HShape) aPShape = Handle(PTopoDS_HShape)::DownCast(p);
        if (!aPShape.IsNull())
        {
	        PTColStd_PersistentTransientMap aMap;
	        TopoDS_Shape aTShape;
            MgtBRep::Translate(aPShape, aMap, aTShape, MgtBRep_WithTriangle);
			myAISContext->Display(new AIS_Shape(aTShape));
        }
    }

	return true;
}

bool OCCViewer::ImportIges(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	Standard_CString aFileName = (Standard_CString)fname; // filename;
    IGESControl_Reader Reader;
    int status = Reader.ReadFile(aFileName);

    if (status == IFSelect_RetDone)
    {
        Reader.TransferRoots();
        TopoDS_Shape aShape = Reader.OneShape();
        myAISContext->Display(new AIS_Shape(aShape));
    } else
		return false;
	myAISContext->UpdateCurrentViewer();
	return true;
}

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
		            myAISContext->Display(new AIS_Shape(shape));
	            }
            }
        }
	} else
		return false;
	return true;
}

bool OCCViewer::ExportBRep(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	myAISContext->InitCurrent();
	if (!myAISContext->MoreCurrent())
		return false;
	Handle_AIS_InteractiveObject anIO = myAISContext->Current();
	Handle_AIS_Shape anIS=Handle_AIS_Shape::DownCast(anIO);
	return (bool)BRepTools::Write(anIS->Shape(), (Standard_CString)fname);
}


bool OCCViewer::ExportIges(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	IGESControl_Controller::Init();
	IGESControl_Writer writer(Interface_Static::CVal("XSTEP.iges.unit"),
                               Interface_Static::IVal("XSTEP.iges.writebrep.mode"));
 
	for (myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextCurrent())
	{
		Handle_AIS_InteractiveObject anIO = myAISContext->Current();
		Handle_AIS_Shape anIS=Handle_AIS_Shape::DownCast(anIO);
		TopoDS_Shape shape = anIS->Shape();
		writer.AddShape (shape);
	}
	writer.ComputeModel();
	return (bool)writer.Write((Standard_CString)fname);
}

bool OCCViewer::ExpotStep(wchar_t* filename)
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
	for (myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextCurrent())
    {
		Handle_AIS_InteractiveObject anIO = myAISContext->Current();
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

bool OCCViewer::ExportStl(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	TopoDS_Compound comp;
	BRep_Builder builder;
	builder.MakeCompound(comp);

	for (myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextCurrent())
	{
		Handle_AIS_InteractiveObject anIO = myAISContext->Current();
		Handle_AIS_Shape anIS=Handle_AIS_Shape::DownCast(anIO);
		TopoDS_Shape shape = anIS->Shape();
		if (shape.IsNull()) 
			return false;    
		builder.Add(comp, shape);
	}

	StlAPI_Writer writer;
	writer.Write(comp, (Standard_CString)fname);
	return true;
}

bool OCCViewer::ExportVrml(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	TopoDS_Compound res;
	BRep_Builder builder;
	builder.MakeCompound(res);

	for (myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextCurrent())
	{
		Handle_AIS_InteractiveObject anIO = myAISContext->Current();
		Handle_AIS_Shape anIS=Handle_AIS_Shape::DownCast(anIO);
		TopoDS_Shape shape = anIS->Shape();
		if (shape.IsNull())
			return false;
        
		builder.Add(res, shape);
	}

	VrmlAPI_Writer writer;
	writer.Write(res, (Standard_CString)fname);

	return true;
}

bool OCCViewer::Dump(wchar_t* filename)
{
    char fname[_MAX_PATH];
	{
		setlocale(LC_CTYPE, "");
	    size_t len;
	    wcstombs_s(&len, fname, _MAX_PATH, filename, _MAX_PATH);
	}
	if (myView.IsNull())
		return false;
	myView->Redraw();
    return (bool)myView->Dump((Standard_CString)fname);
}

bool OCCViewer::IsObjectSelected(void)
{
	if (myAISContext.IsNull())
		return false;
	myAISContext->InitCurrent();
	return (bool)myAISContext->MoreCurrent();
}

int OCCViewer::DisplayMode(void)
{
	if (myAISContext.IsNull())
		return -1;
	int mode = -1;
	bool OneOrMoreInShading=false;
	bool OneOrMoreInWireframe=false;
	for (myAISContext->InitCurrent(); myAISContext->MoreCurrent(); myAISContext->NextCurrent())
	{
		if (myAISContext->IsDisplayed(myAISContext->Current(), 1))
             OneOrMoreInShading = true;
        if (myAISContext->IsDisplayed(myAISContext->Current(), 0))
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

void OCCViewer::CreateNewView(void* wnd)
{
	if (myAISContext.IsNull())
		return;
	myView = myAISContext->CurrentViewer()->CreateView();
	if (myGraphicDriver.IsNull())
    {
      Handle(Aspect_DisplayConnection) aDisplayConnection;
      myGraphicDriver = Graphic3d::InitGraphicDriver(aDisplayConnection);
    }
	Handle(WNT_Window) aWNTWindow = new WNT_Window(reinterpret_cast<HWND> (wnd));
	myView->SetWindow(aWNTWindow);
	Standard_Integer w = 100, h = 100;
	aWNTWindow->Size(w,h);
	if (!aWNTWindow->IsMapped()) 
		 aWNTWindow->Map();
	initViewAppearance();
}

bool OCCViewer::SetAISContext(OCCViewer* Viewer)
{
	myAISContext = Viewer->GetAISContext();
	if (myAISContext.IsNull())
		return false;
	return true;
}

Handle_AIS_InteractiveContext OCCViewer::GetAISContext(void)
{
	return myAISContext;
}

int OCCViewer::CharToInt(char symbol)
{
	TCollection_AsciiString msg = symbol;
	return msg.IntegerValue();
}
