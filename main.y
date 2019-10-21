%{
#include "main.h"

#define YYSTYPE Ast*
Ast *yyroot;
extern char *yytext;
extern int yylex();
extern void yyerror(const char*);
%}

%token INT
%left '+' '-'
%left '*' '/'

%%
s: | e        { yyroot = $1; }
  ;
e:  e '+' e   { $$ = new Add($1, $3); }
  | e '-' e   { $$ = new Sub($1, $3); }
  | e '*' e   { $$ = new Mul($1, $3); }
  | e '/' e   { $$ = new Div($1, $3); }
  | '(' e ')' { $$ = $2; }
  | INT       { $$ = new Int(atoi(yytext)); }
  ;
