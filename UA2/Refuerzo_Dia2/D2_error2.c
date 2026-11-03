#include <stdio.h>
#include <string.h>
int main(void) {
    char placa[10];
    printf("Placa: ");
    scanf("%9s", placa);
    if (strcmp(placa,"FIN") == 0)
        printf("Terminar\n");
    else
        printf("Seguir\n");
    return 0;
}
