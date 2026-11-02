#include <stdio.h>

//definiciones 
#define MAX_FACTURA 25000
#define RECARGO 1200
#define BASICO 6000
#define MEDIO 9000
#define PLUS 14000
#define CAMPOS 10

// Prototipos de funciones restantes
void ingresarDatosClientes(int clientes, char numero[CAMPOS][9], int plan[CAMPOS], float gigas[CAMPOS]);
void calcularFacturacion(int clientes, const int plan[], const float gigas[], float subtotal[], float total[], int *limitePlan);
int buscarClienteMayorFactura(int clientes, const float total[]);

//funcion principal
int main(void) {
  //arreglos
  char numero[CAMPOS][9];
  int plan[CAMPOS];
  float gigas[CAMPOS];
  float subtotal[CAMPOS];
  float total[CAMPOS];
  //variables
  int clientes;
  int limitePlan = 0;
  int mayor = 0;
  int i;

  //Leer cantidad de clientes
  do {
    printf("Escriba la cantidad de clientes (1 a 10): ");
    scanf("%d", &clientes);
    if (clientes < 1 || clientes > CAMPOS) {
      printf("Por favor, ingrese un número válido entre 1 y %d.\n", CAMPOS);
    }
  } while (clientes < 1 || clientes > CAMPOS);

  //Ingresar datos
  ingresarDatosClientes(clientes, numero, plan, gigas);

  //Calcular facturas y excesos
  calcularFacturacion(clientes, plan, gigas, subtotal, total, &limitePlan);

  //Encontrar el indice del mayor consumidor
  mayor = buscarClienteMayorFactura(clientes, total);

  //Mostrar resultados resumen por cliente
  printf("\n\n%-12s%12s%9s%12s%13s\n", "Cliente", "Tipo de plan","Consumo","subtotal","Total");
  for (i = 0; i < clientes; i++) {
    //muestra nombre cliente
    printf("%d. %-10s", i + 1, numero[i]);
    //muestra y valida el plan 
    if (plan[i] == 1) {
      printf("%8s","Basico");
    } else if (plan[i] == 2) {
      printf("%8s","Medio");
    } else {
      printf("%8s","Plus");
    }
    //muesta gigas subtotal y total 
    printf("%8.0fGB%14.2f%14.2f\n", gigas[i], subtotal[i], total[i]);
  }

  // Mostrar resultados resumen general
  printf("\n");
  printf("Cliente con mayor consumo: %d. %-9s con %.0f gigas a: %.2f\n", mayor + 1 , numero[mayor], gigas[mayor], total[mayor]);
  printf("Clientes con tope de consumo: %d\n", limitePlan);

  return 0;
}

//funcion ingresar clientes 
void ingresarDatosClientes(int clientes, char numero[CAMPOS][9], int plan[CAMPOS], float gigas[CAMPOS]) {
  for (int i = 0; i < clientes; i++) {
    printf("\n--- Cliente %d ---\n", i + 1);
    printf("Ingrese el numero de cliente (8 digitos): ");
    scanf("%8s", numero[i]);

    //valida que elija un plan existente 
    do {
      printf("Ingrese el plan contratado\n");
      printf("(1. Basico: 5 GB, 2. Medio: 10 GB, 3. Plus: 20 GB): ");
      scanf("%d", &plan[i]);

      if (plan[i] < 1 || plan[i] > 3) {
          printf("Por favor elija una de las opciones de plan validas (1, 2 o 3)\n");
      }
    } while (plan[i] < 1 || plan[i] > 3);
    
    //valida que ingrese consumo en rango
    do {
      printf("Ingrese los GB consumidos: ");
      scanf("%f", &gigas[i]);

      if (gigas[i] < 0 || gigas[i] > 100) {
          printf("Por favor elija una cantidad valida entre 0 y 100\n");
      }
    } while (gigas[i] < 0 || gigas[i] > 100);
  }
}

//calcular factura 
void calcularFacturacion(int clientes, const int plan[], const float gigas[], float subtotal[], float total[], int *limitePlan) {
  // locales
  float excesoGB;
  *limitePlan = 0;

  // evalua opcion conforme el plan 
  for (int i = 0; i < clientes; i++) {
    switch (plan[i]) {
      //para plan basico
      case 1:
        if (gigas[i] > 5) {
          excesoGB = gigas[i] - 5;
          subtotal[i] = BASICO + (RECARGO * excesoGB);
        } else {
          subtotal[i] = BASICO;
        }
        break;

      //para plan medio
      case 2:
        if (gigas[i] > 10) {
          excesoGB = gigas[i] - 10;
          subtotal[i] = MEDIO + (RECARGO * excesoGB);
        } else {
          subtotal[i] = MEDIO;
        }
        break;

      //para plan plus
      case 3:
        if (gigas[i] > 20) {
          excesoGB = gigas[i] - 20;
          subtotal[i] = PLUS + (RECARGO * excesoGB);
        } else {
          subtotal[i] = PLUS;
        }
        break;
    }

    //valida si la factura no excede el maximo permitido de 25000
    if (subtotal[i] > MAX_FACTURA) {
      total[i] = MAX_FACTURA;
      (*limitePlan)++;
    } else {
      total[i] = subtotal[i];
    }
  }
}

//funcion buscar mayor 
int buscarClienteMayorFactura(int clientes, const float total[]) {
  //locales 
  int mayor = 0;
  float mayorFac = total[0];

  //busca el cliente con mayor consumo 
  for (int i = 1; i < clientes; i++) {
    if (total[i] > mayorFac) {
      mayorFac = total[i];
      mayor = i;
    }
  }

  return mayor;
}