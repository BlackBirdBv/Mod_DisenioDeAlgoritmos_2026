#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {
/*  error: La funcion recibia puntos por valor y usaba scanf incorrectamente en el main
    porque: los argumentos se pasan por copia por lo que modificar puntos dentro de la funcion no afectaba a la variable original del main
    correccion: se cambia el parámetro 'puntos' a un puntero (*puntos) para poder modificar su valor en la memoria */
    *puntos = *puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
/*      error: scanf("%d", compra);
        porque: scanf requiere la dirección de memoria de la variable donde se guardará el dato, no su valor actual. falta el operador '&'.
        correccion: Se agrega el operador de dirección (&) quedando scanf("%d", &compra);*/
        scanf("%d", &compra);
/*      error: sumarPuntos(puntos, compra);
        porque: como la función ahora espera un puntero para poder actualizar los puntos, debemos pasar la dirección de la variable puntos
        correccion: se pasa la direccion utilizando el operador '&': sumarPuntos(&puntos, compra);*/
        sumarPuntos(&puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}