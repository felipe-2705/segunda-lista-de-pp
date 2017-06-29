#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    int n=0,i=0,j=0,aux=0,k=0,K=0, aux1 = 0;

    printf("Digite um valor inteiro (n) que define a dimensao da matriz nxn: \n");
    scanf("%d",&n);

    int M[n][n], a=0,b=0,c=0,d=0; //B[n][n];
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
             printf("%d ",M[j][i]);
             j--;

        }
        putchar('\n');
        k++;
        i++;
    }
    putchar('\n');
    return 0;}
