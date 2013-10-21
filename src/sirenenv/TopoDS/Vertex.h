/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

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