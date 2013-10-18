#pragma once
#include "Shape.h"
#include <TopoDS_Wire.hxx>

namespace topo
{

public ref class Wire : Shape
{
public:
    Wire() { org = new TopoDS_Wire(); }

};

}