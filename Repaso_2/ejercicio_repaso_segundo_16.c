#include <stdio.h>

int main() {
    float pesosArg;
    puts("¡Vamos a cambiar monedas!");
    puts("Cuantos pesos Argentinos me trajiste?");
    scanf("%f", &pesosArg);
    float dolar = pesosArg / 1000;
    printf("Toma tus dolares %.2f\n", dolar);
    return 0;
}
