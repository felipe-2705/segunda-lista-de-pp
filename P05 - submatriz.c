#include<stdlib.h>
#include<stdio.h>

int maxsubmat(int x, int n[x][x]);

int main(int argc, char *argv[]){
    int i,j,n,k,K,cont=0;

    printf("Digite um valor inteiro (n) que define a dimensao da matriz nxn: ");
    scanf("%d",&n);
    int M[n][n];
    ///Ler matriz
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("a[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    }
    ///Matriz formada
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",M[i][j]);
        }
        putchar('\n');
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(M[i][j] == 1){
                for(k=i,k<n,k++){
                    for(K=j,k<n,k++){
                        if(M[k][K] != 1 && M[k][K] != 1 && M[k][K] != 1){

                        }
                    }
                }
                //M[i][j+1] != 1 && M[i+1][j+1] != 1 && M[i+1][j] != 1
            }
        }
    }
    printf("cont: %d\n",cont);
    return 0;}
