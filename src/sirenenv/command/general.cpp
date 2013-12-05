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
 * \brief help for commands
 */
mrb_value help(mrb_state* mrb, mrb_value self)
{
	mrb_value name;
	int argc = mrb_get_args(mrb, "S", &name);

	// prefixmatch
	std::string ptn = std::string("^") + std::string(RSTRING_PTR(name)) + std::string(".*");
	std::tr1::regex re(ptn);

	mrb_value ar = mrb_ary_new(mrb);

	std::map<std::string, structHelp*>::iterator it = Help.begin();
	for (; it != Help.end(); it++) {
		if (std::tr1::regex_match(it->first, re)) {
			mrb_value tar[3];
			tar[0] = mrb_str_new(mrb, it->first.c_str(), strlen(it->first.c_str()));
			tar[1] = mrb_str_new(mrb, it->second->desc->c_str(), strlen(it->second->desc->c_str()));
			tar[2] = mrb_str_new(mrb, it->second->usage->c_str(), strlen(it->second->usage->c_str()));
			mrb_ary_push(mrb, ar, mrb_ary_new_from_values(mrb, 3, tar));
		}
	}
	if ((int)mrb_ary_len(mrb, ar))
		return ar;
	else
		return mrb_nil_value();
}

/**
 * \brief version information
 */
mrb_value version(mrb_state* mrb, mrb_value self)
{
    return mrb_exc_new(mrb, E_NOTIMP_ERROR, NULL, 0);
}
