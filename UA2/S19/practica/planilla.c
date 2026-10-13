#include <stdio.h>

int main(void){

  //Variables
  double horas, tarifa, horasExtra, pago;
  int cantidad, i; 
  char nombre[10];
  double totalPlanilla = 0;
  int conExtra = 0;

  //Entrada

  printf("Cantidad de personas colaboradoras: ");
  scanf("%d", &cantidad);

  for (i = 0; i < cantidad; i++) {
    //Recibe nombre
    printf("Nombre: ");
    scanf("%9s", nombre);
    //inicia ciclo de validacion de horas 
    do {
      printf("Horas de la semana (0 a 72): ");
      scanf("%lf",&horas);
      //Validacion
      if (horas < 0 || horas > 72) {
        printf("Dato inválido, intente de nuevo\n");
      }  
    //fin de ciclo
    } while (horas < 0 && horas > 72);
    
    printf("Tarifa por hora: ");
    scanf("%lf",&tarifa);
    //validacion de horas extra 
    if (horas > 48) {
      horasExtra = horas - 48; 
      pago = 48 * tarifa + horasExtra * tarifa * 1.5; 
      conExtra += 1;
    } else {
      pago = horas * tarifa; 
    }
    //Salida empledo y pago
    printf("%s : %.2f\n",nombre,pago);
    //operacion de planilla
    totalPlanilla = totalPlanilla + pago; 
  }
  //Salida final
  printf("Total de la planilla: %.2f\n",totalPlanilla);
  printf("Personas con horas extra: %d",conExtra);

}