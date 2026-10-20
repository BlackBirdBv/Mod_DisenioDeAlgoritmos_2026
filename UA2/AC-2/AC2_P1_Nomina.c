// Una empresa de consultoría necesita calcular el salario neto de sus empleados. Escriba un programa en C que: 
// 1. Reciba el nombre completo del empleado (puede tener espacios; no se acepta un nombre vacío). 
// 2. Reciba el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a pedir. 
// 3. Calcule los descuentos sobre el salario bruto: CAJA (9.5 %), IESS (2.5 %) e impuesto sobre la 
// renta (10 %, solo si el salario bruto supera 800). 
// 4. Calcule el salario neto (bruto menos todos los descuentos). 
// 5. Muestre un comprobante con el nombre, el salario bruto, cada descuento y el salario neto, con 
// dos decimales y los montos alineados.

//librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//constantes
#define CAJA 0.095
#define IESS 0.025
#define RENTA 0.10
#define LIMITE 800

int main(void) {
  //Variables 
  char nombre [20];
  double salarioBruto, salarioNeto, restCaja, restIess, restRenta;

  //Entadaas de datos 
  printf(" === Calculo de nomina === \n");
  //valida que el campo no este vacio
  do {
    printf("Nombre del empleado: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    if (nombre[0] == '\0') {
      printf("Por favor escriba el nombre del empleado\n");
    }
  } while (nombre[0] == '\0');
  
  //Validacion para que salario sea mayor que 0 
  do {
    printf("Salario bruto: ");
    scanf("%lf",&salarioBruto);
    //mensaje de validacion
    if (salarioBruto < 1) {
      printf("El salario no puede ser igual o menor que cero.\n");
      printf("por favor digite una cifra correcta...\n");
    }
  //se repite
  } while (salarioBruto < 1);

  //operaciones  
  //rebajo caja
  restCaja = salarioBruto * CAJA;
  // rebajo IESS
  restIess = salarioBruto * IESS;
  // si supera los 800 se rebaja impuestos tambien
  if (salarioBruto > LIMITE) {
    restRenta = salarioBruto * RENTA;
  } else {
    restRenta = 0;
  }

  // Calculo salario neto
  salarioNeto = salarioBruto - restCaja - restIess - restRenta;

  //Salida de datos Informe de operaciones 
  printf(" ------- Comprobante de pago ------- \n");
  printf("%-20s%19s\n","Empleado:",nombre);
  printf("%-20s%19.2f\n","Salario bruto:",salarioBruto);
  printf("%-20s%17.2f\n","Descuento CAJA (9.5%):",restCaja);
  printf("%-20s%17.2f\n","Descuento IESS (2.5%):",restIess);
  printf("%-20s%18.2f\n","Impuesto renta (10%):",restRenta);
  printf("%-20s%19.2f\n","Salario neto: ",salarioNeto);

  system("pause");
  return 0;
}