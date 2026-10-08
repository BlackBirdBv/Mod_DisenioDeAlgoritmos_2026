//area.c - saca el area de un rectangulo

#include <stdio.h>

int main(void){
    //declarar variables reales double
    double base, altura, area;

    //Entrada de datos, lee base = 5
    printf("Digite la base del rectangulo (cm): ");
    scanf("%lf", &base);

    //mensaje y lee altura = 3

    printf("Digite la altura del rectangulo (cm): ");
    scanf("%lf", &altura);

    // Proceso: multiplica y guarda el resultado = 15

    area = base * altura;

    //Salida: muestra el area del rectangulo 
    printf("El area del rectangulo es: %.2f cm2\n", area);
    return 0;


}