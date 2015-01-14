#include <stdio.h>
#include "mpc.h"
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv) {

  mpc_parser_t* Operand = mpc_new("operand");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");

  mpca_lang(MPCA_LANG_DEFAULT,
" \
operand = /[0-9]/; \
operator = '+'; \
expr : /^/ <operand><operator><operand>+ /$/; \
", 
	    Operand, Operator, Expr);


  while(1) {
    char* input = readline("lispy> ");
    add_history(input);

    mpc_result_t r;
    if(mpc_parse("<stdin>", input, Expr, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    }

    else {
      mpc_err_print(r.output);
      mpc_err_delete(r.output);
    }

    free(input);
  }

  mpc_cleanup(3, Operator, Operand, Expr);

  return 0;
}
