#include <stdio.h>

#define LIMITE 48
#define RECARGO 1.5 
#define CENTINELA -1

int main(void){

  //Variables
  double tarifa, horasExtra, pago;
  int cantidad = 0; 
  // char nombre[10];
  double totalPlanilla = 0;
  int conExtra = 0;
  double horas = 0;


  //Entrada

  while (CENTINELA != horas) {
    //inicia ciclo de validacion de horas 
    do {
      printf("Horas de la semana (0 a 72) O (-1 para terminar): ");
      scanf("%lf",&horas);
      //Validacion
      if (horas < -1 || horas > 72) {
        printf("Dato inválido, intente de nuevo\n");
      }  
    //fin de ciclo
    } while (horas < -1 || horas > 72);
    
    if (CENTINELA != horas) {
      printf("Tarifa por hora: ");
      scanf("%lf",&tarifa);
      //validacion de horas extra 
      if (horas > LIMITE) {
        horasExtra = horas - LIMITE; 
        pago = LIMITE * tarifa + horasExtra * tarifa * RECARGO; 
        conExtra += 1;
      } else {
        pago = horas * tarifa; 
      }
      //Salida pago
      printf("Pago: %.2f\n",pago);
     //operacion de planilla
      totalPlanilla = totalPlanilla + pago; 
      //cantidad de personas 
      cantidad += 1;
    }
  }
  //Salida final
  printf("Personas: %d\n",cantidad);
  printf("Personas con horas extra: %d\n",conExtra);
  printf("Total de la planilla: %.2f\n",totalPlanilla);

}