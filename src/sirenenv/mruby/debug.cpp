#include <stdio.h>
#include "mirb.h"

/*
mrb_value myplus(mrb_state * mrb, mrb_value self)
{
    mrb_value a, b;
    mrb_get_args(mrb, "oo", &a, &b);
    if (mrb_fixnum_p(a) && mrb_fixnum_p(b)) {
        mrb_int x = mrb_fixnum(a);
        mrb_int y = mrb_fixnum(b);
        return mrb_fixnum_value(x + y);
    }
    else if (mrb_string_p(a) && mrb_string_p(b)) {
        mrb_value s = mrb_str_plus(mrb, a, b);
        return s;
    }
    else {
        return mrb_nil_value();
    }
}
*/

int main(int argc, char** argv)
{
    // // CからRubyのメソッドを叩く
    // {
    //     mrb_state * mrb = mrb_open();
    //     mrb_value v = mrb_str_new_cstr(mrb, "Hello, mrb func!");
    //     mrb_funcall(mrb, mrb_top_self(mrb), "puts", 1, v);
    //     mrb_close(mrb);
    // }

    int char_index;
    int last_char;
    char last_code_line[1024] = { 0 };
    int lno = 1;

    Mirb* m = new Mirb();

    // m->regist("plus", myplus, 2);

    for (;;) {

        printf("%d$ ", lno);

        char_index = 0;
        while ((last_char = getchar()) != '\n') {
            if (last_char == EOF)
                break;
            last_code_line[char_index++] = last_char;
        }
        if (last_char == EOF) {
            fputs("\n", stdout);
            break;
        }
        last_code_line[char_index] = '\0';

        m->user_exec(last_code_line, lno);

        last_code_line[0] = '\0';
     }
     delete(m);
     return 0;
}

