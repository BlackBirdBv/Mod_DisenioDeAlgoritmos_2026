#include <stdio.h>

#define MINIMO 50000.0

int main(void){

  //Constante
  const double TASA = 0.10;

  //Variables
  double  compra, descuento, total;

  //Entrada
  printf("Monto de la compra: ");
  scanf("%lf", &compra);

  //validacion
  if (compra >= MINIMO) {
    descuento = compra * TASA;
  } else {
    descuento = 0;
  }
  
  //operacion
  total = compra - descuento;

  // Salida
  printf("Monto de la compra: %.0f\n",compra);
  printf("Descuento: %.2f\n",descuento);
  printf("Total a pagar: %.2f\n",total);

}