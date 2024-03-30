#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int parcial = 0, parciales = 0, examen_final, trabajo_final;
  int calificacion;
  puts("Ingrese 3 notas de los parciales");
  for(int i = 1; i < 3; i++) {
    scanf("%d", &parcial);
    parciales = parciales + parcial;
  }
  /*
  puts("Ingrese calificacion del examen final");
  scanf("%d", &examen_final);
  printf("Ingrese calificacion de trabajo fianl\n");
  scanf("%d", &trabajo_final);
  calificacion = (parciales * 55 / 100) + (examen_final * 30 / 100) + (trabajo_final * 15 / 100);
  printf("Su calificacion final es: %d\n\n", calificacion);
  */
  printf("%d\n", parciales);
  return 0;
}
