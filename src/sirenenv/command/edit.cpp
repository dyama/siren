/**
 * \brief Edit commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief Erase object
 */
mrb_value erase(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	::unset(target);
	return mrb_nil_value();
}

/**
 * \brief copy object
 */
mrb_value copy(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(hashape->Shape());
	TopoDS_Shape shape = Builder.Shape();

	return mrb_fixnum_value(::set(shape));
}

