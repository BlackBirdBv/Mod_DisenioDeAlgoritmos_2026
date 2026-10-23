//Temperatura.c registro de temperaturas de la semana 
//enunciado: El Instituto Meteorológico registra la temperatura máxima de cada día. Escriba un programa en C que: 
// 1. Pida la temperatura máxima de cada día de la semana, de lunes a domingo (grados C, de 0 a 45). 
//  El mensaje debe mostrar el nombre del día (Lun, Mar, …). Un dato fuera de rango muestra un mensaje y se vuelve a pedir. 
// 2. Guarde las temperaturas en un arreglo de 7 posiciones. 
// 3. Calcule el promedio de la semana y encuentre el día más caluroso. 
// 4. Muestre la temperatura de cada día, el promedio (dos decimales), el día más caluroso y la lista 
//  de días que superaron el promedio con su cantidad. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//definir constantes
#define DIAS 7

int main(void) {
  //==================== ARREGLOS ====================
  //arreglo de dias de la semana 
  char dias[DIAS][4] = {"Lun","Mar","Mie","Jue","Vie","Sab","Dom"};
  //arreglo para almacenar temperaturas por semana
  float temperaturas[DIAS];
  //arreglo de dias por encima de la temperatura promedio
  char sobreTemp[DIAS][4] = {{0}};

  //=================== VARIABLES =================== 
  //guarda el promedio
  double promedio = 0;
  // contador para for 
  int d;
  // guarda el mas caluroso
  int masCaliente = 0;
  //guarada los dias que pasan sobre el promedio de temperatura
  int sobrePromedio = 0;

  //mensaje de ejecucion
  printf("=== Temperaturas de la semana ===\n");
  //for para almacenar temeperaturas 
  for (d = 0; d < DIAS; d++) {
    //valida que no se salga de rango
    do {
      //pide la temperatura
      printf("Temperatura del %d %s (0 a 45): ", d+1, dias[d]);
      scanf("%f",&temperaturas[d]);
      //mensaje si sale de rango
      if (temperaturas[d] > 45 || temperaturas[d] < 0) {
        printf("Error al recibir temperatura...\n");
        printf("porfavor digite una temperatura\n");
        printf("dentro de un rango de (0 a 45)\n\n");
      }
      //repite si se sale de rango
    } while (temperaturas[d] > 45 || temperaturas[d] < 0);
    //suma todas las temperaturas almacenadas
    promedio += temperaturas[d];
  }
  
  //divide las temperaturas sumadas entre los dias
  promedio = promedio / DIAS;

  //para determinar el dia con la temperatura mas alta y los dias que pasan del promedio de temperatura
  for (d = 0; d < DIAS; d++) {
    //campara las temperaturas y guarda la mayor
    if (temperaturas[d] > temperaturas[masCaliente]) {
      masCaliente = d;
    }

    //verifica que la temperatura este por encima del promedio
    if (temperaturas[d] > promedio) {
      //guarda el dia
      strcpy(sobreTemp[d],dias[d]);
      //cuenta los dias
      sobrePromedio++;
    } else {
      sobreTemp[d][0] = '\0';
    }
  }
  
  //Salidas y resumen de analisis
  printf("\n ------- Reporte de la semana ------- \n");
  //muesta los dias con sus temperaturas
  for (d = 0; d < DIAS; d++) {
    printf("%-4s:%6.1f C\n",dias[d],temperaturas[d]);
  }
  //muestra el promedio de temperatura 
  printf("%-20s%.2f C\n","Promedio:",promedio); 

  //muestra el dia mas caluroso 
  printf("%-20s%4s (%.1f C)\n","Mas caluroso:",dias[masCaliente],temperaturas[masCaliente]);

  //muestra los dias que exeden la temperatura promedio
  printf("%-20s","Sobre el promedio:");
  //recorre los dias y solo muestra los que exeden el promedio
  for (d = 0; d < DIAS; d++) {
    // verifica que no este vacia
    if (sobreTemp[d][0] != '\0') {
      printf("%4s",sobreTemp[d]);
    }
  }
  //cantidad de dias
  printf(" (%d dias)\n\n",sobrePromedio);

  system("pause");
  return 0;
}