#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void cent(char i,char j,char k)
{
    if (i=='0'&&j=='0'&&k=='0');
    else
    {
        switch (i)
        {
        case '1':
            if (j=='0'&&k=='0')printf("cem ");
            else printf("cento ");
            break;
        case '2':
            printf("duzentos ");
            break;
        case '3':
            printf("trezentos ");
            break;
        case '4':
            printf("quatrocentos ");
            break;
        case '5':
            printf("quinhentos ");
            break;
        case '6':
            printf("seiscentos ");
            break;
        case '7':
            printf("setecentos ");
            break;
        case '8':
            printf("oitocentos ");
            break;
        case '9':
            printf("novecentos ");
            break;
        case '0':
            break;
        default:
            break;
        }
        if (j=='0'||i=='0');
        else printf("e ");
        switch (j)
        {
        case '1':
            if (k=='0')printf("dez ");
            else if (k=='1')printf("onze ");
            else if (k=='2')printf("doze ");
            else if (k=='3')printf("treze ");
            else if (k=='4')printf("quatorze ");
            else if (k=='5')printf("quinze ");
            else if (k=='6')printf("deseseis ");
            else if (k=='7')printf("desesente ");
            else if (k=='8')printf("dezoito ");
            else if (k=='9')printf("dezenove ");
            break;
        case '2':
            printf("vinte ");
            break;
        case '3':
            printf("trinta ");
            break;
        case '4':
            printf("quarenta ");
            break;
        case '5':
            printf("cinquenta ");
            break;
        case '6':
            printf("sessenta ");
            break;
        case '7':
            printf("setenta ");
            break;
        case '8':
            printf("oitenta ");
            break;
        case '9':
            printf("noventa ");
            break;
        case '0':
            break;
        }
        if((k!='0'&&j!='1')&&(!(i=='0'&&j=='0')))printf("e ");
        switch (k)
        {
        case '1':
            if(j!='1')printf("um ");
            break;
        case '2':
            if(j!='1')printf("dois ");
            break;
        case '3':
            if(j!='1')printf("tres ");
            break;
        case '4':
            if(j!='1')printf("quatro ");
            break;
        case '5':
            if(j!='1')printf("cinco ");
            break;
        case '6':
            if(j!='1')printf("seis ");
            break;
        case '7':
            if(j!='1')printf("sete ");
            break;
        case '8':
            if(j!='1')printf("oito ");
            break;
        case '9':
            if(j!='1')printf("nove ");
            break;
        case '0':
            break;
        }
    }
}
int main(int argc,char *argv[])
{
    int i,j,tamanho,add0;
    char extenso[50];
    char numero[50];
    strcpy(numero,argv[1]);
    tamanho=strlen(numero);
    if (strlen(numero)%3!=0)
    {
        add0=3-strlen(numero)%3;
        for(j=0; j<add0; j++)
        {
            for(i=tamanho+j-1; i>=0; i--)
            {
                numero[i+1]=numero[i];
                numero[tamanho+j+1]='\0';
            }
            numero[0]='0';
        }
    }
    tamanho=strlen(numero);
    if (tamanho>6)
    {
        cent(numero[tamanho-9],numero[tamanho-8],numero[tamanho-7]);
        if (!(numero[tamanho-9]=='0'&&numero[tamanho-8]=='0'&&numero[tamanho-7]=='0'))
        {
            if (numero[tamanho-9]=='0'&&numero[tamanho-8]=='0'&&numero[tamanho-7]=='1')printf("milhao ");
            else printf("milhoes ");
            if ((numero[tamanho-6]=='0'||(numero[tamanho-4]=='0'&&numero[tamanho-5]=='0'))&&(!(numero[tamanho-4]=='0'&&numero[tamanho-5]=='0'&&numero[tamanho-6]=='0')))printf("e ");
        }
    }
    if (tamanho>3)
    {
        cent(numero[tamanho-6],numero[tamanho-5],numero[tamanho-4]);
        if (!(numero[tamanho-4]=='0'&&numero[tamanho-5]=='0'&&numero[tamanho-6]=='0'))printf("mil ");
        if ((numero[tamanho-3]=='0'||(numero[tamanho-1]=='0'&&numero[tamanho-2]=='0'))&&(!(numero[tamanho-1]=='0'&&numero[tamanho-2]=='0'&&numero[tamanho-3]=='0')))printf("e ");
    }
    cent(numero[tamanho-3],numero[tamanho-2],numero[tamanho-1]);
    printf("\n");

    return 0;
}
