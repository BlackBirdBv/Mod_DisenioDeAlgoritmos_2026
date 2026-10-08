// Factura con iva
#include <stdio.h>

int main(void){
    //Constante para IVA
    const double TASA_IVA = 0.13;
    
    //Variables enteras para cantidad y reales para montos
    int cantidad;
    double precio, subtotal, iva, total;

    //Etrada: pedir y almacenar cantidad
    printf("Cantidad: ");
    scanf("%d", &cantidad);

    //leer u double precio = 5000
    scanf("%lf", &precio);

    //PROCESO: int *double -> subtotal = 15000
    subtotal = cantidad * precio;

    //sacamos IVA con la constante -> iva = 1950
    iva = subtotal * TASA_IVA;
    //Total -> 16950
    total = subtotal + iva;

    //SALIDA: usar 2 decimales, 10 espacios
    printf("Subtotal: %10.2f\n", subtotal);
    printf("IVA (13%%): %10.2f\n", iva);
    printf("Total: %10.2f\n", total);
    return 0;

}