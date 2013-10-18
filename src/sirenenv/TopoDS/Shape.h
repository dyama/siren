#pragma once
#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>

namespace topo
{

public ref class Shape
{
public:
    TopoDS_Shape* org;
public:
    Shape() { org = new TopoDS_Shape(); }
    ~Shape() { delete(org); }
    Shape(Shape% src)
    {
        *org = *src.org;
    }
};

}