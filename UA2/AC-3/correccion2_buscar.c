#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    /*  error: El bucle utiliza la condición (i <= n).
        porque: los arreglos en se indexan desde 0 hasta n, al usar (<=) provocaba que salga fuera de los limites del arreglo.
        correccion: Cambiar la condicion a (i < n) para recorrer estrictamente las posiciones validas.*/
    for (i = 0; i < n; i++)
    /*  error: Se intenta comparar las cadenas usando (==)
        porque: comparar (==) en arreglos de caracteres compara direcciones de memoria y no el texto
        correccion: Utilizar la funcion strcmp para comparar el contenido de las cadenas*/
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    return -1;
}

int main(void) {
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe\n");
    else
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    return 0;
}
