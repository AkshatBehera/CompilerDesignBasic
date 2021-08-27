%option noyywrap
%{
#include"y.tab.h"
%}

%%
[0-9]+ {return NUMBER;}
[a-zA-z][0-9a-zA-Z]* {return ID;}
[ \t]+ {;}
. {return yytext[0];}
\n {return 0;}
%%