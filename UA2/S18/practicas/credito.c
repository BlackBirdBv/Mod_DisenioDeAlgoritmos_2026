#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){

  //variables
  double  salario, cuota;
  int antiguedad;
  bool  capacidadPago, tieneDeudas, tieneFiador, aprobado;
  char respDeudas, respFiador;

  //Eantrada de datos 
  printf("Salario mensual: ");
  scanf("%lf", &salario);

  printf("Cuota mensual del credito: ");
  scanf("%lf", &cuota);

  printf("Tiene deudas atrasadas? (S/N): ");
  scanf(" %c", &respDeudas);

  printf("Anios de antiguedad laboral: ");
  scanf("%d", &antiguedad);

  printf("Tiene fiador? (S/N): ");
  scanf(" %c", &respFiador);

  //Operaciones 
  capacidadPago = salario >= (cuota * 3); 
    //de stack overflow y w3school
  tieneDeudas = (toupper(respDeudas) == 'S'); 
  tieneFiador = (toupper(respFiador) == 'S'); 
    //de stack overflow y w3school
  aprobado = capacidadPago && !tieneDeudas && (antiguedad >= 1 || tieneFiador); 

  //Salida
  if (aprobado) {

    printf("---------------------------------\n");
    printf("Salario mensual: %.0f\n",salario);
    printf("Cuota mensual del credito: %.0f\n",cuota);
    printf("Tiene deudas atrasadas? (S/N): %c\n",respDeudas);
    printf("Anios de antiguedad laboral: %d\n",antiguedad);
    printf("Tiene fiador? (S/N): %c\n",respFiador);
    printf("---------------------------------\n");
    printf("        Credito aprobado         \n");
    printf("---------------------------------\n");

  } else {

    printf("---------------------------------\n");
    printf("Salario mensual: %.0f\n",salario);
    printf("Cuota mensual del credito: %.0f\n",cuota);
    printf("Tiene deudas atrasadas? (S/N): %c\n",respDeudas);
    printf("Anios de antiguedad laboral: %d\n",antiguedad);
    printf("Tiene fiador? (S/N): %c\n",respFiador);
    printf("---------------------------------\n");
    printf("        Credito rechazado        \n");
    printf("---------------------------------\n");

  }

  return 0;

}