// billetes.c desglose de billetes
#include <stdio.h>

int main(void){
  //definicion de varibles
  int monto, resto, cantidad;

  //ENTRADAS lee monto = 47500
  printf("Mointo a desglosar: ");
  scanf("%d", &monto);

  //PROCESOS division entera 47500 / 20000 -> cantidad = 2
  cantidad = resto / 20000;

  //% es el residuo 475000 % 20000 -> resto =7500
  resto = resto % 20000;

  //Muestre -> billetes de 20000
  printf("Billetes de 20000: %d\n", cantidad);

  cantidad = resto / 10000; //75000 /5000 -> cantidad 0
  //forma compacta de resto = resto % 10000 -> resto = 7500
  resto %= 10000;
  printf("Billetes de 10000: %d\n", cantidad); //-> 0

  cantidad = resto / 5000; //75000 /5000 -> cantidad 1
  resto %= 5000;
  printf("Billetes de 5000: %d\n", cantidad);

  cantidad = resto / 2000; //75000 /5000 -> cantidad 1
  resto %= 2000;
  printf("Billetes de 10000: %d\n", cantidad); //-> 0

  cantidad = resto / 1000; //75000 /5000 -> cantidad 0
  resto %= 1000;
  printf("Billetes de 1000: %d\n", cantidad); //-> 0

  //lo qur quede se entrega en monedas -> 500
  printf("En monedas: %d\n", resto);
  return 0;
}