/**
 * \brief
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */
#ifndef _COMMAND_H_
#define _COMMAND_H_

#pragma once

#include "Stdafx.h"
#include "mirb.h"
#include "OCCViewer.h"

static OCCViewer* ocv;

class command
{
protected:
	command(){}
	~command(){}

public:
	static mrb_value box(mrb_state* mrb, mrb_value self);

	static void regist_all(mrb_state* mrb, OCCViewer* ocv)
	{
		::ocv = ocv;
		
		mrb_define_method(mrb, mrb->kernel_module,
			"box", &command::box, MRB_ARGS_REQ(3) | MRB_ARGS_OPT(3));

		return;
	}

	static void test()
	{
		::ocv->GetAISContext()->UpdateCurrentViewer();
	}
};

#endif