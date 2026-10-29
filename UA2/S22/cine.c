
#include <stdio.h>
//definir constantes 
#define MAX_COMPRAS 10
#define PRECIO_GENERAL 3500
#define PRECIO_NINO 2500
#define PRECIO_MAYOR 2000
#define MIN_DESCUENTO 5
#define TAZA_DESCUENTO 0.10

//PROTOTIPOS DE FUNCIONES 
int leerEntero(const char mensaje[], int minimo, int maximo);
double precioEntradad(int tipo);
double calcularTotal(int tipo, int cantidad);
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento);

int main(void){
  //definir arreglos 
  char clientes[MAX_COMPRAS][15];   //CLIENTE DE LA COMPRA
  int cantidades[MAX_COMPRAS];      //Cantidad de compras posibles
  double totales[MAX_COMPRAS];      //total de cada compra
  //cantidad de compras, indice y el tipo de entrada 
  int n, i, tipo;
  //mostrar la cantidad de compras
  double totalVendido;
  //resultados
  int posMayor, conDescuento;

  //portada
  printf("====== Venta de Entradas ======\n");
  printf("Tipos: 1. General 3500,  2. Ninio 2500,  3. Adulto mayor 2000\n");

  //leer cantidad de compras -> 4
  n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);

  //FOR para una vuelta por compra 
  for (i = 0; i < n; i++) {
    printf("Compra %d\n Cliente: ",i + 1); //numero de compra y pedido de cliente 
    scanf("%14s",clientes[i]);

    //leer el tipo de entrada 
    tipo = leerEntero("Tipo", 1, 3);
    //leer cantidad de entradas 
    cantidades[i] = leerEntero("Entradas", 1, 8);

    //calcular el total de la compra
    totales[i] = calcularTotal(tipo, cantidades[i]);
  }

  //calcular resumen en una pasada 
  resumir(cantidades, totales, n, &totalVendido, &posMayor, &conDescuento);

  //encabezado de la  tabla

  printf("\n%-12s%9s%12s\n","Clientes","Entradas","Total");
  //recorrer las compras
  for (i = 0; i < n; i++) {
    //mostrar fila 
    printf("%-12s%9d%12.2f\n\n", clientes[i], cantidades[i], totales[i]);
    //total vendido
    printf("Total vendido: %12.2f\n", totalVendido);
    //compra mayor
    printf("Compra Mayor: %s (%.2f)\n", clientes[posMayor], totales[posMayor]);
    //compras con descuento
    printf("Con descuento:   %d compra(s)\n", conDescuento);
    //termina main con return  por valor 
  }
  return 0;
}

//Definiciones. Leer entero
int leerEntero(const char mensaje[], int minimo, int maximo){
  //variable local para el dato
  int valor;

  do {
    printf("%s (%d a %d): ", mensaje, minimo,maximo);
    scanf("%d",&valor);
  } while (valor < minimo || valor > maximo);
  //
  return valor;
}

//Defininiones precioEntrada
double precioEntradad(int tipo){
  switch (tipo) {
  case 1:
    return PRECIO_GENERAL;  //return termina la funcion no hace falta el break

  case 2:
    return PRECIO_NINO;     //return termina la funcion no hace falta el break
  
  default:
    return PRECIO_MAYOR;    //return termina la funcion no hace falta el break
  }
}

//Definicion de calcular total
double calcularTotal(int tipo, int cantidad){
  double total = precioEntradad(tipo) * cantidad;

  if (cantidad >= MIN_DESCUENTO) {
    total = total * (1 - TAZA_DESCUENTO);

    return total;
  }
}

//Definir resumir
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento){
  int i;
  //inicializo los tres resultados en la memoria de main
  *total = 0;
  *posMayor = 0;
  *conDescuento = 0;

  //recorrer las compras 
  for (i = 0; i < n; i++){
    *total += tot[i];
    //comparar la compra mayor
    if (tot[i] > tot[*posMayor]) {
      *posMayor = i;
    }
    if (cant[i] >= MIN_DESCUENTO) {
      (*conDescuento)++;
    }
  }
}



