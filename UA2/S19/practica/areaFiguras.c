#include <stdio.h>

#define PI 3.14159265359

int main(void){
  // variables
  int opcion;
  double lado, base, altura, radio, area;

  //inicio de proseso
  do {
    //Menu
    printf("1. Cuadrado");
    printf("\t2. Rectangulo");
    printf("\t3. Circulo");
    printf("\t0. Salir\n");
    printf("Opcion: ");
    //Entrada
    scanf("%d",&opcion);

    //Opciones 
    switch (opcion) {
    case 1:
      //Area de un cuadrado
      printf("Lado: ");
      scanf("%lf",&lado);
      //operacion 
      area = lado * lado;

      printf("Area: %.2f\n", area);
      break;
  
    case 2:
      //Area de un rectangulo
      printf("Base: ");
      scanf("%lf",&base);

      printf("Altura: ");
      scanf("%lf",&altura);
      //operacion
      area = base * altura;

      printf("Area: %.2f\n", area);
      break;

    case 3:
      //Area de un cuadrado
      printf("Radio: ");
      scanf("%lf",&radio);
      //operacion
      area = PI * (radio * radio);

      printf("Area: %.2f\n", area);

      break;

    default:
      //si opcion es diferente
      printf("Opcion invalida\n");
      break;
    }
    // se repite hasta que opcion sea 0
  } while (opcion != 0);

  printf("Hasta luego");

  return 0;
}