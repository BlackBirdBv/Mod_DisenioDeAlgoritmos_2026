//Caso integrador de la unidad 2 del curso Diseño de Algoritmos 
//Enunciado: El sistema registra notas de un grupo de 16 estudiantes 
//contiene un menú 1. Agregar (nota de 0 100 validarla). 2. Ver notas (cada una con aprobado si es 70 o más, o reprobado), 3. Estadisticas (Promedio, mayor y menos). y 0 para salir
#include <stdio.h>
#define MAX 16

//definicion prototipos
//leer nota no recibe datos y devuelve una nota valida
double leerNota(void);

//Recibe el arreglos y direccion de la cantidad
void agregarNota(double notas[], int *cantidad);

//Mostrar notas: recibe el arreglo y la cantidad por valor 
void mostrarNotas(const double notas[], int cantidad);

//calcula estadisticas: recibe el arreglo y cantidad, y tres punteros 
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor);

int main(void){
  //arreglo notas 16
  double notas[MAX];

  //cantidad de notas guardadas y opcion del menu
  int cantidad = 0, opcion;

  //resultado de las estadisticas
  double promedio, mayor, menor;

  //Ciclo del menu para repetir hasta 0
  do {
  //mostrar el menu
  printf("\n1. Agregar 2. Ver notas 3. Estadisticas 0. Salir\n");
  //pedir la opcion del menu
  printf("Opcion: ");
  //leer opcion
  scanf("%d",&opcion);
  //elige la rama seguin la opcion
  switch (opcion) {
    //opcion 1 agregar
    case 1:
        agregarNota(notas, &cantidad);
      break;//sale del switch

    //opcion 2 lista de notas
    case 2:
      mostrarNotas(notas, cantidad);
      break;//sale del switch

    //estadisticas
    case 3:
      //revisar si no hay notas 
      if (cantidad == 0) {
        printf("No hay notas resgistradas\n");
      } else {
        //hacer la llamada que devuelva 3 resultados.
        calcularEstadisticas(notas, cantidad, &promedio, &mayor, &menor);
        //mostrar resultados 
        printf("promedio: %0.f Mayor: %.1f Menor: %.1f\n", promedio, mayor, menor);
      }
      break;
    //opcion cero para salir
    case 0:
      printf("Hasta luego\n");
      break;
        
    //Cualquier otra opcion que no sea del menu
    default:
      printf("Opcion invalidad\n");
      break;
    }
    //repite mientras no se elije 0
  } while (opcion != 0);
  //termina con main 
  return 0;
}

//definicion de leer nota
double leerNota(void){
  double nota;
  //ciclo de validadcion
  do {
    //pedir nota 
    printf("Nota (0 a 100): ");
    //leer notas
    scanf("%lf",&nota);
    //repite si esta fuera de rango 
  } while (nota < 0 || nota > 100);
  return nota;
}

//definicion agregar nota
void agregarNota(double notas[], int *cantidad){
  //revisar si esta vacio
  if (*cantidad < MAX) {
    //gaurdar la nota
    notas[*cantidad] = leerNota();
    //aumentar a cantidad 
    (*cantidad)++;
  } else {
    printf("El grupo ya tiene %d notas\n", MAX);
  }
}

//definicion para mostrar notas 
void mostrarNotas(const double notas[], int cantidad){
  //indice local para recorrer el arreglo
  int i;
  //for para recorrer las notas 
  for (i = 0; i < cantidad; i++){
    //mostrar numero, nota y condicion
    printf("%2d. %5.lf %s\n", i + 1, notas[i], notas[i] >= 70 ? "Aprobado" : "Reprobado");
  }
}

//Definicion calcular estadisticas
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor){
  //Acumulador local
  double suma = 0;
  //indice local para recorrer el arreglo
  int i;
  //se supone que la primera nota es mayor 
  *menor = notas[0];
  //for para recorrer las notas 
  for (i = 0; i < cantidad; i++) {
    //suma la nota
    suma += notas[i];
    //compare con el mayor 
    if (notas[i] > *mayor) {
      *mayor = notas[i];
    }
  }
  *promedio = suma / cantidad;
}