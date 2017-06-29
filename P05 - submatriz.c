#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int i,j,n,l,k,a,b,cont=0, Area = 0,maior=0,xi=0,xf=0,yi=0,yf=0;

    printf("Digite um valor inteiro (n) que define a dimensao da matriz nxn: ");
    scanf("%d",&n);
    int M[n][n];///declaração da matriz
    ///Ler matriz
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    }
    ///Matriz formada
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",M[i][j]);
        }
        putchar('\n');
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                for(l=0; l<n; l++)
                {
                    cont = 0;
                    for(a=i;a<=k;a++)
                    {
                        for(b=j;b<=l;b++)
                        {
                            cont += M[a][b];
                        }
                    }
                    Area = (k-i+1)*(l-j+1);
                    if((cont==Area) && (cont > maior)){
                        maior = cont;
                        xi = i;
                        xf = k;
                        yi = j;
                        yf = l;
                    }
                }
            }
        }
    }
    if(maior != 0)
    {
        printf("Maxima submatriz eh: \n");
        for(i = xi; i <= xf; i++)
        {
            for(j = yi; j <= yf; j++)
            {
                printf("%d ",M[i][j]);
            }
            putchar('\n');
    }
    }
    else
    {
        printf("Maxima matriz nao exixtente!!!\n");
    }

    return 0;
}
