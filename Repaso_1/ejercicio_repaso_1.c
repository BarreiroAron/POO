#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int alumnos;
  puts("Ingrese la cantidad de alumnos:");
  scanf("%d", &alumnos);

  //pido la cantidad de alumnos a ingresar, esos los multiplico para saber cual es el total a pagar.
  //     en lo ultimo, ya que el total es 6000, lo divido para saber cuanto paga cada alumno

  if(alumnos >= 100) { printf("%d", alumnos * 500); }
  if(alumnos <= 99 && alumnos >= 50) { printf("%d", alumnos*400); }
  if(alumnos <= 49 && alumnos >= 30) { printf("%d", alumnos*300); }
  if(alumnos <= 29) { printf("%d", 6000 / alumnos); }
  printf("\n");
  return 0;
}
