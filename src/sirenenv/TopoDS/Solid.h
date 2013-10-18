#pragma once
#include "Shape.h"
#include <TopoDS_Solid.hxx>

namespace topo
{

public ref class Solid : Shape
{
public:
    Solid() { org = new TopoDS_Solid(); }

};

}