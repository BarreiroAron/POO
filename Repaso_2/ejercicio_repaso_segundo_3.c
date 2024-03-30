#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int numero = atoi(argv[1]);

  if(numero <= 0)  printf("No puedo comparar eso debido a fuerzas superiores\n"); return 0;
  if(numero % 2 == 0) { printf("Par\n"); } else {
    printf("Impar\n");
  }
    return 0;
  }
