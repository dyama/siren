#pragma once
#include "Shape.h"
#include <TopoDS_Face.hxx>

namespace topo
{


public ref class Face : Shape
{
public:
    Face() { org = new TopoDS_Face(); }

};


}