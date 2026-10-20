#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Constantes
#define ESP 2
#define LIMITE 10
#define CENTINELA "FIN"
#define DESCUENTO 0.10
#define IVA 0.13
#define ENVIO 8.0


int main(void){
  //arreglos
  char titulos[LIMITE] [20];
  double datos[ESP] [10];
  double subtotal[10];

  //Variables
  double totalLibros = 0;
  double restDescuento, restIVA;
  double total = 0;
  int unidades = 0;
  int carrito = 0;
  int i = 0;


  //Entrada datos
  printf("Titulo del libro (FIN para terminar): ");
  fgets(titulos[i], sizeof(titulos[i]), stdin);
  titulos[i][strcspn(titulos[i], "\n")] = '\0';

  while (strcmp(titulos[i],CENTINELA)) {
    //validacion positivos
    do {
      //Entrada de precio y cantidad de libros 
      printf("Precio: ");
      scanf("%lf",&datos[0][i]);
      printf("Cantidad: ");
      scanf("%lf",&datos[1][i]);

      // Limpiar el búfer (elimina el '\n' residual de los scanf)
      while (getchar() != '\n');

      //Mensaje de validacion 
      if (datos[0][i] < 1) {
        printf("El precio de libros no puede ser inferior a 1\n");
        printf("Porfavor digite la cantidad correspondiente\n");
      } else if(datos[1][i] < 1) {
        printf("La cantidad de libros no puede ser inferior a 1\n");
        printf("Porfavor digite la cantidad correspondiente\n");
      } 
      //se repite si las cantidades son negativas o cero
    } while (datos[0][i] < 1 || datos[1][i] < 1);

    //subtotal como arreglo
    subtotal[i] = datos[0][i] * datos[1][i];

    //contador cantidad
    unidades += datos[1][i];

    //contador precio
    totalLibros += subtotal[i];

    //contador de vueltas
    i++;
    carrito++;

    //vuelve a preguntar si desea continuar
    printf("Titulo del libro (FIN para terminar): ");
    fgets(titulos[i], sizeof(titulos[i]), stdin);
    titulos[i][strcspn(titulos[i], "\n")] = '\0';
    
    //Validador de vueltas
    if (i > 9) {
      break;
    } 
  }

  //Descuento 
  restDescuento = totalLibros * DESCUENTO;
  //IVA
  restIVA = (totalLibros - restDescuento) * IVA;
  //Total
  total = totalLibros - restDescuento + restIVA + ENVIO;

  //Salidas de dato como tabla
  printf("%-25s%8s%6s%10s\n","Titulo","Precio","Cant","Subtotal");
  for (i = 0; i < carrito; i++) { 
    printf("%-25s",titulos[i]);
    printf("%8.2f",datos[0][i]);
    printf("%6.2f",datos[1][i]);
    printf("%10.2f\n",subtotal[i]);
  }

  //salidas individuales
  printf("%-20s%10d\n",   "Unidades:", unidades);
  printf("%-20s%10.2f\n", "Total de libros:", totalLibros);
  printf("%-20s%10.2f\n", "Descuento:", restDescuento);
  printf("%-20s%10.2f\n", "Impuesto (13%):", restIVA);
  printf("%-20s%10.2f\n", "Envio:", ENVIO);
  printf("%-20s%10.2f\n", "TOTAL A PAGAR:", total);
  
  printf("\n");
  system("pause");
  return 0;
}