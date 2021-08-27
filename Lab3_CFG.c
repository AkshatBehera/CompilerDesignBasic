#include<stdio.h>
#include<conio.h>
struct str
{
    /* data */
    char st[1];
    char rule[20];
}g[15];

void main()
{
    int i,j,n;
    
    printf("Enter no. of productions:");
    scanf("%d",&n);
    printf("Enter productions: \n");
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("\nEnter the non-terminals:");
        scanf("%s",g[i].st);
        printf("Enter the RHS productions:");
        scanf("%s",g[i].rule);
    }
    printf("\nEntered productions are: \n");
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("%c%c%c",g[i].st[0],'-','>');
        printf("%s\n",g[i].rule);
        printf("The starting symbol of productions:");
        printf("%c\n",g[i].st[0]);
    }
    printf("\nThe non-terminals are:");
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("%c\n",g[i].st[0]);
    }
    printf("\nThe terminals are:");
    for(i=0;i<n;i++)
    {
        for (j = 0; g[i].rule[j]!='\0'; j++)
        {
            /* code */
            if (!isupper(g[i].rule[j])&&(g[i].rule[j]!='/'))
            {
                /* code */
                printf("\t%c",g[i].rule[j]);
            }
        }
    }
getch();
}

/*
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

struct str {
    char st[2];
    char rule[20];
} production_rules[30];
char temp[50] = "";

int checkIfExist(char variable) {
    for (int i = 0; temp[i] != '\0'; i++) {
        if (variable == temp[i]) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int n;
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the non terminal: ");
        scanf("%s", production_rules[i].st);
        printf("Enter the RHS of the production Rule: ");
        scanf("%s", production_rules[i].rule);
    }
    printf("the production rules are \n");
    for (int i = 0; i < n; i++) {
        printf("%s -> %s\n", production_rules[i].st, production_rules[i].rule);
    }
    printf("The non terminals are \n");
    for (int i = 0; i < n; i++) {
        printf("%s\t", production_rules[i].st);
    }
    printf("\nThe terminals are \n");
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; production_rules[i].rule[j] != '\0'; j++) {
            
            if (!isupper(production_rules[i].rule[j]) && (production_rules[i].rule[j]!='/') && checkIfExist(production_rules[i].rule[j])) {
                temp[index] = production_rules[i].rule[j];
                index ++;
            }
        }
    }
    for (int i = 0; temp[i] != '\0'; i++) {
        printf("%c\t", temp[i]);
    }
    return 0;
}
*/
