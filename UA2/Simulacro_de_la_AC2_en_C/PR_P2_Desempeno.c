#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Constantes
#define CRIT 3

int main(void) {
  // arreglos 
  char criterios[CRIT] [20]= {"puntualidad","calidad","trabajo en equipo"};
  double puntaje[CRIT];
  // Variables
  double puntajes, promedio;
  char nombre[20];
  char nivel[20];
  int i;

  //Entrada nombre
  printf("=== Evaluacion de desempeno ===\n");
  printf("Nombre del colaborador: ");
  fgets(nombre,sizeof(nombre),stdin);
  nombre[strcspn(nombre, "\n")] = '\0';

  for ( i = 0; i < CRIT; i++) {
    //validacion de rango de (0 a 10)
    do {
      //entrada puntajes
      printf("Puntaje de %s (0 a 10): ",criterios[i]);
      scanf("%lf",&puntaje[i]);
      //mensaje de fuera de rango
      if (puntaje[i] < 0 || puntaje[i] > 10) {
        printf("\t Puntaje invalido, debe estar entre 0 y 10\n");
      }
      //repite si se sale de rango
    } while (puntaje[i] < 0 || puntaje[i] > 10);
    puntajes += puntaje[i];
  }
  
  //opreracion promedio
  promedio = puntajes / CRIT;

  //Nivel validacion de que tan bueno es o si le falta mejorar
  if (promedio >= 9) {
    strcpy(nivel, "EXCELENTE");
  } else if (promedio < 9 && promedio >= 7){
    strcpy(nivel, "BUENO");
  } else {
    strcpy(nivel, "NECESITA MEJORAR");
  }

  //Salidas datos 
  printf("\n");
  printf("Colaborador: %s\n",nombre);
  printf("Promedio: %7.2f\n",promedio);
  printf("Nivel: %15s\n",nivel);

  //puntaje mas bajo por condiciones
  if (puntaje[0] < puntaje[1] && puntaje[0] < puntaje[2]){
    printf("Puntaje mas bajo: %s (%.1f)\n",criterios[0],puntaje[0]);
  } else if (puntaje[1] < puntaje[2] && puntaje[1] < puntaje[0]) {
    printf("Puntaje mas bajo: %s (%.1f)\n",criterios[1],puntaje[1]);
  } else {
    printf("Puntaje mas bajo: %s (%.1f)\n",criterios[2],puntaje[2]);
  }
  
  system("pause");
  return 0;

}