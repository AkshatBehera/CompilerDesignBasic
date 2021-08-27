%option noyywrap
%{
	#include<stdio.h>
    #include<stdlib.h>
%}
DIGIT[0-9]
ID[a-zA-z][a-zA-z0-9]*
%%
{DIGIT}+ {printf("INTEGER: %s (%d)\n",yytext,atoi(yytext));}
{DIGIT}+"."{DIGIT}* {printf("Double: %s (%g)\n",yytext,atof(yytext));}
float |
int |
double |
for |
if {printf("KEYWORD %s\n",yytext);}
{ID}printf("IDENTIFIER: %s\n",yytext);
":"|"{"|"}"|"("|")"|";"|"," printf("PUNCTUATION: %s\n",yytext);
"=" printf("OPERATOR: %s\n",yytext);
[\t\n]+ /*eat up whitespace*/
. printf("Unrecognized character: %s\n",yytext);
%%
int main()
{
	yylex();
	return 0;
}