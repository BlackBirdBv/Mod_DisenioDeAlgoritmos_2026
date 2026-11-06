// biblioteca.c - AC3 parte 2: prestamo de libros
// ENUNCIADO: una biblioteca nesecita un sistema de prestamo de libros, deberia registrar hasta 5 libros direrentes, de cada libro guarda un codigo unico de identificacion en un rango predefinido de (100 a 999), el titulo que sea una sola palabra de 19 caracteres los ejemplares disponibles y si el libro esta activo o retirado del sistema. se inicia con tres libros precargados con un menu de opciones que permitan incluir libros, consultar, prestar, dar de baja, buscar libros y salir y que las opciones esten validadas en caso que se salga de rango

/* QUE SE LOGRA: 
gestionar con limite de capacidad estricto controla, el inventario has un maximo de 5 libros en simultaneos
asegura que los codigos, opciones de menu y cantidades de ejemplares se encuentren siempre dentro de rangos validos
localiza libros por su codigo único de manera segura
guarda libros con sus caracteristicas
revisa los libros exxitentes en el sistema 
realiza prestamos por ejemeplares disponibles 
der de baja sin alterar el sistema 
buscar directamente */

/* COMO SE LOGRA: 
gestionar con limite de capacidad: usar definiciones como ESPACIO para marcar los limites de lo arrglos 
asegura que los codigos: la funcion darDe baja resive la direccion y cmodifica directamente su valor 
opciones de menu y cantidades de ejemplares se encuentren siempre dentro de rangos validos: gracias a validaciones con if y do while que leen y piden el dato hasta que sea correcto
localiza libros por su codigo único de manera segura: realiza un recorrido con un for por codigos para verificar que el codigo exita y coincida con el libro correspondiente 
guarda libros con sus caracteristicas: arreglos paralelos (code, tit, prest, activo) y la funcion incluir con strcpy.
revisa los libros exxitentes en el sistema: La funcion consultar filtrando unicamente los registros donde activo[i] == 1.
realiza prestamos por ejemeplares disponibles: Paso por referencia mediante punteros (*ejemplar) para decrementar las existencias ((*ejemplar)--).
der de baja sin alterar el sistema: Un puntero (*activo) que cambia el estado a 0 mediante la función darDeBaja, sin borrar datos físicamente.
buscar directamente: La posicion pos retornada por buscarCodigo para acceder de inmediato a los arreglos (code[pos], tit[pos], etc.)
*/

/* RESULTADO ESPERADO: 
Consultar Los 3 libros iniciales; libros activos: 3. 
1 Incluir, código 102 El código 102 ya existe. 
1 Incluir: 104, Platero, 25 (inválido) y luego 2 Pide de nuevo los ejemplares; libro incluido (4 de 5). 
3 Prestar 102, tres veces Disponibles 1, luego 0; la tercera vez: no hay ejemplares disponibles. 
4 Dar de baja 101 Libro Quijote dado de baja. 
5 Buscar 101 No existe un libro activo con el código 101. 
5 Buscar 103 103 Cocori: 4 disponibles. 
Opción 9 (inválida) y luego 2 Consultar Pide de nuevo la opción; muestra 102 (0), 103 (4) y 104 (2); libros activos: 3.
*/

// Biblioteca de un colegio - Sistema de control de préstamos corregido
#include <stdio.h>
#include <string.h>

// Definiciones 
#define ESPACIO 5         // Maximo de libros permitidos (5)
#define TITULO 20         // espacio de arreglo
#define COD_MIN 100       // minimo definido 
#define COD_MAX 999       // maximo definido

// Declaración de funciones
int leerEntero(const char contexto[], int min, int max);
int buscarCodigo(const int code[], const int activo[], int n, int codigo);
void incluir(int code[], char tit[][TITULO], int prest[], int activo[], const char nombre[], int codigo, int cantidad, int *n);
void consultar(const int code[], const char tit[][TITULO], const int prest[], const int activo[], int n);
int prestar(int *ejemplar);
void darDeBaja(int *activo);

