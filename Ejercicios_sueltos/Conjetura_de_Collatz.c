#include <stdio.h>

void funcion(int numero) { 
    while (numero != 1) {
        printf("%d ", numero);
        if (numero % 2 == 0) {
            numero = numero / 2;
        } else {
            numero = numero * 3 + 1;
        }
    }
    printf("%d ", numero); 
}

int main() {
    int numero = 0;
    puts("Ingresa un numero");
    scanf("%d", &numero);
    funcion(numero); 
    printf("\n");
    return 0; 
}
