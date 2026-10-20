// Un centro educativo necesita automatizar el cálculo de notas finales. Escriba un programa en C que: 
// 1. Reciba el nombre completo del estudiante. 
// 2. Reciba tres calificaciones de 0 a 100 y las guarde en un arreglo. Cada calificación fuera de 
// rango se rechaza con un mensaje y se vuelve a pedir. 
// 3. Calcule el promedio de las tres calificaciones y busque la calificación más alta recorriendo el 
// arreglo. 
// 4. Determine la condición: APROBADO si el promedio es 70 o más; EN RIESGO si es 60 o más, 
// pero menor que 70; NO APROBADO si es menor que 60. Guarde la condición en una cadena. 
// 5. Muestre el nombre, las tres calificaciones, el promedio (dos decimales), la calificación más alta y 
// la condición.

//librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Constantes 
#define NOTAS 3     //tamaño del arreglo
#define ALTNOTA 70  //NOTAS ALTAS
#define BAJNOTA 60  //NOTAS BAJAS

int main(void){
  //arreglos 
  float calificaciones[NOTAS]; //guarda tres calidficaciones
  //Variables 
  char nombre[20];      //Guarda el nombre
  char condicion[15];   //guarda la condicion del estudiante
  double promedio;      //guarda el promedio
  double sumaNotas;     //guarda las notas 
  double mayor = 0;  //compara notas y guarda el mayor
  int i = 0;            //Cuenta las vueltas

  //Entrada
  printf(" === Calificaciones del estudiante === \n");
  //valida que no quede vacio el campo
  do {
    //Entrada de nombre 
    printf("Nombre del estudiante: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    if (nombre[0] == '\0') {
      printf("Por favor escriba el nombre del estudiante\n");
    }
  } while (nombre[0] == '\0');

  //ciclo para recorrer el arreglo
  for (i = 0; i < NOTAS; i++) {
    //rango de notas 
    do {
      //Entrada de notas
      printf("Calificacion %d (0 a 100): ",i+1);
      scanf("%f",&calificaciones[i]);
      //mensaje de si sale de rango
      if (calificaciones[i] < 0 || calificaciones[i] > 100) {
        printf("Nota fuera de rango........\n");
        printf("porfavor digite una nota entre  (0 y 100)\n");
      }
      //se vuelve a repetir si sale de rango 
    } while (calificaciones[i] < 0 || calificaciones[i] > 100);

    //suma todas la notas ingresadas
    sumaNotas += calificaciones[i];
    
    //guarda la nota solo si es mayor
    if (mayor < calificaciones[i]) { //si es verdadero
      mayor = calificaciones[i];  //cambia de valor
    }
  }
  
  //calculo promedio de notas 
  promedio = sumaNotas / NOTAS;

  //Validacion de condicion del estudiante
  if (promedio >= ALTNOTA) { //si promedio es mayo a 69
    strcpy(condicion,"APROBADO");
  } else if (promedio < ALTNOTA && promedio >= BAJNOTA) {  //si promedio es menor a 70 y mayor a 59
    strcpy(condicion,"EN RIESGO");
  } else { //si promedio es menor que 60
    strcpy(condicion,"NO APROBADO");
  }
  
  //Saida de datos como resumen
  printf("\n------- Resultado -------\n");
  printf("%-15s%15s\n","Estudiante:",nombre);
  printf("%-20s%10.1f\n","Calificacion 1:",calificaciones[0]);
  printf("%-20s%10.1f\n","Calificacion 2:",calificaciones[1]);
  printf("%-20s%10.1f\n","Calificacion 3:",calificaciones[2]);
  printf("%-20s%10.2f\n","Promedio:",promedio);
  printf("%-20s%10.1f\n","Nota mas alta:",mayor);
  printf("%-15s%15s\n","Condicion:",condicion);
  
  system("pause");
  return 0;

}