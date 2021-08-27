#include<stdio.h>
#include<conio.h>
int i=0,t=1;
char str[20];
void E();
void Eprime();
void T();
void Tprime();
void F();
void error();

void main()
{
    printf("\nThe Given Grammer is: \n");
    printf("\nE->TE'");
    printf("\nE'->TE'/$");
    printf("\nT->FT'");
    printf("\nT'->*FT/$");
    printf("\nF->(E)/a");
    printf("\nEnter the string to be parsed: ");
    gets(str);
    E();
    if(t!=1 || str[i]!='\0')
    {
        printf("\n Given String is not accepted");
    }
    else
    {
        printf("\n The Given String is Accepted");
    }
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if(str[i]=='+')
    {
        i++;
        T();
        Eprime();
    }
    else
    {
        return;
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if(str[i]=='*')
    {
        i++;
        F();
        Tprime();
    }
    else return;
}

void F()
{
    if(str[i]=='a')
    {
        i++;
    }
    else if(str[i]=='(')
    {
        i++;
        E();
        if(str[i]==')')
        {
            i++;
        }
    }
    else
    {
        error();
    }
}

void error()
{
    t=-1;
}