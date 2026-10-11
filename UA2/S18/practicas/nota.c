#include <stdio.h>

int main(void){

  //Variables
  double nota;
  
  //Entrada
  printf("Nota: (0 a 100): ");
  scanf("%lf",&nota);

  //Validacion
  if (nota < 0 || nota > 100) {
    printf("Nota invalida");
  } else {
    //Salida
      printf("Nota registrada: %.2f\n",nota);

      if (nota >= 70) {
        printf("<<Aprobado>>");
      } else {
        printf("<<Reprobado>>");
      }
  }

}