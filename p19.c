#include<stdio.h>
#include<stdlib.h>

int main(){
    char matriz[4][12]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    int fim,i,j,x,y;
    do{
    fim=1;
    system("cls");
    printf("   ");
    for(i=0;i<=35;i++){
        putchar('-');
    }
    printf("\n");
    for (i=0;i<4;i++){
            printf("%d ",i+1);
            printf("| ");
        for(j=0;j<12;j++){
            if(j!=0)printf(" ");
            //if(j>=10)printf(" ");
            printf("%c ",matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("   ");
    for(i=0;i<=35;i++){
        printf("-");
    }
    printf("\n");
    printf("    ");
    for(i=1;i<=12;i++){
        printf("%d ",i);
    if(i<9)printf(" ");
    }
    i=0;
    do{
    x=0;y=0;
    printf("\nDigite a cadeira desejada, fileira depois coluna, os lugares com X ja estam ocupados: ");
    scanf("%d%d",&x,&y);
    if (x<1||x>4||y<1||y>12){printf("ERRO... Lugar inexistente\n");i=0;}
    else{
            if(matriz[x-1][y-1]=='X'){printf("ERRO... Lugar ocupado\n");i=0;}else i=1;
        }
    }while(i==0);
    matriz[x-1][y-1]='X';
    for (i=0;i<4;i++){
        for(j=0;j<12;j++){
            if(matriz[i][j]=='0')fim=0;
        }
    }
    }while(fim==0);
    printf("\nTodos os lugares foram preenchidos\n");
    return 0;
}
