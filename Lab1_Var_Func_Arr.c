#include<stdio.h>
#include<ctype.h>
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

int validArray(char var[100]){
	char c = var[0];
	if(!isalpha(c) && c != '_'){
		return 0;
	}
	int i = 0;
	while (c!='\0'){
		if(c=='['){
			break;
		}
		if(!isalnum(c) && c!='_'){
			return 0;
		}
		c = var[++i];
	}
	if (c=='['){
		c = var[++i];
		if (!isdigit(c)){
			return 0;
		}
		c = var[++i];
		while(c!='\0' && c!=']'){
			if (!isdigit(c)){
				return 0;
			}
			c = var[++i];
		}
		if (c==']' && var[++i]=='\0'){
			return 1;
		}
	}else{
		return 0;
	}
	
}

int validFunction(char var[200]){
	char c = var[0];
	if (!isalpha(c) && c!='_'){
		return 0;
	}
	int i = 0;
	while(c != '\0'&&c!='(' ){
		if(!isalnum(c) && c != '_'){
			return 0;
		}
		c = var[++i];
	}
	if (c=='(' && var[++i]==')'){
		return 1;
		
	}else{
		return 0;
	}
	return 1;
}


int main(){
	char identifier[200];
	gets(identifier);
	if(validVariable(identifier)){
		printf("Its a valid variable");
	}else if(validArray(identifier)){
		printf("Its a valid array identifier");
	}
	else if(validFunction(identifier)){
		printf("Its a valid function identifier");
	}
	else{
		printf("Its not a valid identifier");
	}
	return 0;
}