#include <stdio.h> 
#include <stdlib.h> 
  
int main(void) { 
  int i; 
  srand(2026);                         // semilla fija 
  for (i = 1; i <= 5; i++) { 
      printf("%d ", rand() % 6 + 1);   // dado de 1 a 6 
  } 
  printf("\nabs(-8) = %d\n", abs(-8)); 
  printf("atoi(\"2026\") + 1 = %d\n", atoi("2026") + 1); 
  return 0; 
}