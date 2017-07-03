#include <stdio.h>
#include <string.h>

void parametros(char s[], int n, char res[]);
void  imprimir_letras(char s[], int atual, char res[], int n, char temp[]);
void mapa(char s, char temp[]);
int mapalen(char s);

int main(void)
{
    char s[1000], res[1000];
    printf("Digite uma sequencia numerica: ");
    scanf("%s", s);
    int n = strlen(s);
    parametros(s, n, res);
    return 0;
}

void parametros(char s[], int n, char res[])
{
    char temp[5] = {0};
    res[n] = '\0';
    imprimir_letras(s, 0, res, n, temp);
}

void  imprimir_letras(char s[], int atual, char res[], int n, char temp[])
{
    int i;
    if (atual == n)
    {
        printf("%s ", res);
        return ;
    }
    for (i=0; i<mapalen(s[atual]); i++)
    {
        mapa(s[atual], temp);
        res[atual] = temp[i];
        imprimir_letras(s, atual+1, res, n, temp);
    }
}

void mapa(char s, char temp[])
{
    switch(s)
    {
    case '2':
        strcpy(temp, "abc");
    break;
    case '3':
        strcpy(temp, "def");
    break;
    case '4':
        strcpy(temp, "ghi");
    break;
    case '5':
        strcpy(temp, "jkl");
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

int mapalen(char s)
{
    if(s == '7' || s == '9') return 4;
    else return 3;
}
