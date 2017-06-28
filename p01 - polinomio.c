#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int menu();
void leia(int n, int V[n+1], int U[n+1]);
void printar(int n, int V[n+1], int U[n+1]);
void calcular(int n, int V[n+1], int U[n+1]);
void soma(int n, int V[n+1], int U[n+1]);
void sub(int n, int V[n+1], int U[n+1]);

int main(int argc, char *argv[])
{
    int n, i, x;
    printf("Digite o grau dos polinomios: ");
    scanf("%d",&n);

    int V[n+1], U[n+1];
    x = menu();
    while(x != 6){
    switch (x)
    {
    case 1:
        leia(n, V, U);
        break;
    case 2:
        printar(n, V, U);
        break;
    case 3:
        calcular(n, V, U);
        break;
    case 4:
        soma(n, U, V);
        break;
    case 5:
        sub(n, U, V);
        break;
    case 6:
        exit(1);
        break;
    }
    x = menu();
    }
    return 0;
}

int menu(){
    int x = 0;
    printf("Escolha a opcao que voce deseja: \n\n");
    printf("1: Ler polinomio do dispositivo padrao de entrada (teclado).\n");
    printf("2: Escrever polinomio no dispositivo padrao de saida (tela de display).\n");
    printf("3: Calcular o valor do polinomio p(x) em um determinado ponto x.\n");
    printf("4: Somar dois polinomios e apresentar o polinomio resultante.\n");
    printf("5: Subtrair dois polinomios e apresentar o polinomio resultante.\n");
    printf("6: Sair\n");
    scanf("%d",&x);
    system("cls");
    if(x >=1 && x <=6){
       return x;
    }else{
        printf("Erro!\n\n");
        return -1;
    }

}
void leia(int n, int V[n+1], int U[n+1]){
        int i;
        printf("Digite o valor dos coeficientes de V: \n");
        for(i=0; i<(n+1); i++)
        {
            printf("V[%d]:",i);
            scanf("%d",&V[i]);
        }
        printf("Digite o valor dos coeficientes de U: \n");
        for(i=0; i<(n+1); i++)
        {
            printf("U[%d]:",i);
            scanf("%d",&U[i]);
        }
}
void printar(int n, int V[n+1], int U[n+1]){
        int i;
        printf("V: \nP(x): ");
        for(i=0; i<(n+1); i++)
        {
            printf("%+d*x^%d ",V[i], i);
        }
        putchar('\n');
        printf("U: \nP(x): ");
        for(i=0; i<(n+1); i++)
        {
            printf("%+d*x^%d ",U[i], i);
        }
        putchar('\n');
}
void calcular(int n, int V[n+1], int U[n+1]){
    int y, x, soma = 0,i;
    printf("Escolha o polinomio que voce deseja calcular: \n");
    printf("1: polinomio V.\n");
    printf("2: polinomio U.\n");
    scanf("%d",&y);
    printf("Digite o valor de x que voce deseja calcular: ");
    scanf("%d",&x);
    if(y==1){
        for(i=0; i<(n+1); i++)
        {
            soma += V[i] * pow(x, i);
        }
        printf("P(%d): %d\n",x,soma);
    }
    if(y==2){
        for(i=0; i<(n+1); i++)
        {
            soma += U[i] * pow(x, i);
        }
        printf("P(%d): %d\n",x,soma);
    }
    if(y!=1 && y!=2){
        printf("Erro!!\n\n");
    }
}
void soma(int n, int V[n+1], int U[n+1]){
        int i, W[n+1];
        for(i=0; i<(n+1); i++)
        {
            W[i] = V[i] + U[i];
        }
        printf("Polinomio resultate \nP(x): ");
        for(i=0; i<(n+1); i++)
        {
            printf("%+d*x^%d ",W[i], i);
        }
        putchar('\n');
}
void sub(int n, int V[n+1], int U[n+1]){
        int i, W[n+1];
        for(i=0; i<(n+1); i++)
        {
            W[i] = V[i] - U[i];
        }
        printf("Polinomio resultate \nP(x): ");
        for(i=0; i<(n+1); i++)
        {
            printf("%+d*x^%d ",W[i], i);
        }
        putchar('\n');
}
