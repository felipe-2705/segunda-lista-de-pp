#include <stdio.h>
#include <string.h>

#define max 100
 int p_num(int,char s[max]);

 int p_num(int p, char s[max]){
 int i,count=0;

 for(i=0;i<strlen(s);i++){

    if(s[i]>=48 && s[i]<=57){
        count++;
        if(count==p){
                return s[i]-48;
        }

    }

 }

return -1;

 }
 int main(){
 char s[max];
 int p;

 printf("digite uma texto :");
 scanf("%[^\n]s",s);
 printf("digite o n-esimo numero desejado:");
 scanf("%d",&p);
while(p>strlen(s)){
    printf("erro...posicao superior ao numero de caracteres totais do texto!!");
    printf("digite novamente :");
    scanf("%d",&p);
}
if(p_num(p,s)== -1){
    printf("nao existe o numero da posiçao desejada.");
}

else{
 printf("o numero da posicao %d eh :%d",p,p_num(p,s));
 }
 return 0;}
