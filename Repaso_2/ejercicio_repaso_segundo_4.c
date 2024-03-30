#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int nota, tarea;
  int nota_final = 0;
  puts("Ingrese las 4 notas de las pruebas");
  for(int i = 0; i < 4; i++) {
    scanf("%d", &nota);
    nota_final += nota;
  }
  puts("Ingrese nota de la tarea");
  scanf("%d", &tarea);
  printf("La nota finak es: %d\n", (nota_final + tarea) / 5);
  return 0;
}
