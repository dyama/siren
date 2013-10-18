#pragma once
#include "Shape.h"
#include <TopoDS_Vertex.hxx>

namespace topo
{

public ref class Vertex : Shape
{
public:
    Vertex() { org = new TopoDS_Vertext(); }

};
}