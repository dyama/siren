#pragma once
#include "Shape.h"
#include <TopoDS_Edge.hxx>

namespace topo
{

public ref class Edge : Shape
{
public:
    Edge() { org = new TopoDS_Edge(); }

};
}