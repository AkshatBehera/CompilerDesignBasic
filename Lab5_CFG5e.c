#include <stdio.h>
#include <stdlib.h>
int main() {
  char prod[20],alpha[10],beta1[10],beta2[10];
  int i,j,k;
  printf("enter the production:");
  gets(prod);
  if(prod[1]=='-'&&prod[2]=='>')
  {
    i=3;j=0;
    while(prod[j]!='/')
    {
      j++;
    }
    j++;
    k=0;
    while(prod[i]==prod[j])
    {
      alpha[k++]=prod[i++];
      j++;
    }
    alpha[k]='\0';
    k=0;
    while(prod[i]!='/')
    {
      beta1[k++]=prod[i++];
    }
    beta1[k]='\0';
    k=0;
    if(prod[j]=='\0')
    {
      beta2[k++]='$';
      beta2[k]='\0';
    }
    else
    {
      while(prod[j]!='\0')
      {
        beta2[k++]=prod[j++];
      }
      beta2[k]='\0';
    }
    printf("\n%c->%s%c\n",prod[0],alpha,prod[0]);
    printf("%c'->%s/%s",prod[0],beta1,beta2);
  }
  else
  {
    printf("Entered production not in correct format\n");
  }
  return 0;
}