/**
 * \brief Command definitions
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stdafx.h"

// General commands
mrb_value help        (mrb_state*, mrb_value);
mrb_value version     (mrb_state*, mrb_value);
mrb_value debug       (mrb_state*, mrb_value);
mrb_value all         (mrb_state*, mrb_value);
mrb_value init        (mrb_state*, mrb_value);

mrb_value selmode     (mrb_state*, mrb_value);

// Information/Status 
mrb_value exist       (mrb_state*, mrb_value);
mrb_value location    (mrb_state*, mrb_value);
mrb_value type        (mrb_state*, mrb_value);
mrb_value bndbox      (mrb_state*, mrb_value);
mrb_value selected    (mrb_state*, mrb_value);
mrb_value cparam      (mrb_state*, mrb_value);
mrb_value cpoint      (mrb_state*, mrb_value);
mrb_value ccurvature  (mrb_state*, mrb_value);
mrb_value ctangent    (mrb_state*, mrb_value);

// group
mrb_value compound    (mrb_state*, mrb_value);
mrb_value sew         (mrb_state*, mrb_value);
mrb_value explode     (mrb_state*, mrb_value);

// Edit
mrb_value erase       (mrb_state*, mrb_value);
mrb_value copy        (mrb_state*, mrb_value);
mrb_value close       (mrb_state*, mrb_value);

// Transform
mrb_value translate   (mrb_state*, mrb_value);
mrb_value rotate      (mrb_state*, mrb_value);
mrb_value scale       (mrb_state*, mrb_value);
mrb_value mirror      (mrb_state*, mrb_value);

// Boolean
mrb_value common      (mrb_state*, mrb_value);
mrb_value cut         (mrb_state*, mrb_value);
mrb_value fuse        (mrb_state*, mrb_value);
mrb_value volume      (mrb_state*, mrb_value);
mrb_value cog         (mrb_state*, mrb_value);
mrb_value area        (mrb_state*, mrb_value);
mrb_value intersect   (mrb_state*, mrb_value);
mrb_value split       (mrb_state*, mrb_value);
mrb_value intcs       (mrb_state*, mrb_value);
mrb_value intfe       (mrb_state*, mrb_value);
mrb_value isin        (mrb_state*, mrb_value);

// Premitive
mrb_value vertex      (mrb_state*, mrb_value);
mrb_value line        (mrb_state*, mrb_value);
mrb_value polyline    (mrb_state*, mrb_value);
mrb_value arc         (mrb_state*, mrb_value);
mrb_value curve       (mrb_state*, mrb_value);
mrb_value box         (mrb_state*, mrb_value);
mrb_value cylinder    (mrb_state*, mrb_value);
mrb_value cone        (mrb_state*, mrb_value);
mrb_value sphere      (mrb_state*, mrb_value);
mrb_value torus       (mrb_state*, mrb_value);
mrb_value plane       (mrb_state*, mrb_value);
mrb_value polygon     (mrb_state*, mrb_value);
mrb_value wire	      (mrb_state*, mrb_value);
mrb_value sweepv      (mrb_state*, mrb_value);
mrb_value sweepp      (mrb_state*, mrb_value);
mrb_value loft        (mrb_state*, mrb_value);
mrb_value bscurve     (mrb_state*, mrb_value);
mrb_value bzsurf      (mrb_state*, mrb_value);
mrb_value bssurf      (mrb_state*, mrb_value);
mrb_value offset      (mrb_state*, mrb_value);
mrb_value thick       (mrb_state*, mrb_value);
mrb_value projw       (mrb_state*, mrb_value);

// Convertion
mrb_value wire2pts    (mrb_state*, mrb_value);
mrb_value wire2face   (mrb_state*, mrb_value);
mrb_value shell2solid (mrb_state*, mrb_value);
mrb_value triangle    (mrb_state*, mrb_value);
mrb_value contour     (mrb_state*, mrb_value);

// I/O
mrb_value savebrep    (mrb_state*, mrb_value);
mrb_value loadbrep    (mrb_state*, mrb_value);
mrb_value saveiges    (mrb_state*, mrb_value);
mrb_value loadiges    (mrb_state*, mrb_value);
mrb_value savestep    (mrb_state*, mrb_value);
mrb_value loadstep    (mrb_state*, mrb_value);
mrb_value loadstl     (mrb_state*, mrb_value);
mrb_value savestl     (mrb_state*, mrb_value);
mrb_value savestl     (mrb_state*, mrb_value);
mrb_value savevrml    (mrb_state*, mrb_value);

// Visualization
mrb_value fit         (mrb_state*, mrb_value);
mrb_value update      (mrb_state*, mrb_value);
mrb_value redraw      (mrb_state*, mrb_value);
mrb_value display     (mrb_state*, mrb_value);
mrb_value hide        (mrb_state*, mrb_value);
mrb_value color       (mrb_state*, mrb_value);
mrb_value material    (mrb_state*, mrb_value);
mrb_value bgcolor     (mrb_state*, mrb_value);
mrb_value transparency(mrb_state*, mrb_value);
mrb_value select      (mrb_state*, mrb_value);
mrb_value clipon      (mrb_state*, mrb_value);
mrb_value clipoff     (mrb_state*, mrb_value);
mrb_value activate    (mrb_state*, mrb_value);
mrb_value dump        (mrb_state*, mrb_value);
mrb_value reset       (mrb_state*, mrb_value);

#endif // _COMMAND_H_
