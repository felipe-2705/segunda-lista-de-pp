#include <stdio.h>

#define size 100


double diag_superior(double mat [size][size],int );


double diag_superior(double mat [size][size],int n )
{
    int i,j;
    double soma=0,count=0;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {

            if (i+j<n-1 && i-j<0 )
            {

                soma  = mat[i][j]+soma;

                count++;

            }
        }

    }
return soma/count;
}

int main (){
double mat [size][size];
int n,i,j;

printf ("entre com a ordem da matriz  :");
scanf("%d",&n);

while (n>size){
    printf("erro...tamanho superior ao limite!\n");
    printf("digite novamente :");
    scanf("%d",&n);
}
printf ("digite os elementos da matriz :\n");
for (i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf ("mat[%d][%d]:",i+1,j+1);
        scanf("%lf",&mat[i][j]);
    }
}

printf("A media dos elementos superiores da matriz eh : %.3lf",diag_superior(mat,n));

return 0;}


