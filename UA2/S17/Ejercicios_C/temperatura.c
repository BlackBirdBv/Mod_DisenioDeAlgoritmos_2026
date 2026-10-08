#include <stdio.h>

int main(void){
    //Variables
    double celsius, fahrenheit;

    //Entrada
    printf("Temperatura en grados Celsius: ");
    scanf("%lf", &celsius);

    //Proceso
    fahrenheit = celsius * 9 / 5 + 32;

    //Salida
    printf("%.2f C equivalen a %.2f F\n", celsius, fahrenheit);

    return 0;
}