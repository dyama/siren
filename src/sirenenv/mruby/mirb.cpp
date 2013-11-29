/**
 * \brief mruby interpretor interface
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * \author dyama <dyama@member.fsf.org>
 */

#include "mirb.h"

#ifdef _WIN32
  #define strcat strcat_s
  #define strcpy strcpy_s
#endif

/**
 * constractor
 */
Mirb::Mirb()
{
    code_block_open = FALSE;

    mrb = mrb_open();

    if (mrb == NULL) {
        fputs("Invalid mrb interpreter, exiting mirb\n", stderr);
        throw "";
    }

    mrb_define_global_const(mrb, "ARGV", mrb_ary_new_capa(mrb, 0));
    cxt = mrbc_context_new(mrb);
    cxt->capture_errors = 1;
    cxt->lineno = 1;
    mrbc_filename(mrb, cxt, "(mirb)");
    ai = mrb_gc_arena_save(mrb);

	first_command = 1;

    for (int i=0; i<1024; i++) {
        ruby_code[i] = 0;
    }

    return;
}

/**
 * destractor
 */
Mirb::~Mirb()
{
    mrbc_context_free(mrb, cxt);
    mrb_close(mrb);
    return;
}

/**
 * regist function as ruby commands
 * \param name command name
 * \param func function pointer
 * \param args number of arguments
 * \return nothing
 */
void Mirb::regist(char *name, mrb_func_t func, int args)
{
    mrb_define_method(mrb, mrb->kernel_module, name, func, MRB_ARGS_REQ(args));
    return;
}

void Mirb::p(mrb_value obj, int prompt)
{
    obj = mrb_funcall(mrb, obj, "inspect", 0);
    if (prompt) {
        if (!mrb->exc) {
            fputs(" => ", stdout);
        }
        else {
            obj = mrb_funcall(mrb, mrb_obj_value(mrb->exc), "inspect", 0);
        }
    }
    fwrite(RSTRING_PTR(obj), RSTRING_LEN(obj), 1, stdout);
    putc('\n', stdout);
}

void Mirb::p(int prompt, std::string& msg)
{
	msg = std::string();
	this->result = mrb_funcall(mrb, this->result, "inspect", 0);
    if (prompt) {
        if (!mrb->exc) {
			msg  += " => ";
        }
        else {
			this->result = mrb_funcall(mrb, mrb_obj_value(mrb->exc), "inspect", 0);
        }
    }
	msg += RSTRING_PTR(this->result);
	msg += "\n";
    //fwrite(RSTRING_PTR(obj), RSTRING_LEN(obj), 1, stdout);
    //putc('\n', stdout);
}

void Mirb::p(mrb_value obj, int prompt, std::string& msg)
{
	msg = std::string();
	obj = mrb_funcall(mrb, obj, "inspect", 0);
    if (prompt) {
        if (!mrb->exc) {
			msg  += " => ";
        }
        else {
			obj = mrb_funcall(mrb, mrb_obj_value(mrb->exc), "inspect", 0);
        }
    }
	msg += RSTRING_PTR(obj);
	msg += "\n";
    //fwrite(RSTRING_PTR(obj), RSTRING_LEN(obj), 1, stdout);
    //putc('\n', stdout);
}

/* Guess if the user might want to enter more
 * or if he wants an evaluation of his code now */
