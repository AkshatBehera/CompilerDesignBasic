#include <stdio.h>
#include <ctype.h>
#include <string.h>

int indexOf(char string[], char identify) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == identify) return i;
    }
    return -1;  
}

int checkVariable (char inputString[]) {
    if (strlen(inputString) == 0) {
        return 0;
    }
    char first_charecter = inputString[0];
    if (!(isalpha(first_charecter) || first_charecter == '_')) {
        return 0;
    }
    for (int i = 1; i < strlen(inputString); i++) {
        if (inputString[i] == ' ') {
            return 0;
        }
        if((inputString[i] >= 'a' && inputString[i] <= 'z') || (inputString[i] >= 'A' && inputString[i] <= 'Z')){}
        else if(inputString[i] >= '0' && inputString[i] <= '9'){}
        else 
        {
            if (inputString[i] != '_') {
                return 0;
            }
        }
    }
    return 1;
}

int checkInteger(char value[]) {
    int length = strlen(value); int given_is_float = 0; int given_is_integer = 0;
    if (length == 0) return 0;
    int x = 0;
    if (value[0] == '-') x = 1;
    if (length == 1) return 0; 
    for (int i = x; i < length; i++) {
        if (value[i] == '.') given_is_float = 1;
        else if (isdigit(value[i]) == 0) return 0;
    }
    
    if (given_is_float == 1) return 1;
    // if the given is integer
    return 2;
}


int checkStructure(char input[]) {
    // printf("%s", input);
    int length = strlen(input); char str1[] = {'s', 't', 'r', 'u', 'c', 't'};
    int get_index_of_first_white_space = indexOf(input, ' ');
    // printf("%d", get_index_of_first_white_space);
    if (get_index_of_first_white_space == -1) return 0;
    
    for (int i = 0; i < get_index_of_first_white_space; i++) {
        if (input[i] != str1[i]) return 0;
    }
    
    char newString[30] = ""; int temp = 0; int store = 0;

    for (int i = get_index_of_first_white_space +1; input[i] != ' '; i++) {
        newString[temp] = input[i];
        temp += 1;
        store = i; 
        // printf("%d\t%d\n ", i, store);
    }
    
    store += 1;
    if (checkVariable(newString) == 0) return 0;
    if (store + 1 >= length || store + 2 >= length) return 0;
    if (input[store + 1] != '{' || input[store + 2] != '}') return 0;
    return 1;
    // {}
}


int main () {
    char input[50];
    printf("enter a string:\t");
    gets(input);
    // checkStructure(input)
    int output = checkInteger(input);
    // printf("%d", output);
    if (output == 0) {
        //if 0 then not a valid structure
        printf("\nThe given input is not a valid Integer or real number");
    } else if (output == 1) {
        // if 1 not it is a valid structure
        printf("\nthe given input is a valid real number");
    }
    // comment this else if if checking for a structure 
    else if (output == 2) {
        printf ("\nthe given input is a valid integer");
    }
    return 0;
}