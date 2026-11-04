// Un colegio controla los pases de bus de sus estudiantes y puede registrar hasta 5 pases. De cada pase se guarda: el código (100 a 999, no se repite), el nombre del estudiante (una sola palabra, hasta 19 letras), los viajes disponibles y si el pase está activo o dado de baja. El programa inicia con 3 pases ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir.

/* pases cargados al viajar 
Codigo  Nombre  Viajes
201     Ana       5 
202     Luis      1 
203     Sofia     8
*/

//cargar librerias 
#include <stdio.h>
#include <string.h>

//definir las constantes 
#define MAX_PASES 5     //espacios para los pases disponibles 
#define TAM_NOMBRE 20   //19 caracteres o letras + el \0
#define COD_MIN 100     //codigo minimo 
#define COD_MAX 999     //codigo maximo 
#define VIAJES_MAX 40   //viajes maximos a incluir 

//prototipos (una funcion por tarea)
int leerEntro(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad);
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n);
int usarViaje(int *viajes);
void daDeBaja(int *activo);

//funcion principal
int main(void){
  //Asigne datos de los pases
  int cod[MAX_PASES] = {201,202,203};
  char nom[MAX_PASES][TAM_NOMBRE] = {"Ana","Luis","Sofia"};
  int viajes[MAX_PASES] = {5,1,8};
  int activo[MAX_PASES] = {1,1,1};
  int n = 3;      //espacios usados
  int opcion, codigo, pos, cantidad;
  char nombre[TAM_NOMBRE];

  //ciclo para menu 
  do {
    //mostrar el menu
    printf("\n=== pases de bus ===\n");
    printf("1. Incluir   2. Consultar  3. Registrar viaje   4. Dar de baja\n");
    printf("5. Buscar   0. Salir");

    //leer la opcion
    opcion = leerEntro("Opcion", 0, 5);   //no aceptar opciones inexistentes
    if (opcion >= 3) {
      codigo = leerEntro("Codigo", COD_MIN, COD_MAX);
      pos = buscarCodigo(cod, activo, n, codigo);   //busca el pase activo 
      //revisa si existe 
      if (pos == -1) {
        //aviso 
        printf("No existe un pase activo con el codigo %d\n", codigo);
        //para continuar 
        continue;
      }
    }
    switch (opcion) {
      case 1:
        //revisa si no hay espacio
        if (n == MAX_PASES) {
          printf("No hay espacio para mas pases\n");
          break;
        }
        //lee codigo com conteo
        codigo = leerEntro("Codigo", COD_MIN, COD_MAX);
        //revidar si el codigo existe 
        if (buscarCodigo(cod, activo, n, codigo) != -1){
          printf("");
          break;
        }
        //pide nombre 
        printf("Nombre (Una palabra): ");
        //leer nombre
        scanf("%19s", nombre);
        //leer los viajes
        cantidad = leerEntro("Viajes", 1, VIAJES_MAX);  //DE 1 A 40 MAX
        //guardar el pase que viene por direccion 
        incluir(cod, nom,viajes, activo, &n, codigo, nombre, cantidad);
        //conformar pase incluido
        printf("Pase incluido (%d de %d)\n", n, MAX_PASES);
        break;

      case 2:
        consultar(cod, nom, viajes, activo, n);
        break;
      case 3:
        //intenta registrar viaje
        if (usarViaje(&viajes[pos])){
          printf("Viajes registrado. A %s le queda %d\n", nom[pos], viajes[pos]);
        } else {
          printf("%s no tiene viajes disponibles\n", nom[pos]);
        }
        break;
      
        case 4:
          daDeBaja(&activo[pos]);
          printf("Pase de %s dado de baja\n", nom[pos]);
          break;

        case 5:
          //buscar un pase 
          printf("%d %s: %d viajes\n", cod[pos], nom[pos], viajes[pos]);
          break;

        default:
          printf("Hasta luego\n");
    }

  } while (opcion != 0);
  return 0;

}

//lectura valida de un entero 
int leerEntro(const char mensaje[], int minimo, int maximo){
  //dato leido
  int valor;
  //ciclo validadcion para que pida el dato al menos una vez
  do {
    printf("%s (%d a %d): ", mensaje, minimo, maximo);
    //leer
    scanf("%d", &valor);
  } while (valor < minimo || valor > maximo);
  return valor;
}


//Busqueda secuencial de un pase 
int buscarCodigo(const int cod[], const int activo[], int n, int codigo){
  int i;
  for (i = 0; i < n; i++) {
    //ignora pase datos de baja
    if (cod[i] == codigo && activo[i] == 1) {
      return i;
    }
  }
  //no esta activo
  return -1;
}

//Agrega espacio en el primer espacio libre 
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad){
  //guardar el codigo
  cod[*n] = codigo;
  //guardar el nombre 
  strcpy(nom[*n], nombre);
  //guardar los viajes 
  viajes[*n] = cantidad;
  //pase activo
  activo[*n] = 1;
  //procimo pase a posicion siguiente
  (*n)++;
}

//pases activos y cuantos son 
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n){
  //indice del contador 
  int i, activos = 0;

  //encabezado de la tabla
  printf("%-6s %-12s %6s\n","Codigo","Nombre","Viajes disponibles");
  //recorrer los espacios usados
  for (i = 0; i < n; i++) {
    //solo activos 
    if (activo[i] == 1) {
      printf("%-6d %-12s %6d\n",cod[i],nom[i],viajes[i]);
      //cuenta pases
      activos++;
    }
  }
  //mostrar total 
  printf("Pases activos: %d\n",activos);
}

//registrar viajes si quedan
int usarViaje(int*viajes){
  //revisar si quedan viajes 
  if (*viajes == 0) {
    //no registra
    return 0;
  }
  //cambio en el arreglo 
  (*viajes)--;
  return 1;   //para confirmar desde main
}

//dar de baja
void daDeBaja(int *activo){
  //se marca como inactivo
  *activo = 0;
}