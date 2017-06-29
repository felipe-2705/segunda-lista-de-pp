#include<stdio.h>
#include<stdlib.h>
#define dimensao_campo 10
#define numero_minas 10

void imprime_campo(int mina[][dimensao_campo], int jogada[][dimensao_campo], int marcada[][dimensao_campo], int *perdeu);
void le_jogada(int i, int j, int jogada[][dimensao_campo], int marcada[][dimensao_campo]);
void gerar_mina(int mina[][dimensao_campo], int quantidade);
void revelar(int i, int j, int jogada[][dimensao_campo], int marcada[][dimensao_campo]);
void marcar(int i, int j, int marcada[][dimensao_campo], int jogada[][dimensao_campo]);
int vitoria(int mina[][dimensao_campo], int marcada[][dimensao_campo]);

int main()
{
    int perdeu = 0, i, j;

    int mina[dimensao_campo][dimensao_campo] = {0}; //matriz da posição das minas
    int jogada[dimensao_campo][dimensao_campo] = {0}; //matriz que armazena posições ja abertas
    int marcada[dimensao_campo][dimensao_campo] = {0}; //matriz que armazena posições marcadas
    //inicializando o srand
    time_t t;
    srand((unsigned) time(&t));

    gerar_mina(mina, numero_minas); //gera bombas em lugares aleatorios
    imprime_campo(mina, jogada, marcada, &perdeu);
    while(perdeu != 1 && vitoria(mina, marcada) != 1)
    {
        le_jogada(i, j, jogada, marcada);
        imprime_campo(mina, jogada, marcada, &perdeu);
        vitoria(mina, marcada);
    }
    if(perdeu==1)
        printf("Fim do jogo, voce perdeu.\nObrigado por jogar!\n");
    else printf("Parabens, voce venceu.\nObrigado por jogar!\n");

    return 0;
}

void imprime_campo(int mina[][dimensao_campo], int jogada[][dimensao_campo], int marcada[][dimensao_campo], int *perde)
{
    int i, j, nminas;
    system("cls");
    printf("======Campo minado======\n");
    printf("  ");
    for(i = 0; i < dimensao_campo; i++) printf(" %d", i);
    putchar('\n');
    for(i = 0; i < dimensao_campo; i++)
    {
        printf("%c ", 'a'+i);
        for(j = 0; j < dimensao_campo; j++)
        {
            //numero de minas ao redor
            //restrições servem para não verificar fora da matriz
            nminas=0;

            if(mina[i-1][j-1] == 1 && i-1>=0 && j-1>=0) nminas++;
            if(mina[i-1][j] == 1 && i-1 >=0) nminas++;
            if(mina[i-1][j+1] == 1 && i-1>=0 && j+1<dimensao_campo) nminas++;
            if(mina[i][j-1] == 1 && j-1>=0) nminas++;
            if(mina[i][j+1] == 1 && j+1<dimensao_campo) nminas++;
            if(mina[i+1][j-1] == 1 && i+1<dimensao_campo && j-1>=0) nminas++;
            if(mina[i+1][j] == 1 && i+1<dimensao_campo) nminas++;
            if(mina[i+1][j+1] == 1 && i+1<dimensao_campo && j+1<dimensao_campo) nminas++;



            if(jogada[i][j] == 0 && marcada[i][j] == 0) printf(" *");
            else if(jogada[i][j] ==1 && mina[i][j] == 0 && marcada[i][j] == 0)
            {
                if(nminas == 0 ) printf("  ");
                else printf(" %d", nminas);
            }
            else if(marcada[i][j] == 1 && mina[i][j] == 1 && jogada[i][j] == 0) printf(" M");
            else if(jogada[i][j] == 1 && mina[i][j] == 1 && marcada[i][j] == 0)
            {
                printf("-1");
                *perde = 1;
            }
        }
        printf(" %c", 'a'+i);
        putchar('\n');
    }
    printf("  ");
    for(i = 0; i < dimensao_campo; i++) printf(" %d", i);
    putchar('\n');
}

void le_jogada(int i, int j, int jogada[][dimensao_campo], int marcada[][dimensao_campo])
{
    int acao;

    //menu de interação
    printf("\n1- Revelar.\n");
    printf("2- Marcar.\n");
    printf("0- Sair.\n\n");
    scanf("%d", &acao);

    if(acao == 1) revelar(i, j, jogada, marcada);
    else if(acao == 2) marcar(i, j, marcada, jogada);
    else if(acao == 0) exit(1);
    else printf("Comando não reconhecido...\n");
}

void revelar(int i, int j, int jogada[][dimensao_campo], int marcada[][dimensao_campo])
{
    char linha;
    fflush(stdin);
    printf("Digite a letra da linha que deseja revelar: ");
    do
    {
        scanf("%c", &linha);
        fflush(stdin);
        if(!(linha >= 'a' && linha <= 'j')) printf("Tecla invalida...\nOBS: A letra deve ser minuscula.\nDigite a letra da linha que deseja revelar: \n");
    }
    while(!(linha >= 'a' && linha <= 'j'));
    linha -= 'a';
    printf("Digite o numero da coluna que deseja revelar: ");
    scanf("%d", &j);

    //não deixa revelar uma posição marcada
    if(marcada[linha][j] == 0)
    {
        jogada[linha][j] = 1;
    }
}

void marcar(int i, int j, int marcada[][dimensao_campo], int jogada[][dimensao_campo])
{
    char linha;
    fflush(stdin);
    printf("Digite a letra da linha que deseja marcar: ");
    do
    {
        scanf("%c", &linha);
        fflush(stdin);
        if(!(linha >= 'a' && linha <= 'j')) printf("Tecla invalida...\nOBS: A letra deve ser minuscula.\nDigite a letra da linha que deseja marcar: \n");
    }
    while(!(linha >= 'a' && linha <= 'j'));
    linha -= 'a';
    printf("Digite o numero da coluna que deseja marcar: ");
    scanf("%d", &j);

    //não deixa marcar uma posição revelada
    if(jogada[linha][j] == 0)
    {
        if(marcada[linha][j] == 0) marcada[linha][j] = 1;
        else if(marcada[linha][j] == 1) marcada[linha][j] = 0;
    }
}

void gerar_mina(int mina[][dimensao_campo], int quantidade)
{
    int i, j, n, n1;

    for(i=0; i<numero_minas; i++) //o número de vezes que o loop executar, é a quantidade de minas que terá
    {
        //gera minas entre 0 e n
        n = rand()%dimensao_campo;
        n1 = rand()%dimensao_campo;
        mina[n][n1] = 1;
    }
}

int vitoria(int mina[][dimensao_campo], int marcada[][dimensao_campo])
{
    int i, j;

    //testa se o jogador marcou todas as minas
    for(i = 0; i<dimensao_campo; i++)
    {
        for(j=0; j<dimensao_campo; j++)
        {
            if (mina[i][j] != marcada[i][j]) return 0;
        }
    }

    return 1;
}
