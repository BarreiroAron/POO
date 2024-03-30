#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[1]) {
  //pedi que ingresase el sueldo base. Una vez hecho eso, suma el sueldo + el 10% de ese sueldo, haciendo una cuenta matematica de sueldo * 10 (el porcentaje de comision) dividido 100.
    int sueldo_vendedor_mes;
  puts("Ingrese su sueldo: ");
  scanf("%d", &sueldo_vendedor_mes);
  printf("El sueldo a final del mes con 3 comisiones conceptuales extra son: %d\n", sueldo_vendedor_mes + (sueldo_vendedor_mes * 10 / 100));
  return 0;
}
