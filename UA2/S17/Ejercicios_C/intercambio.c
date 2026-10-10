#include <stdio.h>

int main(void){

  //Variables
  int a, b, aux;

  a = 5;
  b = 9;

  //operacion
  aux = a;
  a = b;
  b = aux;

  //Salida
  printf("Antes:   a = %d  b = %d\n",b,a);
  printf("Despues: a = %d  b = %d\n",a,b);

}