#include <stdio.h> 
  
double calcularDescuento(double total) { 
  if (total >= 50000) { 
    return total * 0.10; 
  } 
  return 0; //correjido
} 
  
int main(void) { 
  printf("%.2f\n", calcularDescuento(60000)); 
  return 0; 
} 