int main(void){
  // CORRECCION: Se usa (ESPACIO 5) en lugar de un tamaño 20 para cumplir con el límite de 5 libros.
  int code[ESPACIO] = {101, 102, 103};
  char tit[ESPACIO][TITULO] = {"Quijote", "Principito", "Cocori"};
  int prest[ESPACIO] = {3, 2, 4};
  int activo[ESPACIO] = {1, 1, 1};

  // Variables
  int n = 3; 
  int opcion, codigo, pos, cantidad;
  char nombre[TITULO];

  // Inicio menu
  do {
    // Mostrar el menu
    printf("\n=== sistema de prestamo de libros ===\n");
    printf("| 1. Incluir libro.\n");
    printf("| 2. Consultar libro.\n");
    printf("| 3. Prestar un ejemplar.\n");
    printf("| 4. Dar de baja un libro\n");
    printf("| 5. Buscar libro.\n");
    printf("| 0. Salir.\n");

    // Leer y validar la opcion
    opcion = leerEntero("opcion", 0, 5);

    // CORRECCION: Las opciones 3, 4 y 5 requieren que el libro EXISTA previamente.
    if (opcion >= 3 && opcion <= 5) {
      codigo = leerEntero("codigo", COD_MIN, COD_MAX);
      
      // CORRECCION: Se corrigió el orden de los argumentos en buscarCodigo: 
      // paso de: buscarCodigo(code, activo, codigo, n) a buscarCodigo(code, activo, n, codigo)
      pos = buscarCodigo(code, activo, n, codigo);

      // CORRECCION: Se cambio la logica invertida. 
      // Si pos == -1 significa que el libro no existe, por lo tanto no se puede prestar, dar de baja o buscar.
      if (pos == -1) {
        printf("El codigo %d no existe en el sistema\n", codigo);
        continue; // Vuelve a mostrar el menú principal
      }
    }

    switch (opcion) {
      case 1:
        // CORRECCION: Se cambió EXISTENCIAS por ESPACIO para respetar el limite de 5 libros.
        if (n == ESPACIO) {
          printf("No hay espacio disponible para más libros\n");
          break;  // Termina el caso
        }

        // Lee codigo
        codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
        
        // Valida si ya existe (para evitar duplicados al incluir)
        if (buscarCodigo(code, activo, n, codigo) != -1) {
          printf("El codigo %d ya existe\n", codigo);
          break;  // Termina el caso
        }
        
        // Pide titulo
        printf("Titulo del libro: ");
        scanf("%19s", nombre);
        
        // Leer los ejemplares por cantidad (maximo el limite de espacio o un valor razonable)
        cantidad = leerEntero("Ejemplares", 1, 20); 
        
        // Guardar el libro
        incluir(code, tit, prest, activo, nombre, codigo, cantidad, &n);
        
        printf("Libro incluido (%d de %d)\n", n, ESPACIO);
        break;

      case 2: 
        // Muestra los libros
        consultar(code, tit, prest, activo, n);
        break;

      case 3:
        // Presta libros usando la posicion (pos) encontrada previamente
        if (prestar(&prest[pos])) {
          printf("Prestamo realizado. A %s le quedan %d disponibles\n", tit[pos], prest[pos]);
        } else { 
          printf("%s no tiene ejemplares disponibles\n", tit[pos]);
        }
        break;

      case 4: 
        // Da de baja el libro usando la posicion (pos) encontrada previamente
        darDeBaja(&activo[pos]);
        printf("El libro %s ha sido dado de baja\n", tit[pos]);
        break;

      case 5: 
        printf("Libro encontrado -> Codigo: %d | Titulo: %s | Ejemplares: %d\n", code[pos], tit[pos], prest[pos]);
        break;

      default:
        printf("Hasta luego\n");
    }

  } while (opcion != 0);

  return 0; 
}

// Funcion leer entero
int leerEntero(const char contexto[], int min, int max){
  int rangoValor;
  do {
    printf("%s (%d a %d): ", contexto, min, max);
    scanf("%d", &rangoValor);
  } while (rangoValor < min || rangoValor > max);
  return rangoValor;
}

// Funcion para buscar codigo
int buscarCodigo(const int code[], const int activo[], int n, int codigo){
  int i;
  for (i = 0; i < n; i++) {
    // Ignora libros dados de baja (activo[i] == 0)
    if (code[i] == codigo && activo[i] == 1) {
      return i; // Retorna la posicion si lo encuentra y está activo
    }
  }
  return -1; // Retorna -1 si no se encuentra
}

// Funcion para agregar libros
void incluir(int code[], char tit[][TITULO], int prest[], int activo[], const char nombre[], int codigo, int cantidad, int *n){
  code[*n] = codigo;
  strcpy(tit[*n], nombre);
  prest[*n] = cantidad;
  activo[*n] = 1;
  (*n)++;
}

// Funcion consulta 
void consultar(const int code[], const char tit[][TITULO], const int prest[], const int activo[], int n){
  int i = 0;
  int activos = 0;

  printf("%-6s %-20s %12s\n", "Codigo", "Titulo", "Disponibles");
  for (i = 0; i < n; i++){
    if (activo[i] == 1){
      printf("%-6d %-20s %12d\n", code[i], tit[i], prest[i]);
      activos++;
    }
  }
  printf("Libros activos: %d\n", activos);
}

// Funcion prestamo de libros
int prestar(int *ejemplar) {
  if (*ejemplar == 0) {
    return 0; // No hay ejemplares
  }
  (*ejemplar)--;
  return 1; // Prestamo exitoso
}

// Funcion dar de baja 
void darDeBaja(int *activo) {
  *activo = 0; // Se marca como inactivo
}