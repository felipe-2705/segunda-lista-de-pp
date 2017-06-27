#include <stdio.h>
#include <math.h>
#define erro 0.0000001//margem de erro desejada

float f(float);
float get_raizes(float,float);
double bissecao(float,float);

int main ()
{
    float a,b,aux;
    printf("f(x)= -5x^2+12x^4+2x^2+x-12\n\n");
    printf("digite o intervalo em que se deseja verificar as raizes:");
    scanf ("%f",&a);
    scanf ("%f",&b);

    while(f(a)*f(b)>0)
    {
        printf("intervalo nao possui raiz ,digite outro intervalo :\\n");
        scanf ("%f %f",&a,&b);
    }
    if (a>b){
        aux=b;
        b=a;
        a=aux;
    }
    printf("a raiz a proximada eh :%lf",bissecao(a,b));
}
float get_raizes(float a,float b)
{
    float c;
    c= (a+b)/2;
    return c;
}
double bissecao (float a, float b )
{
    double n,c;//n maximo de repetiçoes
int i=0;
n=(log(b-a)-log(erro))/2;

    while(i<=n)
    { c=get_raizes(a,b);

        if(f(c)==0){
            return c;
        }
        else {
            if (f(c)< 0 && f(a)>0 || f(c)>0 && f(a)<0){
                b=c;

            }
            else{
                if(f(c)<0 && f(b)> 0|| f(c)>0 && f(b)<0){
                    a=c;

                }
            }
        }
i++;
    }
    return c;
}

float f(float x)
{
    //funçao escolhida
    float y;
  y=-5*pow(x,5)+12*pow(x,4)-2*pow(x,2)+x-12;
    return y;
}
