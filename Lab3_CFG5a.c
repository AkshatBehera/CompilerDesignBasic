#include <stdio.h>
#include <conio.h>
#include <ctype.h>

struct str {
    char st[2];
    char rule[20];
} production_rules[30];

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
    char output[30];
    int index = 0;     
    for (int i = 0; i < n; i++) {
        for (int j = 0; production_rules[i].rule[j] != '\0'; j++) {
            output[index] = production_rules[i].rule[j];
            index ++;
        }
        output[index] = '/';
        index ++;
    }
    printf("The updated production rule is: \n");
    printf("%s -> ", production_rules[0].st);
    for (int i = 0; i < index-1; i++) {
        printf("%c", output[i]);
    }
    return 0;
}