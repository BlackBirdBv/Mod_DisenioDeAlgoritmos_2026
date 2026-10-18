#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definiciones
#define EST 3
#define DIAS 4

int main(void){

  //Variables 
  int d, i, horas, hTotal, suma = 0;
  // arreglos
  char semana[DIAS] [5] = {"Lun","Mar","Mie","Jue"};
  char nombres[EST] [10];
  int dias[DIAS] [EST];
  int total[EST];

  for (i = 0; i < EST; i++) {
    // Entrada nombre
    printf("Nombre del estudiante %d: ",i+1);
    scanf("%9s",nombres[i]);
    
    for (d = 0; d < DIAS; d++) {
      //entrada de horas estudiadas por dia
      printf(" Horas del %s: ",semana[d]);
      scanf("%d",&dias[i][d]);
      suma += dias[i][d];
    }
    total[i] = suma;
    suma = 0;
  }
  
  // Salidas de tabla
  printf("Nombre    Lun    Mar   Mie   Jue   Total\n");

  for (i = 0; i < EST; i++) {
    //salida nombre
    printf("%-8s",nombres[i]);
    for (d = 0; d < DIAS; d++) {
      //salida horas
      horas = dias[i][d];
      printf("%6d",horas);
    }
    hTotal = total[i];
    //salida total horas
    printf("%8d", hTotal);
    printf("\n");
  }

  system("pause");
  return 0;

}