#include <stdio.h>

int main(void){
  //Variables
  int i, j, cantidadFilas;
  //inicializada
  int cont = 1;

  //Entrada 
  printf("Cantidad de filas: ");
  scanf("%d", &cantidadFilas);

  //ciclo de estructura trianulo con *
  for (i = 0; i < cantidadFilas; i++) {
    for (j = 0; j < cont; j++) {
      printf("*");
    }
    printf("\n");
    cont += 1;
  }

  //Reseteo variable
  cont = 1;

  //Segundo ciclo de triangulo con numeros
  for (i = 0; i < cantidadFilas; i++) {
    for (j = 0; j < cont; j++) {
      printf("%d",j+1);
    }
    printf("\n");
    cont += 1;
  }
}