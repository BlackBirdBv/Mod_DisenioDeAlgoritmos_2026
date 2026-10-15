//vetas.c Ventas de una caden de sodas por sucursal y por dia
//que logra: Guardar en una matriz las ventas de 3 sucursales en 4 dias.
//sumar cada sucursal (fila) y cada dia por medio de la (columna) e 
//identificar la sucursal que mas vendio, con su nombre guardado 
//en cadena.
// Resualtado esperado centro 470, norte 350, sur 410; por dia 330 270 
//330; sucursal con mas ventas centro(470).

#include <stdio.h>
#include <string.h>     //strcpy
#include <stdlib.h>     
#define SUC 3           //filas sucursales
#define DIAS 4          //columnas dias

int main(void){
  //Arreglo de cadenas: una fila por nombre (hasta 9 letras + '\0')
  char nombres[SUC] [10] = {"Centro","Nombre","Sur"};

  //Ventas en miles de colones 
  int ventas[SUC] [DIAS] = { {120, 100, 130, 120},
                              {90, 80, 100, 80},
                              {120, 90, 100, 100} };
  char mejor[10];   //nombre de la sucursal ganadora
  int s, d, total, totalDia, mayor = 0;

  //Encabezado : D1 a D4
  printf("%-8s", "");
  for (d = 0; d < DIAS; d++) {
    printf("  D%d", d + 1);
  }
  printf("  |  Total\n");

  //RECORRIDOS POR FILAS 
  for (s = 0; s < SUC; s++) {
    total = 0;       //reinicia cada fila 
    printf("%-8s",nombres[s]);  //nombre a la izquierda
    for (d = 0; d < DIAS; d++) {
      printf("%5d", ventas[s][d]);
      total += ventas[s][d];
    }
    printf("  | %5d\n");    //470, 3750, 410

    //Guardar la variable con mayor total; strcpy copia el nombre
    if (total > mayor) {
      mayor = total;
      strcpy(mejor, nombres[s]);    //mejor = Centro
    }
  }
  //Recorrido por columnas. El for externo recorre los dias
  printf("%-8s","Dia");
  for (d = 0; d < DIAS; d++) {
    totalDia = 0;
    for (s = 0; s < SUC; s++) {
      totalDia += ventas[s] [d];
    }
    printf("%5d",totalDia);   //330 270 330 300
  }
  printf("\n");
  //SALIDAS: Sucursal con mas ventas: Centro 470
  printf("Sucursal con mas ventas: %s (%d)\n",mejor, mayor);
  
  system("pause");
  return 0;
}

