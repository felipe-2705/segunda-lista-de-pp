#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char wordreverse (){
int i;
char string[100];

printf("Digite a string: \n");
scanf("%s" , string);

printf("\nEntrada: %s\n" ,string);
printf("Saida: ");
for (i= strlen(string) - 1;i>=0;i--){
    printf("%c", string[i]);
}
printf("\n");

return 0;
}

int main()
{
    wordreverse();
    return 0;
}
