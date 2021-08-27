#include<stdio.h>
#include<conio.h>
int i,x,y;
char stack[20];
char arr[4][4]={{'b','>','>','>'},
                {'<','>','<','>'},
                {'<','>','>','>'},
                {'<','<','<','b'}};

char pop();
void push(char *p);
int prec(char p);
char top();

void main()
{
    int j, flag=0;
    char str[30];
    i=0;
    stack[i++]='$';
    printf("Enter The String: ");
    gets(str);
    j=0;
    while(str[j]!='$')
    {
        y=prec(str[j]);
        x=prec(top());
        if(arr[x][y]=='<')
        {
            push(&arr[x][y]);
            push(&str[j++]);
        }
        else if (arr[x][y]=='>')
        {
            while(top()!='<')
            {
                pop();
            }
            pop();
        }
        else if (arr[x][y]=='b')
        {
            
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        while(top()!='$')
        {
            y=prec(str[j]);
            x=prec(top());
            if(arr[x][y]=='>')
            {
                while(top()!='<')
                {
                    pop();
                }
                pop();
            }
            else if(arr[x][y]=='b')
            {
                flag=1;
                break;
            }
        }
    }

    if (flag==0)
    {
        printf("The Entered String is Accepted");
    }
    else
    {
        printf("The Entered String is Not Accepted");
    }
}

char pop()
{
    return stack[--i];
}
void push(char *p)
{
    stack[i++]=*p;
}
int prec(char p)
{
    if(p=='d')
    {
        return 0;
    }
    else if(p=='+')
    {
        return 1;
    }
    else if(p=='*')
    {
        return 2;
    }
    else if(p=='$')
    {
        return 3;
    }
}
char top()
{
    return stack[i-1];
}