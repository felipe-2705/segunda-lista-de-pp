#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50


int maxsubstring(char str[max],int);

int maxsubstring(char str[max],int n)
{
    char str1[max]= {};
    int i=0,j,k,flag,pos=0,maior=0;
    while(i<=n)
    {
        flag =1;

        for(i=pos; flag==1; i++)
        {
            j=pos;
            k=0;
            while(j<i)
            {


                if(str1[k]==str[i]||str[i]=='\0')
                {
                    flag=0;


                }
                k++;
                j++;
            }

            if(flag==1)str1[i-pos]=str[i];


        }
        str1[i+1]='\0';
        if(strlen(str1)>maior)maior=strlen(str1);
        pos=i;

    }

    return maior;
}

int main ()
{
    int n;
    char str[max];
    printf ("digite uma string :\n");
    gets(str);
    n=strlen(str);
    printf("o tamanho da maior substring eh : %d",maxsubstring(str,n));
    return 0;
}



