//El grupo va a elegir a su representante entre tres candidatos: 1 Ana, 2 Luis y 3 Sofia. Cada estudiante pasa a la computadora y digita el numero de su candidato. No se sabe cuantas personas votaran: la votacion termina cuando alguien digita 0.

//Cualquier otro numero es voto nulo. Al final se muestra una barra de * con los votos del candidato

#include <stdio.h> //libreria prinf y scanf
#define FIN 0 //se define e inicializan constantes

int main(void){
  //Variables
  int voto;         //numero que digita cada estudiante -> 1,2,3 otro o 0
  int total = 0;    //contador de votos recibidos (Validos como nulos). 
  int ana = 0;
  int luis = 0;
  int sofia = 0;
  int nulos = 0;    //CONTADOR de voto nulo
  int i;            //contador del for interno: una vuelata por cada *
  int c;            //candidato que dibuja el for externo 1 a 3
  int cantidad;     //votos del candidato
  int mayor;
  int empatados;

  printf("========= Eleccion de representante =========\n");
  printf("1. Ana     2. Luis    3. Sofia    (0 cierra)\n\n");
  
  //LECTURAS PREVIAS
  // printf("voto: ");
  // scanf("%d", &voto);
  
  //WHILE con centinela. Se repite mientras el voto no sea 0
  while (voto != FIN) {
    total++;         //CUENTA EL VOTO -> 1,2, ........

    switch (voto) {
    case 1: ana++; break; //break: sale del switch
    case 2: luis++; break;
    case 3: sofia++; break;
    
    default:        //cualquier otro numero -> 5
      nulos++;
      printf("Voto nulo\n");
      break;
    }

    //FOR EXTERNO: Una vuelta sin la nueva lectura el voto no cambia y el while no termina
    for (c = 1; c <= 3; c++) {
      switch (c) {
        case 1: printf("Ana  "); cantidad = ana; break;
        case 2: printf("Luis  "); cantidad = luis; break;
        default: printf("Sofia  "); cantidad = sofia; break;
      }
       //FOR INTERNO: (aninado) un for * y otro por voto -> Ana ***
      for (i = 1; i <= total; i++) {
        printf("*");
      }
      printf(" (%d)\n",cantidad);
    }

    printf("Nulos: (%d)\n",nulos);

     //NUEVA LECTURA: Sin la nueva lectura el voto no cambia y el while no termina
    printf("voto: ");
    scanf("%d", &voto);


    mayor = ana;
    if (luis > mayor) {mayor = luis;}
    if (sofia > mayor) {mayor = sofia;}
    //empatados
    empatados = 0;
    if (ana == mayor) {empatados++;}
    if (luis == mayor) {empatados++;}
    if (sofia == mayor) {empatados++;}

    //DESICION: solo se ejecuta el primer bloque que se cumpla
    if (mayor == 0) {
      printf("No hubo votos validos\n");
    } else if (empatados > 1) {
      printf("empate con %d votos: se repite la votacion\n", mayor);
    } else if (ana == mayor) {
      printf("Gana Ana con %d votos: \n", mayor);   //3 votos 
    } else if (luis == mayor) {
      printf("Gana Luis con %d votos: \n", mayor);   //3 votos 
    } else if (sofia == mayor) {
      printf("Gana Sofia con %d votos: \n", mayor);   //3 votos 
    } 

  }
  

  return 0;

}