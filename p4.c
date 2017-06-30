#include<stdio.h>
#include<stdlib.h>

int telhado(int n,int matriz[][50])
{
    int i=0,j=0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i>j&&i<=n/2)
            {
                matriz[i][0]=i;
                matriz[i][j]=matriz[i][0]-j;
            }
            if (i>j&&i>n/2)
            {
                matriz[i][0]=n-i-1;
                if (matriz[i][0]-j>0)matriz[i][j]=matriz[i][0]-j;
            }
            if (j>i&&j<=n/2&&i<=n/2)
            {
                matriz[i][j]=j-i;
            }
            if (j>i&&j>n/2&&i<n/2)
            {
                if(matriz[i][n/2]+(n/2-j)>0)matriz[i][j]=matriz[i][n/2]+(n/2-j);
            }
            if (j>i&&j>n/2&&i<=n/2)
            {
                if(matriz[i][n/2]+(n/2-j)<0)matriz[i][j]=(j+i+1)-n;
            }
            if (j>i&&j>=n/2&&i>n/2)
            {
                matriz[i][j]=j-i;
            }
            if (i>j&&i>n/2&&j<=n/2)
            {
                if(j+i-n+1>=0)matriz[i][j]=j+i-n+1;
            }
            if (i>j&&j>n/2)
            {
                matriz[i][j]=matriz[i][n/2]-j+n/2;
            }
        }
    }
    return matriz;
}
int main()
{
    int matriza,i=0,j=0,n,matriz[50][50]= {0};
    scanf("%d",&n);
    telhado(n,matriz);
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
