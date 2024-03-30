#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int primer_sujeto = atoi(argv[1]);
  int segundo_sujeto = atoi(argv[2]);
  //simplemente se ingresan dos numeros, los cuales son los km. Se suman y se dividen por 2
  printf("%d\n", (primer_sujeto + segundo_sujeto) / 2);
  return 0;
}
