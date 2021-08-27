#include<stdio.h>
#include<ctype.h>
#include<conio.h>
int validVariable(char var[200]){
	char c = var[0];
	if (!isalpha(c) && c!='_'){
		return 0;
	}
	int i = 0;
	while(c != '\0'){
		if(!isalnum(c) && c != '_'){
			return 0;
		}
		c = var[++i];
	}
	return 1;
}

int isStruct(char str[100]){
	int i = 0;
	char y[7]= {'s','t','r','u','c','t','\0'};
	
	while(i<6){
		if (str[i]!= y[i]) return 0;
		i++;	
	}
	if (str[i] != ' ') return 0;
	char x = str[++i];
	char var[100];
	int j = 0;
	while(x!='{' && x!='\0'){
		var[j++] = x;
		x = str[++i];
	}
    var[j]='\0';
	if (x=='\0'){
		return 0;
	}
	if (!validVariable(var)){
		return 0;
	}
	if(str[++i] == '}' && str[++i]==';' && str[++i]=='\0'){
		return 1;
	}
	return 0;
	
}

int main(){
	char str[100];
	gets(str);
	if(isStruct(str)){
		printf("Valid");
	}
	else{
		printf("Not Valid");
	}
	getch();
	return 0;
}