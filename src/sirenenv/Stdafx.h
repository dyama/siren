/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

//#include <limits.h>

//standard OCC types
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#pragma warning( disable : 4267 )
#include <Standard_Boolean.hxx>
#include <Standard_CString.hxx>
#include <Standard_Version.hxx>
#include <Standard_Persistent.hxx>
//collections
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <PTColStd_PersistentTransientMap.hxx>
#include <TCollection_AsciiString.hxx>
//for OCC graphic
#include <Aspect_DisplayConnection.hxx>
#include <WNT_Window.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Graphic3d.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
//for object display
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Trihedron.hxx>
#include <AIS_DisplayMode.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_TypeOfVisualization.hxx>
#include <V3d_TypeOfShadingModel.hxx>
#include <V3d_TypeOfUpdate.hxx>
//topology
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
//brep tools
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
#include <MgtBRep.hxx>
//geometry
#include <gp_Ax2.hxx>
#include <Geom_Axis2Placement.hxx>
//csfdb I/E
#include <Message_ProgressIndicator.hxx>
#include <FSD_File.hxx>
#include <ShapeSchema.hxx>
#include <Storage_Data.hxx>
#include <Storage_Error.hxx>
#include <Storage_HSeqOfRoot.hxx>
#include <Storage_Root.hxx>
#include <PTopoDS_HShape.hxx>
#include <PTColStd_TransientPersistentMap.hxx>
// iges I/E
#include <IGESControl_Reader.hxx>
#include <IGESControl_Controller.hxx>
#include <IGESControl_Writer.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Interface_Static.hxx>
//step I/E
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
//for stl export
#include <StlAPI_Writer.hxx>
//for vrml export
#include <VrmlAPI_Writer.hxx>

// for primitive box
#include <BRepPrimAPI_MakeBox.hxx>

// マップコレクション
// #include <TCollection_BasicMap.hxx>
//#include <Draw_VMap.hxx>

//
#pragma comment (lib, "TKernel.lib")
#pragma comment (lib, "PTKernel.lib")
#pragma comment (lib, "TKBO.lib")
#pragma comment (lib, "TKBRep.lib")
#pragma comment (lib, "TKBool.lib")
#pragma comment (lib, "TKG2d.lib")
#pragma comment (lib, "TKG3d.lib")
#pragma comment (lib, "TKGeomAlgo.lib")
#pragma comment (lib, "TKHLR.lib")
#pragma comment (lib, "TKMath.lib")
#pragma comment (lib, "TKPShape.lib")
#pragma comment (lib, "TKPrim.lib")
#pragma comment (lib, "TKService.lib")
#pragma comment (lib, "TKShHealing.lib")
#pragma comment (lib, "TKShapeSchema.lib")
#pragma comment (lib, "TKTopAlgo.lib")
#pragma comment (lib, "TKV3d.lib")
#pragma comment (lib, "TKXSBase.lib")

// FIle I/O
#pragma comment (lib, "TKIGES.lib")     // IGES
#pragma comment (lib, "TKVRML.lib")     // VRML
#pragma comment (lib, "TKSTEP.lib")     // STEP
#pragma comment (lib, "TKSTEP209.lib")  // 
#pragma comment (lib, "TKSTEPAttr.lib") // 
#pragma comment (lib, "TKSTEPBase.lib") // 
#pragma comment (lib, "TKSTL.lib")      // STL

//#pragma comment (lib, "TKDraw.lib")     // DRAW

// mruby
#pragma comment (lib, "libmruby.lib")

// local
#include "colorname.h"

static Handle_AIS_InteractiveContext AISContext;