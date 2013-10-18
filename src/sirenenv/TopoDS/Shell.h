#pragma once
#include "Shape.h"
#include <TopoDS_Shell.hxx>

namespace topo
{


public ref class Shell : Shape
{
public:
    Shell() { org = new TopoDS_Shell(); }

};


}