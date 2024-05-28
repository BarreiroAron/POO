#include <stdio.h>

int main() {
    int numeros[10];
    int mayor;
    int i;

    printf("Ingrese 10 numeros enteros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    for (i = 1; i < 10; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    printf("\nEl numero mas grande es: %d\n", mayor);
    return 0;
}
