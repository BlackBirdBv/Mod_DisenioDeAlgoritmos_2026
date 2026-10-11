#include <stdio.h>
#include <stdbool.h>

int main(void){

  //Variables 
  int anio;
  bool esBisiesto;

  //Entrada
  printf("Escriba el anio: ");
  scanf("%d",&anio);

  //operacion
  esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

  //Salida
  if (esBisiesto) {
    printf("%d Es bisiesto", anio);
  } else {
    printf("%d No es bisiesto", anio);
  }

  return 0;
}