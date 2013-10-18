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