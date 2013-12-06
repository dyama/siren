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
