/**
 * \brief Common functions for mruby commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once

#include "Stdafx.h"
#include "mirb.h"

/* ------------------------------------------ */
// Expanded ruby exception and messages
/* ------------------------------------------ */

inline mrb_value mrb_exc_notexist(mrb_state* mrb)
{
    static const char m[] = "No such specified shape.";
    return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
}
#define checkexist(S) if (S.IsNull()) return mrb_exc_notexist(mrb);
/*
// siren の型チェック機能は非常にゆるく、指定されたものを Explorer でまわしてみて
// 対象の型のものが入っていなければ何もせずに終わる、という方針。
// さらに、TopAbs_ShapeEnum が整数列挙型なのに対し、「Wire または Edge」、という
// 複数条件で判定したい場合の方が多いので、次の関数はほとんど出番がないかも。
inline mrb_value mrb_exc_incorrecttype(mrb_state* mrb, TopAbs_ShapeEnum type)
{
    static const char *m[] = {
        "The type of specified shape is not compound.",
        "The type of specified shape is not compsolid.",
        "The type of specified shape is not solid.",
        "The type of specified shape is not shell.",
        "The type of specified shape is not face.",
        "The type of specified shape is not wire.",
        "The type of specified shape is not edge.",
        "The type of specified shape is not vertex.",
        "Incorrect type of shape specified."
    };
    switch (type) {
    case TopAbs_COMPOUND: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[0], sizeof(m[0]) - 1);
    case TopAbs_COMPSOLID: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[1], sizeof(m[1]) - 1);
    case TopAbs_SOLID: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[2], sizeof(m[2]) - 1);
    case TopAbs_SHELL: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[3], sizeof(m[3]) - 1);
    case TopAbs_FACE: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[4], sizeof(m[4]) - 1);
    case TopAbs_WIRE: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[5], sizeof(m[5]) - 1);
    case TopAbs_EDGE: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[6], sizeof(m[6]) - 1);
    case TopAbs_VERTEX: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[7], sizeof(m[7]) - 1);
    default: return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m[8], sizeof(m[8]) - 1);
    }
}
#define checktype(S,T) if (S.ShapeType() != T) return mrb_exc_incorrecttype(mrb, T);
*/

/* ------------------------------------------ */
// common functions
/* ------------------------------------------ */

double    ar2double (mrb_state* mrb, mrb_value& ary, int index);
gp_Pnt    ar2pnt    (mrb_state* mrb, mrb_value& ary);
gp_Vec    ar2vec    (mrb_state* mrb, mrb_value& ary);
gp_Dir    ar2dir    (mrb_state* mrb, mrb_value& ary);
gp_Ax1    ar2ax1    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
gp_Ax2    ar2ax2    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
gp_Ax3    ar2ax3    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
mrb_value pnt2ar    (mrb_state* mrb, const gp_Pnt& rPnt);
mrb_value vec2ar    (mrb_state* mrb, const gp_Vec& rVec);

int set(const TopoDS_Shape& shape, const mrb_value& self);
void display(const TopoDS_Shape& shape, bool is_active, bool is_shaded);
void unset(int hashcode);

Handle(AIS_Shape) getAISShape(int hashcode);
TopoDS_Shape& getTopoDSShape(int hashcode);
int updateTopoDSShape(int oldhashcode, const TopoDS_Shape& shape);

bool has_object(int hashcode);
void redisplay(const Handle(AIS_Shape)& hashape);
