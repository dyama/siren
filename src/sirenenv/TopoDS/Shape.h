/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

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