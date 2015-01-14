#include <stdio.h>

static char input[2048];

int main() {

  puts("Lispy version 0.1 \n");
  puts("press Ctrl+c to exit \n");

  while(1) {

    fputs("lispy> ", stdout);
    fgets(input, 2048, stdin);

    printf("No you're a %s", input);
  }

  return 0;
}
