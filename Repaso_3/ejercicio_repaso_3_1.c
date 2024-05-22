#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int uno, dos, tres, cuatro;
    puts("B I E N V E N I D O");
    puts("Ingrese cuatro numeros por favor!");
    scanf("%d %d %d %d", &uno, &dos, &tres, &cuatro);
    int suma = (uno + dos + tres + cuatro);
    int aritmetica = suma / 4;
    
    
    printf("Usted a ingresado: %d, %d, %d y %d. \n", uno, dos, tres, cuatro);
    printf("Su medida aritmetica de 4 es: %d \n\n", aritmetica);
    printf("Su cuenta ha sido: suma de %d, %d, %d, %d. . . dividido la cantidad de numeros que se ingreso (4). . .\n", uno, dos, tres, cuatro);
    return 0;
}
