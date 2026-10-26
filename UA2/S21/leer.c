#include <stdio.h> 

int leerEntero(int minimo, int maximo); 

int main(void) { 
  int edad = leerEntero(15, 99); 
  int opcion = leerEntero(0, 3); 
  printf("Edad: %d  Opcion: %d\n", edad, opcion); 
  return 0; 
} 
  
int leerEntero(int minimo, int maximo) { 
  int valor; 
  do { 
    printf("Valor (%d a %d): ", minimo, maximo); 
    scanf("%d", &valor); 
  } while (valor < minimo || valor > maximo); 
  return valor; 
}