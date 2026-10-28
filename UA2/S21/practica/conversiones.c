//conversiones. ENUNCIADO: convertir en funciones cuatro algoritmos 
//Coversion de temperatura / conversion de moneda (colones por dolar )
#include <stdio.h>
#define TIPO_CAMBIO 510.0

//PROTOTIPOS DE LAS FUNCIONES 
double celsiusFahrenheit(double celsius);   //devuelve los grados F
double colonesADolares(double colones);     //devuelve los dolares
int esBisiesto(int anio);                   //1 o 0
int esNotaValida(double nota);              //1 o 0

//funcion priuncipal 
int main(void){
  //prueba de temperatura
  printf("25 C = %.1f F (esperado 77.0)\n",celsiusFahrenheit(25));

  //prueba la moneda 10.00
  printf("5100 colones = %.2f dolares (esperado 10.00)\n",colonesADolares(5100));

  //prueba anio bisiesto -> 1 verdadero
  printf("2024 bisiesto: %d (esperado 1)\n",esBisiesto(2024));

  //prueba anio bisiesto -> 0 falso
  printf("1900 bisiesto: %d (esperado 0)\n",esBisiesto(1900));

  //prueba de nota invalida -> 0 falso
  printf("Nota 105 valida: %d (esperado 0)\n",esNotaValida(105));

  //prueba de nota invalida -> 1 verdadero
  printf("Nota 85 valida: %d (esperado 1)\n",esNotaValida(85));
  return 0;
}

//Conversion de temperatura
double celsiusFahrenheit(double celsius){
  return celsius * 9.0 / 5.0 + 32;
}

//Conversion de moneda
double colonesADolares(double colones){
  return colones / TIPO_CAMBIO;
}

//anio bisiesto
int esBisiesto(int anio){
  return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

//validar nota 
int esNotaValida(double nota){
  return (nota >= 0 && nota <= 100);
}