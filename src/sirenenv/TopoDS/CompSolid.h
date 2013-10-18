#pragma once
#include "Shape.h"
#include <TopoDS_CompSolid.hxx>

namespace topo
{


public ref class CompSolid : Shape
{
public:
    CompSolid() { org = new TopoDS_CompSolid(); }

};


}