#include <stdio.h>

int sumarPuntos(int puntos, int compra) {
    puntos = puntos + compra / 1000;
    return puntos;
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", &compra);
        puntos = sumarPuntos(puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
