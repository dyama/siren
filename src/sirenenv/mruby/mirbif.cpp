/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include <stdio.h>

#include "mirbif.h"

static mrb_value plus(mrb_state *mrb, mrb_value self) {
    mrb_value a, b;
    mrb_get_args(mrb, "oo", &a, &b);
    if (mrb_fixnum_p(a) && mrb_fixnum_p(b)) {
        mrb_int x = mrb_fixnum(a);
        mrb_int y = mrb_fixnum(b);
        return mrb_fixnum_value(x + y);
    } else if (mrb_string_p(a) && mrb_string_p(b)) {
        mrb_value s = mrb_str_plus(mrb, a, b);
        return s;
    } else {
        return mrb_nil_value();
    }
}

int main(array<System::String ^> ^args)
{
	// C‚©‚çRuby‚Ìƒƒ\ƒbƒh‚ð’@‚­
	{
		mrb_state* mrb = mrb_open();
		mrb_value v = mrb_str_new_cstr(mrb, "Hello, mrb func!");
		mrb_funcall(mrb, mrb_top_self(mrb), "puts", 1, v);
		mrb_close(mrb);
	}

	Mirb* m = new Mirb();
	m->regist("plus", plus, 2);

    int char_index;
    int last_char;
    char last_code_line[1024] = {0};

    for (;;) {

        char_index = 0;
        while ((last_char = getchar()) != '\n') {
            if (last_char == EOF) break;
            last_code_line[char_index++] = last_char;
        }
        if (last_char == EOF) {
            fputs("\n", stdout);
            break;
        }

        last_code_line[char_index] = '\0';

        m->user_exec(last_code_line);
        last_code_line[0] = '\0';

    }

	delete(m);

    return 0;
}
