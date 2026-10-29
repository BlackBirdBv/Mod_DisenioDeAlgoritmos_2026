//Eunuciado: pulperia.c muestra un menu y dependiendo la accion realiza las siguientes operaciones:  1. Listar  2. Vender  3. Reponer  4. Valor  0. Salir.

#include <stdio.h>

//Constantes 
#define CAMPO 4

//definiciones 
int leerEntero(const char mensaje[], int minimo, int maximo);
void listar();
int vender(int *stocks, int cantidad);
// void reponer(int *existencia, int cantidad);
// double valorInventario();

//arreglo globalizado
char productos[CAMPO][15] = {"Arroz 2 kg","Frijoles 1 kg","Cafe 1 kg","Aceite 1 L"};
float precios[CAMPO] = {2400.00,1800.00,4500.00,3200.00};
int stocks[CAMPO] = {20,15,12,8};

//funcion principal
int main(void){
  //variables 
  int opcion;
  int ;
  int cantidad;
  
  do {
    //muestra menu de opciones 
    printf("\n1. Listar  2. Vender  3. Reponer  4. Valor  0. Salir\n");
    printf("Opcion (0 a 4): ");
    //lee la opcion
    scanf("%d",&opcion);

    switch (opcion) {
      //muesta la lista de los productos 
      case 1:
        listar();
        break;

      //vende productos del sistema
      case 2:
        int prod = leerEntero("Opcion (1 a 4): ", 1, 4);
        int cant = leerEntero("Cantidad (1 a 50): ", 1, 50);
        
        vender(&stocks[prod - 1], cant);
        if ( vender(&stocks[prod - 1], cant)) {
          
        }
        

        break;

      //repone productos del sistema
      case 3:
        // void reponer(int *existencia, int cantidad);
        break;

      //muestra el valor total del inventario
      case 4:
        // double valorInventario(provisional);
        break;

      case 0:
        printf("Hasta luego\n");
        break;
      
      default:
        printf("Error al ingresar opcion fuera de rango\n");
        printf("porfavor elija una de las opciones sugeridas\n");
        printf("elija una opcion de (0 a 4)\n");

        break;
      }

  } while (opcion != 0);
  return 0;
}

//funcion producto y la cantidad
int leerEntero(const char mensaje[], int minimo, int maximo){
  int numero;
  do
  {
    printf(mensaje);
    scanf("%d",numero);
    if (numero > minimo || numero < maximo)
    {
      printf("Fuera de rango");
    }
  
  } while (numero > minimo || numero < maximo);

  return numero;
  
}

//funcion listar
void listar(){
  //recorre los procductos del sistema
  for (int i = 0; i < CAMPO; i++) {
    printf("%d. %-15s %8.2f %4d\n",i + 1, productos[i], precios[i], stocks[i]);
  }
}

//funciopn vender 
int vender(int *stocks, int cantidad){
  if (cantidad < *stocks)
  {
    return 0;
  }
  else{
    *stocks -= cantidad;
    return 1;
  }
  
}