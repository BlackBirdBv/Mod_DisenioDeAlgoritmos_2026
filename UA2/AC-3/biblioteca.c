//Enunciado: La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir. 

//bibliotecas
#include <stdio.h>
#include <string.h>

//definiciones 
#define ESPACIO 5       
#define TITULO 20     
#define COD_MIN 100       
#define COD_MAX 999
#define EXISTENCIAS 20

//definiciones
int leerEntero(const char contexto[], int min, int max);
int buscarCodigo(const int code[], const int activo[], int n, int codigo);
void incluir(int code[], char tit[][TITULO], int prest[], int activo[], const char nombre[], int codigo, int cantidad, int *n);
void consultar(const int code[], const char tit[][TITULO], const int prest[], const int activo[], int n);
int prestar(int *ejemplar);
void darDeBaja(int *activo);

int main(void){
  //arreglos con 3 existencias
  int code[EXISTENCIAS] = {101,102,103};
  char tit[EXISTENCIAS][TITULO] = {"Quijote", "Principito", "Cocori"};
  int prest[EXISTENCIAS] = {3,2,4};
  int activo[EXISTENCIAS] = {1,1,1};

  //variables
  int n = 3; 
  int opcion, codigo, pos, cantidad;
  char nombre[TITULO];

  //inicio menú
  do {
    //mostrar el menu
    printf("\n=== sistema de prestamo de libros ===\n");
    printf("| 1. Incluir libro.\n");
    printf("| 2. Consultar libro.\n");
    printf("| 3. Prestar un ejemplar.\n");
    printf("| 4. Dar de baja un libro\n");
    printf("| 5. Buscar libro.\n");
    printf("| 0. Salir.\n");

    //Leer la y valida la opcion
    opcion = leerEntero("opcion", 0, 5);
    if (opcion >= 3) {
      codigo = leerEntero("codigo", COD_MIN, COD_MAX);
      pos = buscarCodigo(code, activo, codigo, n);

      //se confirma en base a la respuesta de buscar codigo
      if (pos != -1) {
        //mensaje
        printf("El codigo %d ya existe\n", codigo);
        continue;
      }
    }

    switch (opcion) {
        case 1:
        if (n == EXISTENCIAS) {
          printf("No hay copias disponibles\n");
          break;  //termina el caso
        }

        //lee codigo
        codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
        //valida si existe
        if (buscarCodigo(code, activo, n, codigo) != -1) {
          printf("El codigo %d ya existe\n", codigo);
          break;  //termina el caso
        }
        //pide titulo
        printf("Titulo del libro: ");
        //leer titulo
        scanf("%19s", nombre);
        //leer los ejemplares por cantidad
        cantidad = leerEntero("Ejemplares", 1, EXISTENCIAS); // DE 1 A 20
        //guardar el libro
        incluir(code, tit, prest, activo, nombre, codigo, cantidad, &n);
        //muesta la cantidad
        printf("Pase incluido (%d de %d)\n", n, EXISTENCIAS);
        break;

      case 2: 
        //muestra los libros
        consultar(code, tit, prest, activo, n);
        break;
      case 3:
        //presta libros
        if (prestar(&prest[pos]))
        printf("Prestamo realizado. A %s le quedan %d disponibles\n", tit[pos], prest[pos]);
        //si no hay
        else 
          printf("%s no tiene ejemplares disponibles\n", tit[pos]);
        break;

      case 4: 
        darDeBaja(&activo[pos]);
        printf("libro %s es dado de baja\n", tit[pos]);
        break;

      case 5: 
        //buscar un pase
        printf("%d %s: %d ejemplares\n", code[pos], tit[pos], prest[pos]);
        break;

      default:
        printf("Hasta luego\n");
    }

  } while (opcion !=0);

  return 0; 
  
}

// funcion leer entero
int leerEntero(const char contexto[], int min, int max){
  //variable local
  int rangoValor;
  //validacion de rango  
  do {
    printf("%s (%d a %d): ", contexto, min, max);
    scanf("%d", &rangoValor);
    //se repite si se sale de rango
  } while (rangoValor < min || rangoValor > max);
  // regresa la el dato
  return rangoValor;
}

//funcion para buscar codigo
int buscarCodigo(const int code[], const int activo[], int n, int codigo){
  int i;
  for (i = 0; i < n; i++)
    //ignora pase dados de baja
    if (code[i] == codigo && activo[i] == 1) {
      return i;
    }
  return -1;
}
  
  

//funcion para agregar libros
void incluir(int code[], char tit[][TITULO], int prest[], int activo[], const char nombre[], int codigo, int cantidad, int *n){
  //guardar el codigo
  code[*n] = codigo;
  //guardar el titulo
  strcpy(tit[*n], nombre);
  //guardar los ejemplares 
  prest[*n] = cantidad;
  //guarda el activo
  activo[*n] = 1;
  //pasa al siguiente 
  (*n)++;
}

//funcion consulta 
void consultar(const int code[], const char tit[][TITULO], const int prest[], const int activo[], int n){
  //contador local
  int i = 0;
  int activos = 0;

  //encabezado de tabla
  printf("%-6s %-20s %12s\n", "Codigo", "Titulo", "Disponibles");
  //recorrer los espacios usados
  for (i = 0; i < n; i++){
    //solo activos
    if (activo[i] == 1){
      printf("%-6d %-20s %12d\n", code[i], tit[i], prest[i]);
      //cuenta pases
      activos++;
    }
  }
  //mostrar total
  printf("Pases activos: %d\n", activos);
}

//funcion prestamo de libros
int prestar(int *ejemplar) {
  //revisa si hay libros disponibles
  if (*ejemplar == 0) {
    return 0;
  }
  //si hay lo resta
  (*ejemplar)--;
  return 1; 
}

//funcion dar de baja 
void darDeBaja(int *activo) {
  //se marca como inactivo
  *activo = 0;
}