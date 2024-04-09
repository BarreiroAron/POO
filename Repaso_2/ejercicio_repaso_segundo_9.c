#include <stdio.h>

int main() {
    int edad_padre = 50;
    int edad_hijo = 20;
    int anios = 0;

    // Incrementa las edades hasta que la edad del padre sea el doble que la del hijo
    while (edad_padre != 2 * edad_hijo) {
        edad_padre++;
        edad_hijo++;
        anios++;
    }

    printf("Dentro de %d años,\n", anios);

    return 0;
}
