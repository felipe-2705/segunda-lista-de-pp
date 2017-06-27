#include <stdio.h>
#include <stdlib.h>

int contadigitos (int n)
{
    int contador = 0;
    if (n == 0) contador = 1;
    else
        while (n != 0)
        {
            contador = contador + 1;
            n = n / 10;
        }
    printf("Esse numero contem um total de %d numeros decimais.\n", contador);
    return (contador);
}

int main()
{
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    contadigitos(n);
    return 0;
}
