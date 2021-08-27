#include<stdio.h>
#include<conio.h>

int n,counter=0;
char arr[20][20];
void First(char *);
void Follow(char *);

void main()
{
    int i;
    printf("\nEnter the number of productions:");
    scanf("%d",&n);
    n++;
    printf("\nEnter the productions: ");
    for(i=0;i<n;i++)
    {
        gets(arr[i]);
    }
    for(i=1;i<n;i++)
    {
        printf("\nFirst(%c):",arr[i][0]);
        First(&arr[i][0]);
        counter=0;
        printf("\nFollow(%c):",arr[i][0]);
        Follow(&arr[i][0]);
    }
}

void First(char *p)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i][0] == *p)
        {
            if(isupper(arr[i][3]))
            {
                if(arr[i][3]==arr[i][0])
                {
                    //Does Nothing
                }
                else
                {
                    First(&arr[i][3]);
                }
            }
            else
            {
                printf("%c",arr[i][3]);
            }
            j=0;
            while(arr[i][j]!='\0')
            {
                if(arr[i][j]=='/')
                {
                    j++;
                    if(isupper(arr[i][j]))
                    {
                        if(arr[i][j]==*p)
                        {
                            //Does Nothing
                        }
                        else
                        {
                            First(&arr[i][j]);
                        }
                    }
                    else
                    {
                        printf("%c",arr[i][j]);
                    }
                }
                j++;
            }
        }
    }
}

void Follow(char *p)
{
    int i,j;
    if(*p==arr[1][0])
    {
        printf("$");
    }
    for(i=0;i<n;i++)
    {
        j=3;
        while(arr[i][j]!='\0')
        {
            if(arr[i][j]==*p)
            {
                j++;
                if(arr[i][j]=='\0'||arr[i][j]=='/')
                {
                    if(counter==0)
                    {
                        Follow(&arr[i][0]);
                        counter++;
                    }
                }
                else if (isupper(arr[i][j]))
                {
                    /* code */
                    First(&arr[i][j]);
                }
                else
                {
                    printf("%c",arr[i][j]);
                }
            }
            j++;
        }
    }
}









/*

#include<stdio.h>

int n,counter=0;
char arr[20][20];
int First(char *);
int Follow(char *);

int main()
{
    int i;
    printf("\nEnter the number of productions:");
    scanf("%d",&n);
    n++;
    printf("\nEnter the productions: ");
    for(i=0;i<n;i++)
    {
        gets(arr[i]);
    }
    for(i=1;i<n;i++)
    {
        printf("\nFirst(%c):",arr[i][0]);
        First(&arr[i][0]);
        counter=0;
        printf("\nFollow(%c):",arr[i][0]);
        Follow(&arr[i][0]);
    }
    return 0;
}

int First(char *p)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i][0] == *p)
        {
            if(isupper(arr[i][3]))
            {
                if(arr[i][3]==arr[i][0])
                {
                    //Does Nothing
                }
                else
                {
                    First(&arr[i][3]);
                }
            }
            else
            {
                printf("%c",arr[i][3]);
            }
            j=0;
            while(arr[i][j]!='\0')
            {
                if(arr[i][j]=='/')
                {
                    j++;
                    if(isupper(arr[i][j]))
                    {
                        if(arr[i][j]==*p)
                        {
                            //Does Nothing
                        }
                        else
                        {
                            First(&arr[i][j]);
                        }
                    }
                    else
                    {
                        printf("%c",arr[i][j]);
                    }
                }
                j++;
            }
        }
    }
    return 0;
}

int Follow(char *p)
{
    int i,j;
    if(*p==arr[1][0])
    {
        printf("$");
    }
    for(i=0;i<n;i++)
    {
        j=3;
        while(arr[i][j]!='\0')
        {
            if(arr[i][j]==*p)
            {
                j++;
                if(arr[i][j]=='\0'||arr[i][j]=='/')
                {
                    if(counter==0)
                    {
                        Follow(&arr[i][0]);
                        counter++;
                    }
                }
                else if (isupper(arr[i][j]))
                {
                    
                    First(&arr[i][j]);
                }
                else
                {
                    printf("%c",arr[i][j]);
                }
            }
            j++;
        }
    }
    return 0;
}

*/