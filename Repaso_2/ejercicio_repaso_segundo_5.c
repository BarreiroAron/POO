#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int nota = atoi(argv[1]);
if(nota >= 6) { printf("aprobado\n"); } else {
printf("desaprobado\n"); }
if(nota == 1) printf("Esforzarte mas\n");
if(nota >= 8) printf("felicitaciones\n");
  return 0;
}
