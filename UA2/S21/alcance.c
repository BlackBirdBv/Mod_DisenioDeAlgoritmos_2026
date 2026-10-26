#include <stdio.h> 

int contador = 0;            // GLOBAL: fuera de todas las funciones 

void registrar(void) { 
  int temporal = 10;       // LOCAL de registrar 
  contador++; 
  printf("registrar: contador=%d temporal=%d\n", contador, temporal); 
}

int main(void) { 
  int temporal = 99;       // LOCAL de main (otra variable) 
  registrar(); 
  registrar(); 
  printf("main: contador=%d temporal=%d\n", contador, temporal); 
  return 0; 
}