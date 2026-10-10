#include <stdio.h>

#define BONO 5000.0

int main(void){

  //Variables
  double horas, pagoHora, salario;

  //Entrada
  printf("Horas trabajadas en la semana: ");
  scanf("%lf", &horas);

  printf("Pago por hora: ");
  scanf("%lf", &pagoHora);

  //Porceso
   salario = horas * pagoHora + BONO;

  //Salidad
  printf("-------------------------\n");
  printf("Horas:         %10.2f\n",horas);
  printf("Pago por hora: %10.2f\n",pagoHora);
  printf("Bono:          %10.2f\n",BONO);
  printf("Pago semanal:  %10.2f\n",salario);
  printf("-------------------------\n");
  return 0;

}