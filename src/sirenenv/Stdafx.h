/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#ifndef _STDAFX_H_
#define _STDAFX_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
// #include <regex>

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>

//standard OCC types
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#pragma warning( disable : 4267 )
#include <Standard_Boolean.hxx>
#include <Standard_CString.hxx>
#include <Standard_Version.hxx>
#include <Standard_Persistent.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_TypeOfLayer.hxx>

#include <Aspect_TypeOfDisplayText.hxx>

#include <OSD_Path.hxx>

//collections
#include <TCollection.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <PTColStd_PersistentTransientMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_Array2OfPnt.hxx>

//for OCC graphic
#include <Aspect_DisplayConnection.hxx>
#include <WNT_Window.hxx>
#include <Graphic3d.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_NameOfMaterial.hxx>

//for object display
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <V3d_PerspectiveView.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_TypeOfVisualization.hxx>
#include <V3d_TypeOfShadingModel.hxx>
#include <V3d_TypeOfUpdate.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Trihedron.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>
#include <Visual3d_Layer.hxx>
#include <Handle_Visual3d_Layer.hxx>
//topology
#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
//brep tools
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
#include <MgtBRep.hxx>
//geometry
#include <gp_Ax2.hxx>
#include <gp_Ax3.hxx>
#include <gp_Pln.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_OffsetSurface.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GeomAPI_IntCS.hxx>
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
#include <RWStl.hxx>
#include <StlAPI.hxx>
#include <StlAPI_Reader.hxx>
#include <StlAPI_Writer.hxx>
#include <StlMesh.hxx>
#include <StlTransfer.hxx>
//for vrml export
#include <VrmlAPI_Writer.hxx>

// BRep Builder API, Make
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
// BRep Builder API, Modify
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
// BRep Offset API
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
// for primitive
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <BRepPrimAPI_MakeHalfSpace.hxx>

// BRep Algo API
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Section.hxx>

// BRep Feat
#include <BRepFeat_SplitShape.hxx>

#include <TopExp_Explorer.hxx>
#include <BRepBndLib.hxx>
#include <Bnd_Box.hxx>
#include <GCPnts_UniformDeflection.hxx> // wire2pts
#include <BRepAdaptor_Curve.hxx>        // wire2pts
#include <BRepAdaptor_Surface.hxx>
#include <IntAna_IntConicQuad.hxx>

// for volume
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>

// BRep Mesh
#include <BRepMesh.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Poly_Triangulation.hxx>

//Shape fix
#include <ShapeFix_ShapeTolerance.hxx>
#include <ShapeFix_Wire.hxx>

// for wire
#include <ShapeExtend_WireData.hxx>

#include <ShapeAnalysis_Curve.hxx>

// new 
#include <Visual3d_View.hxx>
#include <Visual3d_ViewManager.hxx>
#include <V3d_AmbientLight.hxx>
#include <V3d_DirectionalLight.hxx>
#include <V3d_LayerMgr.hxx>
#include <V3d_LayerMgrPointer.hxx>
#include <V3d_PositionalLight.hxx>
#include <V3d_SpotLight.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>

#include <TopOpeBRep_FaceEdgeIntersector.hxx>

// libraries
#pragma comment (lib, "TKernel.lib")
#pragma comment (lib, "PTKernel.lib")
#pragma comment (lib, "TKBO.lib")
#pragma comment (lib, "TKBRep.lib")
#pragma comment (lib, "TKBool.lib")
#pragma comment (lib, "TKG2d.lib")
#pragma comment (lib, "TKG3d.lib")
#pragma comment (lib, "TKGeomAlgo.lib")
#pragma comment (lib, "TKGeomBase.lib") // for GCPnts_UniformDeflection
#pragma comment (lib, "TKHLR.lib")
#pragma comment (lib, "TKMath.lib")
#pragma comment (lib, "TKMesh.lib")     // for triangulation
#pragma comment (lib, "TKPShape.lib")
#pragma comment (lib, "TKPrim.lib")
#pragma comment (lib, "TKService.lib")
#pragma comment (lib, "TKShHealing.lib")
#pragma comment (lib, "TKShapeSchema.lib")
#pragma comment (lib, "TKTopAlgo.lib")
#pragma comment (lib, "TKV3d.lib")
#pragma comment (lib, "TKXSBase.lib")
#pragma comment (lib, "TKOffset.lib")  //sweep
#pragma comment (lib, "TKFeat.lib")  //sweep
// FIle I/O
#pragma comment (lib, "TKIGES.lib")     // IGES
#pragma comment (lib, "TKVRML.lib")     // VRML
#pragma comment (lib, "TKSTEP.lib")     // STEP
#pragma comment (lib, "TKSTEP209.lib")  // 
#pragma comment (lib, "TKSTEPAttr.lib") // 
#pragma comment (lib, "TKSTEPBase.lib") // 
#pragma comment (lib, "TKSTL.lib")      // STL
// OpenGL
#pragma comment (lib, "TKOpenGL.lib")
// mruby
#pragma comment (lib, "libmruby.lib")

// definitions
#ifndef _MAX_PATH
#define _MAX_PATH 1024
#endif

// local
#include "colorname.h"
#include "material.h"
#include "orientation.h"

#include "help.h"
#include "mirb.h"
#include "common.h"
#include "script/script.h"
#include "command.h"

#include "OCCViewer.h"

// Global/Static varibles
static std::map<std::string, structHelp*> Help;       // Help string map
//static Handle(AIS_InteractiveContext)     AISContext; // Visualization manager
//static Handle(V3d_View)                   View;       // 3D-View
static OCCViewer* cur;

#endif
