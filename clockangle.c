#include <stdio.h>


float clockangle(float,float);
float hourtomin(float);


//calcula o angulo entre os ponteiros (as horas devem estar em minutos.
float clockangle(float h,float m)
{
    float anguloh,angulo;
    float angulom;
//calcula o angulo do ponteiro das horas ,usando regra de tres
h=h+m;
    anguloh = (h*3)/6;
//ponteiro dos minutos
    angulom=m*6;

    if(anguloh>360)anguloh=anguloh-360;

    if (angulom>anguloh)angulo=angulom-anguloh;
    else angulo=anguloh-angulom;
    return angulo;
}

//converte as horas em minutos
float hourtomin(float h)
{
    float convert;
    convert=h*60;
    return convert;
}


int main ()
{
    float m,h;
    float angulo;
    printf ("digite o valor das horas:");
        scanf("%f",&h);
        printf ("digite o valor dos minutos:");
        scanf("%f",&m);
        angulo=clockangle(hourtomin(h),m);
        printf("o angulo dos ponteiros do relogio em :\n");
        printf("%02.0f : %02.0f = %.2f",h,m,angulo);
        return 0;
    }
