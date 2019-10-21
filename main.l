%{
#include "main.tab.h"
int line = 0;
%}

%%
[ \t]     ;
\n        line++;
[0-9]+    return INT;
[+\-*/()] return yytext[0];
.

%%
