#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void leia(int n, double x[n], double y[n]);
double Sxy(int n, double x[n], double y[n], double mediax, double mediay);
double Sxx(int n, double x[n], double mediax);
double media(int n, double x[n]);

int main(int argc, char *argv[]){
    int n=0;
    double Sxy, mediaX, mediaY, Sxx, Syy;
    double correlacao;
    printf("Digite a quantidade de variaveis: ");
    scanf("%d",&n);
    double x[n], y[n];

    leia(n, x, y);
    mediaX = media(n, x);
    mediaY = media(n, y);
    Sxy = (n, x, y, mediaX, mediaY);
    Sxx = (n, x, mediaX);
    Syy = (n, y, mediaY);
    correlacao = Sxy / sqrt( (Sxx*Syy) );
    printf("Correlacao: %.6lf\n",correlacao);
    return 0;
}

void leia(int n, double x[n], double y[n]){
    int i;
    for(i=0;i<n;i++){
        printf("V[%d]: ",i+1);
        scanf("%lf",&x[i]);
    }
    printf("---------------\n");
    for(i=0;i<n;i++){
        printf("V[%d]: ",i+1);
        scanf("%lf",&y[i]);
    }
}
double media(int n, double x[n]){
    double soma=0;
    int i;
    for(i=0;i<n;i++){
        soma += x[i];
    }
    return (soma/n);
}

double Sxy(int n, double x[n], double y[n], double mediax, double mediay){
    double soma=0;
    int i;
    for(i=0;i<n;i++){
        soma += (x[i] - mediax)*(y[i] - mediay);
    }
    return soma;
}
double Sxx(int n, double x[n], double mediax){
    double soma=0;
    int i;
    for(i=0;i<n;i++){
        soma += (x[i] - mediax)*(x[i] - mediax);
    }
    return soma;
}
