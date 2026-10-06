#include <stdio.h>

int main(void){
  int numero;
  int cociente;
  int b0, b1, b2, b3;

  //ENTRADA: Lee el numero  -> numero = 13

  prinf("Numero decimal (0  a 15)");
  scanf("%d", &numero);

  //VALIDACION: con 4 bits solo se representan los valores de 0 a 15 
  if (numero < 0 || numero >15) {
    prinf("Fuera de rango: use un  numero de 0 a 15\n");
    return 1;
  }

  //Se empieza dividiendo el nuemro completo -> conciente = 13
  cociente =  numero;
  
  //Divicion entre 1: el reciduo es el bit de las unidades -> b0 = 1
  b0 = cociente % 2;

  //Muestra el paso de 13 / 2 = 6 residuo 1 
  printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b0);

  // El cociente pasa a la divicion cociente = 6 

  //Muestra divicion 2: 6/2 = 3 residuo 0 b1 = 0
  b1 = cociente % 2;

  //Muestra el paso de 13 / 2 = 6 residuo 2
  printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b1);

  //Muestra divicion 2: 3/2 = 1 residuo 0 b1 = 0
  b2 = cociente % 2;

  //Muestra el paso de 13 / 2 = 6 residuo 3
  printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b2);

  //Muestra divicion 2: 1/2 = 1 residuo 0 b1 = 0
  b3 = cociente % 2;

  //Muestra el paso de 13 / 2 = 6 residuo 3
  printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b3);


  //RESULTADO: Los residuos se leen de abajo hacia arriba  -> 1101
  
  printf("En biario: %d%d%d%d\n", b3, b2, b1, b0);

  //COMPROBACION: %o muestra en octal y %X en decimal <> 15 y D

  printf("Comprobacion: octal %o, hexadecimal %X\n", numero, numero);

  return 0;

}