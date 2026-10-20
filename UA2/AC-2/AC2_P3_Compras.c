//librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Constantes
#define FILAS 10
#define COLUM 3
#define LIMITE 10
#define DESCMAXIMO 0.15
#define DESCMEDIO 0.10
#define DESCMINIMO 0.05
#define IMP 0.13

int main(void){
  //arreglos
  char productos[15][FILAS];      //guarda los productos con sus caracteristicas
  double precio[FILAS];           //guarda la precio
  int cantidad[FILAS];            //guarda cantidad
  double subProductos[COLUM];     //guarda el precio total por productos 
  //Variables
  char nombre[20];            //guarda el nombre
  char continuar;
  double subTotal;            //guarda el subtotal de todos los producto
  double restDescuento;       //guarda el descuento aplicado
  double restImp;             //guarda el impuesto aplicado
  double total;               //guarda el total a pagar
  int i;                      //contado de for


  //Entrada de datos
  printf(" === Compra en la tienda === \n");
  //valida que el campo no este vacio
  do {
    printf("Nombre del cliente: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    if (nombre[0] == '\0') {
      printf("Por favor escriba el nombre del cliente\n\n");
    }
  } while (nombre[0] == '\0');

  //ciclo de guardado de productos
  for (i = 0; i < LIMITE; i++) {  
    //vuelta por producto  
    printf("Producto %d\n",i+1); 

    //solo pide el nombre   
    printf("\tNombre: ");
    fgets(productos[i], sizeof(productos[i]), stdin);
    productos[i][strcspn(productos[i], "\n")] = '\0';
  
    //Validad que sean mayor que cero 
    do {
       //pide precio por unidad
      printf("\tPrecio unitario: ");
      scanf("%lf",&precio[i]);
      //pide cantidad
      printf("\tCantidad: ");
      scanf("%d",&cantidad[i]);

      //limpia el salto de linea
      while (getchar() != '\n');

      //mensaje de validadcion
      if (precio[i] < 1 || cantidad[i] < 1) {
        printf("Error al ingresar datos...\n");
        printf("porfavor ingrese cantidades mayor que 0 para continuar\n");
      }
      //repite si se cumple 
    } while (precio[i] < 1 || cantidad[i] < 1);
    
    //calculo subtotal por producto
    subProductos[i] = precio[i] * cantidad[i];
    //subtotal a pagar 
    subTotal += subProductos[i];
    //muestra subtotal por producto
    printf("\tSubtotal: %.2f\n",subProductos[i]);


    //pregunta si quiere te4rminar
    printf("Desea agregar otro producto? (S/N): ");
    scanf("%c",&continuar);
    //si se cumple se termina 
    if (continuar == 'N' || continuar == 'n') {
      break;
    }
  }
  


}
