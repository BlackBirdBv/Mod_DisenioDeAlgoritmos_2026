#include <stdio.h>

int main(void){

  //Variables 
  int cantidad, i;
  double nota, promedio;
  //inicializadas
  double suma = 0;

  //Validacion de rango (1-10) 
  do {
    printf ("Cuantas notas va a digitar?: ");
    scanf("%d", &cantidad);
    //mensaje de validacion 
    if (cantidad < 1 || cantidad > 10) {
      printf ("------------------------------------\n");
      printf ("Notas fuera de rango\n");
      printf ("Porfavor digite la cantidad de notas\n");
      printf ("entre (1 a 10) por favor\n");
      printf ("------------------------------------\n");
    }
    //repite 
  } while (cantidad < 1 || cantidad > 10);

  //operacion de guadado de notas
  for (i = 0; i < cantidad; i++) {
    //Validacion de notas en rango (0 a 100)
    do {
      //entrada de notas
      printf("Nota %d: \n",i+1);
      scanf("%lf", &nota);

      //mensaje de validacion 
      if (nota < 0 || nota > 100) {
        printf ("-----------------------------\n");
        printf ("Notas fuera de rango\n");
        printf ("Porfavor digite notas validas\n");
        printf ("entre (0 a 100) por favor\n");
        printf ("-----------------------------\n");
      }
      //repite 
    } while (nota < 0 || nota > 100);
    //se suma la nota
    suma = suma + nota;
  }
  
  //Operacion de promedio
  promedio = suma / cantidad; 

  //Salida
  printf("Suma: %.2f\n",suma);
  printf("Promedio: %.2f\n",promedio);

}