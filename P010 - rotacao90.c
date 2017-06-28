#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    int n=0,i=0,j=0,aux=0,k=0,K=0;

    printf("Digite um valor inteiro (n) que define a dimensao da matriz nxn: \n");
    scanf("%d",&n);

    int M[n][n], B[n][n];
    ///Ler a matriz

    while(i<n){
        j=0;
        while(j<n){
            printf("a[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
            j++;
        }
        i++;
    }

    ///Código que gira a matriz

    i=0;
    j=n-1;
    while(i<n){
        j=n-1;
        K=0;
        while(j>=0){
             B[k][K] = M[j][i];
             j--;
             K++;
        }
        k++;
        i++;
    }
    putchar('\n');
    ///Imprimir a inicial
    printf("A matriz digitada \n");
    i=0;
    j=0;
    while(i<n){
        j=0;
        while(j<n){
            printf("%d ",M[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    putchar('\n');
    ///Imprimir a matriz final
    printf("A matriz rodada 90 graus \n");
    i=0;
    j=0;
    while(i<n){
        j=0;
        while(j<n){
            printf("%d ",B[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }


    return 0;}
