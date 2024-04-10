#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	puts("Ingrese los valores en fila y con un espacio de diferencia, por favor");
	scanf("%d %d", &a, &b);
	c = sqrt(a * a + b * b);
	printf("%d", c);
	return 0;
}
