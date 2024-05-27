#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5];

    printf("Introduce 5 números:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Los números en orden inverso son:\n");
    for (int i = 10; i >= 0; i--) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
