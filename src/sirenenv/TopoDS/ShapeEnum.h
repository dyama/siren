/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once
#include <TopAbs_ShapeEnum.hxx>

namespace topo
{
    public enum class ShapeEnum
    {
        COMPOUND  = 0,
        COMPSOLID = 1,
        SOLID     = 2,
        SHELL     = 3,
        FACE      = 4,
        WIRE      = 5,
        EDGE      = 6,
        VERTEX    = 7,
        SHAPE     = 8
    };
}
