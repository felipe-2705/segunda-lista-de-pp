#include <stdio.h>
#include <stdlib.h>

void inverterecursiva(char *inverte)
{
    if(*inverte)
    {
        inverterecursiva(inverte+1);
        putchar (*inverte);
    }
}

int main()
{
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);

    inverterecursiva(str);
    return 0;
}
