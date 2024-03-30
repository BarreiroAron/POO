#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int nota1 = atoi(argv[1]);
  int nota2 = atoi(argv[2]);
  int nota3 = atoi(argv[3]);
//Pido tres notas y se divide por 3 para el promedio
  printf("%d\n", (nota1 + nota2 + nota3) / 3);
  return 0;
}
