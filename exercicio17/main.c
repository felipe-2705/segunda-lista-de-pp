#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i,j, linha,coluna;
    int x=9;
    char r= 's';

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    int m[n][n];  /*deixando o usuario definir tamanho da matriz*/


    for (i=0; i<n; i++) /*definindo que a matriz inicial eh nula*/
    {
        for (j=0; j<n; j++)
        {
            m[i][j]=0;
        }

    }

    printf("MATRIZ ORIGINAL: \n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d  ",m[i][j]);
        }
        printf("\n");
    }

    while (r== 's') /* cria laco pra caso o usuario queira continuar modificando a matriz*/
    {

        printf("\nDigite a linha do elemento: \n");
        scanf("%d", &linha);
        printf("Digite a coluna do elemento: \n");
        scanf("%d", &coluna);

        while  ((coluna>n) || (linha>n)) /* validando os valores da coluna e linha*/
        {
            printf("\nO elemento de linha %d e coluna %d nao existe nessa matriz.\nDigite um elemento valido.\n" ,linha,coluna);
            printf("\nDigite a linha do elemento: \n");
            scanf("%d", &linha);
            printf("Digite a coluna do elemento: \n");
            scanf("%d", &coluna);
        }


        if (m[linha][coluna]< x) /* caso o elemento seja menor que 9*/
        {
            m[linha][coluna]= x;
        }

        for (i=0; i<n; i++) /*acrescentando uma unidade nos elementos ao redor do elemento escolhido pelo usuario*/
        {
            for(j=0; j<n; j++)
            {
                if ( ((i== linha) && (j==coluna-1)) || ((i== linha-1) && (j==coluna)) || ((i== linha-1) && (j==coluna-1)) || ((i== linha) && (j==coluna+1)) || ((i== linha+1) && (j==coluna)) || ((i== linha+1) && (j==coluna+1)) || ((i== linha-1) && (j==coluna+1)) || ((i== linha+1) && (j==coluna-1)))
                {
                    m[i][j]+= + 1;
                }
            }
        }
        printf("MATRIZ MODIFICADA \n");

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d  ",m[i][j]);
            }
            printf("\n");
        }
        printf("\nVoce deseja continuar? Digite s. ");
        scanf("\n%c", &r);

        while ((r!= 'n') && (r!= 'N') && (r!= 'S') && (r!= 's')) /*validando a resposta em sim ou nao*/
        {
            printf("\nEssa resposta nao eh valida. Digite apenas 's' para sim ou 'n' para nao.\n");
            printf("\nVoce deseja continuar? Digite s. \n");
            scanf("\n%c", &r);
        }

    }
    return 0;
}
