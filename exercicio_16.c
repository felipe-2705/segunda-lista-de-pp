#include <stdio.h>
#include <stdlib.h>

void combina(int k, int n);
void recursiva(int n, int k,  int vet_res[], int inicio, int atual);

int main()
{
    int k, n;
    printf("Digite o valor para n: ");
    scanf("%d", &n);
    printf("Digite o valor para k: ");
    scanf("%d", &k);
    if(n>=k) combina(k, n);
    else printf("Valores invalidos.\n");

    return 0;
}

void combina(int k, int n)
{
    int vet_res[k];

    recursiva(n, k, vet_res, 0, 0);
}

void recursiva(int n, int k, int vet_res[], int inicio, int atual)
{
    int i, j;

    if (atual == k)
    {
        for (j=0; j<k; j++)
            printf("%d ", vet_res[j]);
        printf("\n");
        return;
    }
    else
    {
        for (i=inicio; i<n; i++)
        {
            vet_res[atual] = i+1;
            recursiva(n, k, vet_res, i+1, atual+1);
        }
    }
}
