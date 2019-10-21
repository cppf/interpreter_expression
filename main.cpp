#include "main.h"
#include <stdio.h>

extern FILE* yyin;
extern Ast* yyroot;
extern int yyparse();


int main(int argc, char **argv) {
  const char *input = argc > 1? argv[1] : "input.txt";
  yyin = fopen(input, "r");
  yyparse();
  string *s = new string();
  yyroot->postfix(s);
  printf("postfix: %s\n", s->c_str());
  printf("eval: %d\n", yyroot->eval());
}

void yyerror(const char *s) {
  fprintf(stderr, "error: %s\n", s);
}
