/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once

#include <stdlib.h>
#include <string.h>
#include <string>
#include <ostream>

using namespace std;

#include <mruby.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/numeric.h>
#include <mruby/proc.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/error.h>
#include <mruby/data.h>
#include <mruby/compile.h>

class Mirb
{
private:
    mrbc_context* cxt;
    mrb_value result;
    mrb_bool code_block_open;       // = FALSE;
    int ai;
	int first_command;
	unsigned int nregs;

    char ruby_code[1024*32];// = { 0 };

public:
    Mirb();  /**< constructor */
    ~Mirb(); ///< destructor
    mrb_state* mrb;

private:
    int init(void);
    int cleenup(void);
    void p(mrb_value obj, int prompt);
	void p(mrb_value obj, int prompt, std::string& msg);
    mrb_bool is_code_block_open(struct mrb_parser_state *parser);

public:
	int user_exec(char *last_code_line);
	int user_exec(char *last_code_line, std::string& errmsg);
    void regist(char *name, mrb_func_t func, int args);
	void p(int prompt, std::string& result);

	bool isCodeBlockOpen();

 };

