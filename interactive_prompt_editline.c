#include <stdio.h>
#include <stdlib.h>

#include <editline/history.h>
#include <editline/readline.h>

int main() {

  while(1) {
    char* input = readline("lipsy> ");
    add_history(input);
    printf("No you're a %s \n", input);
    free(input);
  }

  return 0;
}
