//inscripcion.c viene de algoritmo inscripcion cursos
#include <stdio.h>
#include <stdbool.h>
#define COSTO_MODULO 15000.00;

int main(void){
    //Cadenas: arreglos de caracteres 
    char nombre[30], cedula[15];
    int cantidadModulos;
    double total;
    //Logica en C 1 Verdadero y 0 Falso
    int tieneDescuento;

    //ENTRADAS
    //pide y almacena el nombre. En el tipo char no se usa "&" para almacnar 
    printf("Nombre: ");
    scanf("%29s", nombre);

    //leer la cedula como texto
    printf("Cedula: ");
    scanf("%14s", cedula);

    //Pedir y almacenar cantidad de modulos 
    printf("Cantidad de modulos: ");
    scanf("%d", &cantidadModulos);

    //PROCESOS total = 3 * 15000 -> 45000
    total = cantidadModulos * COSTO_MODULO;
    //Aa la pregunta tiene descuentos se responde con 1 para si o 0 para no
    tieneDescuento = cantidadModulos >= 3;

    //SALIDAS
    printf("Estudiante: %s (%s)\n", nombre, cedula);
    printf("Total de la inscripcion: %.2f\n", total);
    printf("Aplica para descuento?: %d (1 = si, 0 = no)\n",tieneDescuento);
    return 0;

}