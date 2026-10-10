#include <stdio.h>

int main(void){

  //variables 
  double horas, tarifaHora, bruto, deduccion, neto;

  //Entrada 
  printf("Ingrese las horas trabajdas: \n");
  scanf("%lf", &horas);

  printf("Ingrese pago por hora: \n");
  scanf("%lf", &tarifaHora);

  //Operaciones
  bruto = horas * tarifaHora;
  deduccion = bruto * 0.10; 
  neto = bruto - deduccion;

  //Salida
  printf("Horas trabajadas: %0.f\n", horas);
  printf("Pago por hora:  %0.f\n", tarifaHora);
  printf("Salario bruto: %.2f\n", bruto);
  printf("Deduccion: %.2f\n", deduccion);
  printf("Salario neto: %.2f\n", neto);
  
  return 0;

}