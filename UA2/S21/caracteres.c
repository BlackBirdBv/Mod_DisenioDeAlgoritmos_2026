#include <stdio.h> 
#include <ctype.h> 
  
int main(void) { 
  char texto[] = "Ced 1-0234"; 
  int i, letras = 0, digitos = 0; 
  for (i = 0; texto[i] != '\0'; i++) { 
    if (isalpha(texto[i])) { 
        letras++; 
    } 
    if (isdigit(texto[i])) { 
        digitos++; 
    } 
    putchar(toupper(texto[i])); 
  } 
  printf("\nLetras: %d  Digitos: %d\n", letras, digitos); 
  return 0;
}