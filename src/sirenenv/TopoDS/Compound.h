#pragma once
#include "Shape.h"
#include <TopoDS_Compound.hxx>

namespace topo
{

public ref class Compound : Shape
{
public:
    Compound() { org = new TopoDS_Compound(); }

};

}