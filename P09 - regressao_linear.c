#include<stdlib.h>
#include<stdio.h>


void leia(int n, int x[n], int y[n]);
int Sx(int n, int x[n]);
int Sy(int n, int y[n]);
int Sxy(int n, int x[n], int y[n]);
int Sxx(int n, int x[n]);

int main(int argc, char *argv[]){

    int n=0,sx=0,sy=0,sxy=0,sxx=0,A=0,B=0;

    printf("Digite o numero de cordenadas que voce deseja: ");
    scanf("%d",&n);

    int x[n], y[n];

    leia(n, x, y);
    sx = Sx(n, x);
    sy = Sy(n, y);
    sxy = Sxy(n, x, y);
    sxx = Sxx(n, x);
    if(((n*sxx) - (sx*sx)) != 0){
        A = ((n*sxy) - (sx*sy)) / ((n*sxx) - (sx*sx));
        B = ((sy - (A*sx))/n);
        printf("Y = %+d*X%+d\n",A,B);
    }
    else{
        printf("Nao forma uma reta!!!\n");
    }
    //printf("A: %d\nB: %d\n",A,B);
    return 0;
}

void leia(int n, int x[n], int y[n]){
    int i;
    for(i=0;i<n;i++){
        printf("Cordenada %d: ",i+1);
        scanf("%d %d",&x[i],&y[i]);
    }
}

int Sx(int n, int x[n]){
    int i, soma=0;
    for(i=0;i<n;i++){
        soma += x[i];
    }
    return soma;
}

int Sy(int n, int y[n]){
    int i, soma=0;
    for(i=0;i<n;i++){
        soma += y[i];
    }
    return soma;
}

int Sxy(int n, int x[n], int y[n]){
    int i, soma=0;
    for(i=0;i<n;i++){
        soma += (x[i]*y[i]);
    }
    return soma;
}
int Sxx(int n, int x[n]){
    int i, soma=0;
    for(i=0;i<n;i++){
        soma += (x[i]*x[i]);
    }
    return soma;
}
