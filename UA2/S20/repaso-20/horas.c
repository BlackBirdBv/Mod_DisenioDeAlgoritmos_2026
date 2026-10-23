//horas.c - horas de estudio a la semana
/*Enunciado: registrar las horas de estudio de tres estudiantes de lunes a jueves 
se  digite el nombre y las horas de cada dia.
Mostrar una tabla con total de cadad estudiante, quien estudio mas, el dia con mas horas y buscar a una persona del gupo por su nombre*/

#include <stdio.h>
#include <string.h>

//Definir constantes 
#define EST 3     //Filas de la matriz 
#define DIAS 4    //Columnas

int main(void) {
  //Arreglo de cadenas para los 3 nombres.
  char nombres[EST][15];    //de los 15 caracteres 14 son para el nombre y 1 para '/0'

  //Matriz de horas: 3 filas para estudiantes y 4 columnas para los dias
  int horas[EST][DIAS];

  //ARREGLO DE CADENAS: CON LOS NOMBRE CORTOS DE LOS DIAS 
  char dias[DIAS][4] = {"Lun","Mar","Mie","Jue"};
  //Se crean los indices de fina y columna 
  int e;
  int d;

  //Arreglo total por estudiante. total[e] es la suma de la fila "e"
  int total[EST];

  //Posicion de quien  estudio mas 
  int mejor;

  //Acumulador de columna (horas de grupo en un dia)
  int sumaDia;

  //suma mayor de dia 
  int sumaMayor;

  //Posicion dia con mas horas 
  int diaMejor;

  //cadena con el nombre a buscar 
  char buscado[15];

  //Posicion donde aparece el nombre buscado
  int encontrado;

  // ========= Lectura con los for anidados ==========
  //ciclo externo: una vuelta por estudiante (fila)

  for (e = 0; e < EST; e++) {
    //pedimos el nombre del estudiante 
    printf("Nombre del estudiante %d: ",e+1);
    //leer una palabra en la fila de nombre 
    scanf("%14s",nombres[e]);

    //cilco interno: una vuelta por dia (columna) de la fila
    for (d = 0; d < DIAS; d++) {
      //pedir las horas del dia
      printf("horas de %s: ",dias[d]);
      // leer un entero en la celda
      scanf("%d",&horas[e][d]);
    }
  }

  //=====================TABLA=========================
  //Con encabezado con la palabra "nombre "
  printf("\n%-8s","Nombre");

  //For para recorrer los dias parar el encabazado 
  for (d = 0; d < DIAS; d++) {
    //mostrar cada dia 
    printf("%5s",dias[d]);
  }

  //titulo de la ultima 
  printf("%7s\n","Total");

  //una fila de la tabal por estudiante 
  for (e = 0; e < EST; e++) {
    //reinicia el total de la fila e 
    total[e] = 0;
    //Mostar el nombre 
    printf("%-8s",nombres[e]);
    
    //recorre la columna de la fila e 
    for (d = 0; d < DIAS; d++) {
      //mostrar las notas de la celda 
      printf("%5d",horas[e][d]);
      //sumar la celda al total 
      total[e] += horas[e][d];
    }
    //mostrar el total 
      printf("%7d\n",total[e]);
  }
  
  //===============Mayor del arreglo total====================
  //supone que el primero estudio mas 
  mejor = 0;
  //recorrer los demas estudiantes(posiciones 1 y 2).
  for (e = 0; e < EST; e++) {
    //comparar totales 
    if (total[e] > total[mejor]) {
      mejor = e;
    }
    
    //mostrar quien estudio mas 
    printf("\nEstudio mas: %s (%d horas)\n",nombres[mejor], total[mejor]);

    //============Dia mas horas (suma por columna)
    //mayor suma inicial en 0
    sumaMayor = 0;
    diaMejor = 0;

    //recorrer columnas 
    for (d = 0; d < DIAS; d++) {
      //Reiniciamos el acumulador 
      sumaDia = 0;

      // recorrer filas de esa columna
      for (e = 0; e < EST; e++) {
        //suma de celdas 
        sumaDia += horas[e][d];
      }

      //comparar la suma del dia con la mayor 
      if (sumaDia > sumaMayor) {
        //guardar la nueva mayor 
        sumaMayor = sumaDia;
        //guarda la posicion 
        diaMejor = d;
      }
    }
    
    //mostrar el dia con mas horas 
    printf("Dia con mas horas: %s (%d horas)\n",dias[diaMejor],sumaMayor);

    //====================== buqueda por nombre ========================

    //pedir nombre a buscar 
    printf("\nBuscar estudiante: ");
    //lee la palabra 
    scanf("%14s",buscado);
    //marca que todavia no aparece
    encontrado = -1; //si el for no lo encuentra sique en -1
    //recorrer los nombre 
    for (e = 0; e < EST; e++){
      //compara las dos cadenas 
      if (strcmp(buscado,nombres[e]) == 0) {
        encontrado = e;
      }
    }

    //revisa si encontro
    if (encontrado >= 0) {
      //muestra el total encontrado 
      printf("%s estudio %d horas\n",nombres[encontrado],total[encontrado]);
    } else {    //en cado que no aparesca 
      printf("%s no esta en la lista\n",buscado);
      //finalizamos
    }   
    
  }
  
  return 0;

}