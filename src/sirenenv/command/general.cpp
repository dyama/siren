/**
 * \brief General commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief version information
 */
mrb_value version(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

mrb_value debug2(mrb_state* mrb, mrb_value self)
{
    return mrb_fixnum_value(123);
}

/**
 * \brief debug command
 */
mrb_value debug(mrb_state* mrb, mrb_value self)
{
    RClass* my_class = mrb_define_class(mrb, "Shape", mrb->object_class);
    mrb_define_method(mrb, my_class, "type", debug2, ARGS_NONE());

    //RClass* a_class = mrb_class_get(myMirb->mrb, "MyClass");
    // mrb_value args[2];
    // args[0] = mrb_fixnum_value(LED_ORANGE);     //pin Number
    // args[1] = mrb_fixnum_value(1000);   //interval
    mrb_value a_obj = mrb_class_new_instance(mrb, 0, NULL, my_class);

    return mrb_funcall(mrb, a_obj, "type", 0);

    //  mrb_funcall(mrb, blinker_obj,"run",0);
    // return a_obj;
}