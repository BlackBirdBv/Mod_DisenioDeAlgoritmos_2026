#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMI 0.05
#define BONO 50.00
#define RETE 0.02
#define SEMANAS 4

int main(void) {
  //Variables y arreglos 
  double sumatoria, comision, retencion, pago;
  int i;
  char nombre [20];
  double ventas [SEMANAS];

  //entradas de datos
  printf("Nombre del vendedor: ");
  fgets(nombre, sizeof(nombre), stdin);
  nombre[strcspn(nombre, "\n")] = '\0';

  for (i = 0; i < SEMANAS; i++) {
    //Validacion de positivos
    do {
      printf("Ventas de la semana %d: ", i+1);
      scanf("%lf", &ventas[i]);

      if (ventas[i] < 0) {
        printf("El numero ingresado es incorrecto\n");
        printf("Porfavor dijite numeros positivos\n");
      }

    } while (ventas[i] < 0);
    sumatoria += ventas[i];
  }
  
  //Comision 
  comision = sumatoria * COMI;
  //retencion
  retencion = comision + BONO;
  retencion = retencion * RETE;
  //pago
  pago = comision + BONO - retencion;

  //Salida
  printf("------- Pago de %s -------\n",nombre);
  //Semanas 
  for (i = 0; i < SEMANAS; i++) {
    printf("Semana %d: %20.2f\n", i+1, ventas[i]);
  }
  //Mes
  printf("Ventas del mes: %14.2f\n",sumatoria);
  //aplicaiones
  printf("Comision (5%%):   %14.2f\n",comision);
  printf("Bono: %24.2f\n", BONO);
  printf("Retencion (2%%): %15.2f\n",retencion);
  //pago
  printf("Pago del mes: %16.2f\n",pago);
  
  system("pause");
  return 0;

}