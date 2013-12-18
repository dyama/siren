/**
 * \brief Common functions for mruby commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

// ÉRÉ}ÉìÉhÇé¿ëïÇ∑ÇÈÇΩÇﬂÇÃã§í ä÷êîåQ

#pragma once

#include "Stdafx.h"
#include "mirb.h"

double    ar2double (mrb_state* mrb, mrb_value ary);
gp_Pnt*   ar2pnt    (mrb_state* mrb, mrb_value& ary);
gp_Vec*   ar2vec    (mrb_state* mrb, mrb_value& ary);
gp_Dir*   ar2dir    (mrb_state* mrb, mrb_value& ary);
gp_Ax1*   ar2ax1    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
gp_Ax2*   ar2ax2    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
gp_Ax3*   ar2ax3    (mrb_state* mrb, mrb_value& pos, mrb_value& dir);
mrb_value pnt2ar    (mrb_state* mrb, const gp_Pnt& rPnt);

int set(const TopoDS_Shape& shape);
int set(const TopoDS_Shape& shape, int draw);
void unset(int hashcode);
Handle(AIS_Shape) get(int hashcode);
bool has_object(int hashcode);
void redisplay(const Handle(AIS_Shape)& hashape);
