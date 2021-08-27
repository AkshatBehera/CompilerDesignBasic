#include<stdio.h>
#include<ctype.h>
int isConst(char str[100]){
	int i = 0;
	char x = str[i];
	if (x == '-' || x == '+'){
		x = str[++i];
	}
	int res = 1;
	while(x!='\0'){
		
		if (!isdigit(x) && x != '.'){
			return 0;
		}
		if (x == '.' && res==2){
			return 0;
		}
		if (x == '.'){
			res = 2;
		}
		x = str[++i];
	}
	return res;
}
int main(){
	char str[100];
	gets(str);
	switch(isConst(str)){
		case 1: printf("Integer");
			break;
		case 2: printf("Real");
			break;
		case 0: printf("Not a Constant");
	}
	return 0;
}