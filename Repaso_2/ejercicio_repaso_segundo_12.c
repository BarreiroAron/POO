#include <stdio.h>
#include <stdlib.h>

int main() {
	float costo = 0;
	puts("Costo de la compra");
	scanf("%f", &costo);
	puts("Ingrese el descuento (Numeros del uno al cien)");
	float descuento = 0;
	scanf("%f", &descuento);
	float lol = costo * (descuento / 100);
	printf("%2.f\n", lol);
	return 0;
}
