/**
 * \brief The I/O operation commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief Save object to BRep file
 */
mrb_value savebrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	mrb_int target; 
	int argc = mrb_get_args(mrb, "Si", &path, &target);

	mrb_value result;

	Handle(AIS_Shape) hashape = ::get((int)target);

	if (hashape.IsNull()) {
		static const char m[] = "No such named object.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	else {
		Standard_Boolean res = BRepTools::Write(hashape->Shape(), (Standard_CString)RSTRING_PTR(path));

		if (res) {
			result = mrb_nil_value();
		}
		else {
			static const char m[] = "Failed to save BRep file.";
	        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}

	return result;
}

/**
 * \brief Load object from BRep file
 */
mrb_value loadbrep(mrb_state* mrb, mrb_value self)
{
    mrb_value path;
	int argc = mrb_get_args(mrb, "S", &path);

	TopoDS_Shape shape;
    BRep_Builder aBuilder;
    Standard_Boolean res = BRepTools::Read(shape, (Standard_CString)RSTRING_PTR(path), aBuilder);

	mrb_value result;

	if (res) {
		//if(AISContext->HasOpenedContext())
		//	AISContext->CloseLocalContext();
		result = mrb_fixnum_value(::set(shape));
	}
	else {
		static const char m[] = "Failed to load BRep file.";
        result = mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	return result;
}

/**
 * \brief Save object to IGES file
 */
mrb_value saveiges(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}

/**
 * \brief Load object from IGES file
 */
mrb_value loadiges(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}
