/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#pragma once

using namespace std;

#include <stdlib.h>
#include <string.h>
#include <string>
#include <ostream>

#include <mruby.h>

#include "mruby/array.h"
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mruby/string.h>

class Mirb
{
private:
    mrbc_context * cxt;
    mrb_state * mrb;
    mrb_value result;
    int code_block_open;       // = FALSE;
    int ai;
    ostream* fout;
    ostream* ferr;

public:
    Mirb();  /**< constructor */
    ~Mirb(); ///< destructor

private:
    int init(void);
    int cleenup(void);
    void p(mrb_value obj, int prompt);
    mrb_bool is_code_block_open(struct mrb_parser_state *parser);

    bool chstdout(ostream* ost);
    bool chstderr(ostream* ost);

public:
    int user_exec(char *last_code_line);
    void regist(char *name, mrb_func_t func, int args);

 };

