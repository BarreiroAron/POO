#include <stdio.h>

int main() {
    int numero;
    scanf("%d", &numero);
    if(numero == 0) { printf("No te hagas el vivo"); return 0; }
    if(numero < 0)  numero = numero * -1;
    printf("%d\n", numero);
    return 0;
//multiplico el numero por -1 cuando es menor a 0, esto para que siempre se vuelva positivo
}
