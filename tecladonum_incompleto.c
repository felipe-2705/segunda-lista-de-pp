#include<stdlib.h>
#include<stdio.h>

char caracteres(char s, char res[], int i);
void recursiva(char string[], char res[], int pos, int fim, int n);

int main()
{

    char string[1000], res[1000];
    int n;
    printf("Digite a string de numeros: ");
    scanf("%s", string);
    n = strlen(string);
    recursiva(string, res, 0, n-1, n);

    return 0;
}

void recursiva(char string[], char res[], int pos, int fim, int n)
{
    int i, j, k=0;
    if(pos==n)
    {
        printf("%c", res[j]);
        printf("\n");
        return;
    }

    int temp[5];
    for(i=0; i<=n-1; i++)
    {
        res[pos] = caracteres(string[i], temp, i);
        recursiva(string, res, pos+1, i+1, n);
    }
}

char caracteres(char s, char temp[], int i)
{
    switch(s)
    {
    case '2':
        strcpy(temp, "abc");
        return temp[i];
        break;
    case '3':
        strcpy(temp, "def");
        return temp[i];
        break;
    case '4':
        strcpy(temp, "ghi");
        return temp[i];
        break;
    case '5':
        strcpy(temp, "jkl");
        return temp[i];
        break;
    case '6':
        strcpy(temp, "mno");
        break;
    case '7':
        strcpy(temp, "pqrs");
        break;
    case '8':
        strcpy(temp, "tuv");
        break;
    case '9':
        strcpy(temp, "wxyz");
        break;
    }
}
