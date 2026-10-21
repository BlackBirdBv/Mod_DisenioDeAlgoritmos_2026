#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EST 3
#define DIAS 4

int main(void){

  // Variables inicializadas
  int d, i, masHoras, estuioMas, mayor, suma = 0;
  int encontrado = -1;
  char nombreBuscado[10];
  
  // Arreglos
  char semana[5][DIAS] = {"Lun","Mar","Mie","Jue"};
  char nombres[EST][10];    
  int horasDia[DIAS] = {0};
  int dias[EST][DIAS];
  int total[EST];

  for (i = 0; i < EST; i++) {
    printf("Nombre del estudiante %d: ", i + 1);
    scanf("%9s",nombres[i]);
    
    for (d = 0; d < DIAS; d++) {
      printf(" Horas del %s: ", semana[d]);
      scanf("%d", &dias[i][d]);
      suma += dias[i][d];
    }
    total[i] = suma;
    suma = 0;
  }

  //para saber quién estudió más
  mayor = -1;
  estuioMas = 0;
  for (i = 0; i < EST; i++) {
    if (total[i] > mayor) {
      mayor = total[i];
      estuioMas = i; // Guarda la posición exacta del estudiante
    }
  }

  // Suma las horas y elige qué día estudiaron más
  for (i = 0; i < DIAS; i++) {
    for (d = 0; d < EST; d++) {
      horasDia[i] += dias[d][i];
    }
  }

  //para saber qué día se estudió más
  mayor = -1;
  masHoras = 0;
  for (i = 0; i < DIAS; i++) {
    if (horasDia[i] > mayor) {
      mayor = horasDia[i];
      masHoras = i; // Guarda la posición exacta del día
    }
  }
  
  // Salidas de tabla
  printf("\n%-8s%6s%6s%6s%6s%8s\n", "Nombre", "Lun", "Mar", "Mie", "Jue", "Total");

  for (i = 0; i < EST; i++) {
    printf("%-8s", nombres[i]);
    for (d = 0; d < DIAS; d++) {
      printf("%6d", dias[i][d]);
    }
    printf("%8d\n", total[i]);
  }
  printf("\n");

  // Salidas de resultados finales
  printf("%-15s%10s%5d horas\n", "Estudio mas:", nombres[estuioMas], total[estuioMas]);
  printf("%-20s%5s%5d horas\n", "Dia con mas horas:", semana[masHoras], horasDia[masHoras]);

  //buscador de estudiante
  printf("\nBuscar estudiante: ");
  scanf("%9s",nombreBuscado);
  // Recorre la lista de nombres almacenados (
  for (i = 0; i < EST; i++) {
    // strcmp devuelve 0 si las cadenas son exactamente iguales
    if (strcmp(nombres[i], nombreBuscado) == 0) {
      encontrado = i; // Guarda posicion
      break;          // sale del ciclo
    }
  }

  //salida busqueda
  printf("%10s%9s%3d horas\n\n",nombres[encontrado],"estudio",total[encontrado]);

  system("pause");
  return 0;
}
