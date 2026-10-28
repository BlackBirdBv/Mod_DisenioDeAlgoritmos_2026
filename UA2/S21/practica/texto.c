//texto.c Enunciado: leer una frase, mostrarla en mayúsculas y contar vocales, consonantes y dígitos. 
//getchar y putchar (sesión 20), isalpha, isdigit, toupper y tolower de ctype.h, y una función propia int esVocal(int c) que devuelve 1 o 0.

#include <stdio.h>
#include <ctype.h>

//funcion prototipo
int esVocal(int c);

//funcion principal
int main() {
  //variables
  char frase[100];
  int c;
  int i = 0;
  int vocales = 0, consonantes = 0, digitos = 0;

  //pide la frase 
  printf("Frase: ");

  //Lee la frase caracter por caracter usando getchar
  while ((c = getchar()) != '\n' && c != EOF && i < (int)sizeof(frase) - 1) {
    frase[i] = c;
    i++;
  }
  // Marcar el final de la cadena
  frase[i] = '\0';

  // muestrar la frase en mayúsculas usando putchar
  for (int j = 0; j < i; j++) {
    putchar(toupper(frase[j]));
  }
  printf("\n");

  // contador de vocales, consonantes y dígitos recorriendo el arreglo
  for (int j = 0; j < i; j++) {
    //guarda el caracter
    char actual = frase[j];
    if (isdigit(actual)) {
      // cuenta digitos 
      digitos++;
    } 
    //sino son digitos 
    else if (isalpha(actual)) {
      if (esVocal(actual)) {
        // cuenta vocales 
        vocales++;
      } else {
        // cuenta consonantes 
        consonantes++;
      }
    }
    // Los espacios y otros símbolos se ignoran automáticamente en el conteo
  }

  //Muestra resumen de analisis 
  printf("Vocales: %d  Consonantes: %d  Digitos: %d\n", vocales, consonantes, digitos);

  return 0;
}

// Funcion de vocales 
int esVocal(int c) {
  char lower = tolower(c);
  if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
    // Es vocal
    return 1; 
  }
  // No es vocal
  return 0;
}