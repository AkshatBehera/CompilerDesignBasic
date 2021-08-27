%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER ID
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
stmt :expr ;
expr :expr'+'expr|expr'-'expr
|expr'*'expr
|expr'/'expr
|'('expr')'
|NUMBER
|ID
|'-'expr %prec UMINUS ;
%%
int main()
{
printf("Enter the Arithmetic Expression : ");
yyparse();
printf("The Entered Arithmetic Expression is Valid\n\n");
return 1;
}
int yyerror()
{
printf("Invalid Expression\n");
exit(0);
}
