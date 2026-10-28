//dados.c Enunciado: simula 600 lanzamientos de un dado y muestra cuantas veces calló cada cara 
//lanzarDado(void) /  (void mostrarBarra(int cantidad): un * por cada 10 lanzamiento

#include <stdio.h>
#include <stdlib.h>

#define CARAS 7
#define LANZAMIENTOS 600

//prototipo fuinciones 
int lanzarDado(void);
void mostrarBarra(int cantidad);

//arreglo global
int frecuencia[CARAS] = {0};

//variable global
int c;
int l;
int i;

//funcion principal
int main(void){
  int cantidad;

  //semilla 
  srand(2026);

  //llamada funcion lanzamiento de dado
  lanzarDado();

  //recorrido de cada cara 
  for (c = 1; c < CARAS; c++) {
    //muestra la cara y las veces que se repitio
    printf("Cara %d: %3d ", c, frecuencia[c]);

    //divide entre 10 la cantidad de veces que se repitio cada cara
    cantidad = frecuencia[c] / 10;

    //llama la funcion barra de inicidencia
    mostrarBarra(cantidad);
    
    //salto de linea
    printf("\n");
  }

  return 0 ;
}

//funcion lanzamiento de dado
int lanzarDado(void){
  //variable inicializada en 0
  int cara = 0;

  //ciclo con la cantidad de veces que se lanza
  for (l = 0; l < LANZAMIENTOS; l++) {
    cara = rand() % 6 + 1;    //numero aleatorio para del dado
    frecuencia[cara]++;       //cuenta y guarda en un arreglo cuantas veces se repite
  }
  //regresa el arreglo
  return *frecuencia;         
}

//funcion barras de incidencia 
void mostrarBarra(int cantidad){  
  //optiene el valor y se repite esa misma cantidad de veces
  for (i = 0; i < cantidad; i++) {
    printf("*");
  }
}
