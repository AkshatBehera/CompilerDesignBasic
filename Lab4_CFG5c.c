#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char prod[20],alpha[20],beta[20];
    int i,j;
    printf("Enter Production: ");
    gets(prod);
    if(prod[0]==prod[3])
    {
        printf("\n Entered Production is left recursive");
        i=4;j=0;
        while(prod[i]!='/')
        {
            alpha[j++]=prod[i++];
        }
        alpha[j]='\0';
        i=i+1;
        j=0;
        while (prod[i]!='\0')
        {
            /* code */
            beta[j++]=prod[i++];
        }
        beta[j]='\0';
        printf("\n The Production after removing the left production is: \n");
        printf("\n %c -> %s%c'",prod[0],beta,prod[0]);
        printf("\n %c -> %s%c'/$",prod[0],alpha,prod[0]);
    }
    else{
        printf("Enter production is not left recursive");
    }
}