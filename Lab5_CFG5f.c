#include <stdio.h>
#include <stdlib.h>
int main() {
  char prod[20][20],alpha[10][10],beta1[10][10],beta2[10][10];
  int i,j,k,x,n;
  printf("enter the no. of productions:");
  scanf("%d",&n);
  printf("enter the %d productions: ",n);
  for(i=0;i<=n;i++)
  {
    gets(prod[i]);
  }
  for(x=1;x<=n;x++)
  {
    if(prod[x][1]=='-'&&prod[x][2]=='>')
      {
        i=3;j=0;
        while(prod[x][j]!='/')
        {
          j++;
        }
        j++;
        k=0;
        while(prod[x][i]==prod[x][j])
        {
          alpha[x][k++]=prod[x][i++];
          j++;
        }
        alpha[x][k]='\0';
        k=0;
        while(prod[x][i]!='/')
        {
          beta1[x][k++]=prod[x][i++];
        }
        beta1[x][k]='\0';
        k=0;
        if(prod[x][j]=='\0')
        {
          beta2[x][k++]='$';
          beta2[x][k]='\0';
        }
        else
        {
          while(prod[x][j]!='\0')
          {
            beta2[x][k++]=prod[x][j++];
          }
          beta2[x][k]='\0';
        }
        printf("\n%c->%s%c\n",prod[x][0],alpha[x],prod[x][0]);
        printf("%c'->%s/%s",prod[x][0],beta1[x],beta2[x]);
      }
      else
      {
        printf("Entered production not in correct format\n");
      }
      }
  return 0;
}