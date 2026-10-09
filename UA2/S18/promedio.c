//promedio.c genmera promedio de notas enteras

#include <stdio.h>

int main(void){
  //3 notas enteras y su suma 
  int nota1, nota2, nota3, suma;
  //Dos resultados reales para comparar
  double promedioMal, promedioBien;

  //ENTRADAS: Notas 80, 75 y 90
  printf("Digite las 3 notas: ");
  scanf("%d %d %d", &nota1, &nota2, &nota3);

  //PROCESOS: Suma de enteros -> 245
  suma = nota1 + nota2 + nota3;
  //int / int = divicion entera: 245 / 3 = 81, se guarde como 81.0
  promedioMal = suma / 3;
  //(double) convierte suma 245.0 antes de dividir -> 81.6666.....
  promedioBien = (double) suma / 3;

  //SALIDA:  sin casting 81.0 y con casting 81.67
  printf("Sin casting: %.2f\n", promedioMal);
  printf("Con casting: %.2f\n", promedioBien);
  return 0;

}