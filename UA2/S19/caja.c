#include <stdio.h>

int main(void){
  //Variables
  int opcion;         //opcion del menu
  int productos = 0;  //contador de productos de la venta 
  double precio;      //precion para cada producto
  double total = 0;   //acumulador de la venta 

  //DO... WHILE: El menu se muestra al menos una vez
  do {
    //mostar el menu y lee la opcion -> 1
    printf("\n1. Agregar  2. Ver total  3. Cobrar  0. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    //SWITCH : segun: salta al case que coincida con la opcion elegida 
    switch (opcion) {
    case 1:
      //Validacion: repite mientras el precio no sea positivo
      do {
        printf("Precio del producto: ");
        scanf("%lf", &precio); //-> 1500 (-200)
        if (precio <= 0) {
          printf("Precio invalido\n");
        }
      } while (precio <= 0);
      productos++;
      total += precio;
      
      break;
    
    case 2:
      //Muestra el avance
      printf("Productos: %d Total: %.2f\n", productos, total);
      break;

    case 3:
      //Cobra y reinicia e contador y acumulador 
      printf("Cobrador: %.2f. Nueva venta\n", total);
      productos = 0;
      total = 0;
      
      break;

    case 0:
      printf("Caja Cerrada\n");
      break;

    default:
      //Si nungun caso coincide -> 9
      printf("Opcion invalida");
      break;
    }

    //repetir mientras no se elija el 0
  } while (opcion != 0);
  
  return 0;

}