mrb_bool Mirb::is_code_block_open(struct mrb_parser_state *parser)
{
    int code_block_open = FALSE;

    /* check for heredoc */
    /* ヒアドキュメントかチェック */
    if (parser->parsing_heredoc != NULL)
        return TRUE;

    if (parser->heredoc_end_now) {
        parser->heredoc_end_now = FALSE;
        return FALSE;
    }

    /* check for unterminated string */
    if (parser->lex_strterm)
        return TRUE;

    /* check if parser error are available */
    if (0 < parser->nerr) {
        const char *unexpected_end = "syntax error, unexpected $end";
        const char *message = parser->error_buffer[0].message;
            /* a parser error occur, we have to check if */
            /* we need to read one more line or if there is */
            /* a different issue which we have to show to */
            /* the user */
            if (strncmp(message, unexpected_end, strlen(unexpected_end)) == 0) {
            code_block_open = TRUE;
        }
        else if (strcmp(message, "syntax error, unexpected keyword_end") == 0) {
            code_block_open = FALSE;
        }
        else if (strcmp(message, "syntax error, unexpected tREGEXP_BEG") == 0) {
            code_block_open = FALSE;
        }
        return code_block_open;
    }
    switch (parser->lstate) {

            /* all states which need more code */
    case EXPR_BEG:

            /* an expression was just started, */
            /* we can't end it like this */
            code_block_open = TRUE;
        break;
    case EXPR_DOT:

            /* a message dot was the last token, */
            /* there has to come more */
            code_block_open = TRUE;
        break;
    case EXPR_CLASS:

            /* a class keyword is not enough! */
            /* we need also a name of the class */
            code_block_open = TRUE;
        break;
    case EXPR_FNAME:

            /* a method name is necessary */
            code_block_open = TRUE;
        break;
    case EXPR_VALUE:

            /* if, elsif, etc. without condition */
            code_block_open = TRUE;
        break;

            /* now all the states which are closed */
    case EXPR_ARG:

            /* an argument is the last token */
            code_block_open = FALSE;
        break;

            /* all states which are unsure */
    case EXPR_CMDARG:
        break;
    case EXPR_END:

            /* an expression was ended */
            break;
    case EXPR_ENDARG:

            /* closing parenthese */
            break;
    case EXPR_ENDFN:

            /* definition end */
            break;
    case EXPR_MID:

            /* jump keyword like break, return, ... */
            break;
    case EXPR_MAX_STATE:

            /* don't know what to do with this token */
            break;
    default:

            /* this state is unexpected! */
            break;
    }
    return code_block_open;
}

int Mirb::user_exec(char* last_code_line)
{
	std::string msg;
	return user_exec(last_code_line, msg);
}

/**
 * user execution with ruby code string
 * \param last_code_line code line
 * \return true if success
 */
int Mirb::user_exec(char* last_code_line, std::string& errmsg)
{
    struct mrb_parser_state *parser;
    int err = 0;

    if ((strcmp(last_code_line, "quit") == 0) || (strcmp(last_code_line, "exit") == 0)) {
        if (!code_block_open) {
            return err;
            // break;
        }
        else {
            /* count the quit/exit commands as strings if in a quote block */
            strcat(ruby_code, "\n");
            strcat(ruby_code, last_code_line);
        }
    }
    else {
        if (code_block_open) {
            strcat(ruby_code, "\n");
            strcat(ruby_code, last_code_line);
        }
        else {
            strcpy(ruby_code, last_code_line);
        }
    }

    /* parse code */
    /* パースする */
    parser = mrb_parser_new(mrb);
    parser->s = ruby_code;
    parser->send = ruby_code + strlen(ruby_code);
    parser->lineno = cxt->lineno;
    mrb_parser_parse(parser, cxt);
    code_block_open = is_code_block_open(parser);

    if (code_block_open) {
        /* no evaluation of code */
        /* ブロック内ならば実行しない */
    }
    else {
        if (0 < parser->nerr) {
            /* syntax error */
            /* 構文エラー */
            //printf("line %d: %s\n", parser->error_buffer[0].lineno, parser->error_buffer[0].message);
			errmsg = std::string(parser->error_buffer[0].message);
            err = 1;
        }
        else {
	        /* generate bytecode */
            /* バイトコードを生成 */
	        struct RProc *proc = mrb_generate_code(mrb, parser);

	        /* pass a proc for evaulation */
	        nregs = first_command ? 0: proc->body.irep->nregs;
	        /* evaluate the bytecode */
            /* バイトコードを実行 */
	        result = mrb_context_run(mrb,
	            proc,
	            mrb_top_self(mrb),
	            nregs);

            /* did an exception occur? */
            /* 例外が発生したか */
            if (mrb->exc) {
				p(mrb_obj_value(mrb->exc), 0, errmsg);
                err = 2;
                mrb->exc = 0;
            }
            else {
                /* no */
                /* してない */
                if (!mrb_respond_to(mrb, result, mrb_intern2(mrb, "inspect", 7))) {
                    result = mrb_any_to_s(mrb, result);
                }
                p(result, 1);
            }
        }
        ruby_code[0] = '\0';
        mrb_gc_arena_restore(mrb, ai);
    }

    mrb_parser_free(parser);
    cxt->lineno++;
	first_command = 0;

    return err;
}

bool Mirb::isCodeBlockOpen()
{
	return (this->code_block_open == TRUE);
}
