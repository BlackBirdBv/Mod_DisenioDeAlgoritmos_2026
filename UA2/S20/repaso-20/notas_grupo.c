//notas_grupo.c matriz recorrida por filas y columnas, busqueda con strcmp
// Un docente quiere organizar las notas de un grupo pequeño. Escriba un programa en C que: 
// 1. Pida el nombre (una palabra) de 4 estudiantes y sus notas en 3 evaluaciones (de 0 a 100). 
// Una nota inválida muestra un mensaje y se vuelve a pedir. 
// 2. Guarde las notas en una matriz de 4 filas (estudiantes) por 3 columnas (evaluaciones). 
// 3. Muestre una tabla con el nombre, las tres notas y el promedio de cada estudiante (dos 
// decimales). 
// 4. Muestre el promedio de cada evaluación (columna) y el estudiante con mejor promedio. 
// 5. Al final, pida un nombre y búsquelo: si está, muestre su promedio y su condición (APROBADO 
// con 70 o más; si no, NO APROBADO); si no está, muéstrelo con un mensaje.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defines y limites 
#define EST 4
#define NOTA 3

int main(void){
  //============= ARREGLOS =============
  //arreglo para guardar los nombres
  char nombres[EST][15];
  //arreglo para almacenar nota 
  int notas[EST][NOTA];
  //arreglo para guardar los promedios
  float promedios[EST];

  //============ VARIABLES ============
  //contador de for para estudiantes 
  int e;
  //contador de for para notas 
  int n;
  //para sacar los promedios
  float promedio;

  //Entradas de datos
  printf(" === Notas del grupo === \n");
  //for para guardar en los arreglos 
  for (e = 0; e < EST; e++) {
    //reset de variable
    promedio = 0;
    //para guardar los nombre
    printf("Nombre del estudiante %d: ",e+1);
    scanf("%14s",nombres[e]);
    for (n = 0; n < NOTA; n++) {
      //para guardar las notas 
      printf("\t Nota %d de %s: ", n+1, nombres[e]);
      scanf("%d",&notas[e][n]);
      //suma todas las notas
      promedio += notas[e][n];
    }
    //divide el promedio con la cantidad de notas 
    promedio = promedio / NOTA;
    //guarda el promedio dentro del arreglo
    promedios[e] = promedio;
  }
  
  //Salidas de datos y resumen 
  //tabla de informacion titulos 
  printf("%-14s%3s%3s%3s%10s\n","Nombre","N1","N2","N3","Promedio");
  for (e = 0; e < EST; e++) {
    //muesta los nombre
    printf("%-14s",nombres[e]);
    //muestra las notas 
    for (n = 0; n < NOTA; n++) {
      printf("%3d",notas[e][n]);
    }
    //muestra los promedios
    printf("%10.2f\n",promedios[e]);
  }
  
  system("pause");
  return 0;

}