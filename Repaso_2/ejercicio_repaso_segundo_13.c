#include <stdio.h>

int main() {
float costo = 0;
puts("Costo de la compra");
scanf("%f", &costo);
puts("Ingrese el descuento (Numeros del uno al cien)");
float descuento = 0;
scanf("%f", &descuento);
float lol = costo * (descuento / 100);
printf("%2.f", lol);
return 0;
}
