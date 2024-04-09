#include <stdio.h>
#include <stdlib.h>

void opcion1() {
    int n;
    printf("Ingresa un numero: ");

    scanf("%d", &n);
    if(n > 0) {
        printf("\nEs positivo\n\n\n\n");
    } else {
        printf("\nEs negativo\n\n\n\n"); }
}


void opcion2() {
    int n;
    printf("Ingresa un numero: ");

    scanf("%d", &n);
    if(n % 2 == 0) {
        printf("\nEs par\n\n\n\n");
    } else {
        printf("\nEs impar\n\n\n\n");}
}


void opcion3() {
    int n;
    printf("Ingresa un numero: ");

    scanf("%d", &n);

    if(n == 0) {
        printf("xd\n");
    }

    if(n % 2 == 0 && n % 3 == 0) {
        printf("\nEs multiplo de los dos\n\n\n\n");
    } else if(n % 2 == 0) {
        printf("\nEs multiplo de dos\n\n\n\n");
    } else if(n % 3 == 0) {
        printf("\nEs multiplo de tres\n\n\n\n"); }
}


void opcion4() {
    int uno, dos, tres;
    printf("Ingresa tres numeros: ");

    scanf("%d %d %d", &uno, &dos, &tres);

    if(tres == dos && dos == uno) {
        printf("\nSon iguales\n\n\n\n"); }

    if(uno > dos && uno > tres) {
        printf("\nUno es el ganador\n\n\n\n"); }

    if(dos > uno && dos > tres) {
        printf("\nDos es el ganador\n\n\n\n");
    } else { printf("\nTres es el ganador\n\n\n\n"); }
}


int main() {
  while(1) {
    //system("clear");
    int opcion;
    puts("Selecciona una opcion:\n\n");
    puts("1. Determinar si un número es positivo o negativo");
    puts("2. Determinar si un numero es par o impar");
    puts("3. Determinar multiplos");
    puts("4. Comparar tres numeros");
    puts("5. Salir");
    puts("\nOpcion: \n");

    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            opcion3();
            break;
        case 4:
            opcion4();
            break;
        case 5:
            system("clear");
            puts("Saliendo. . .");
            puts("¡Vuelva pronto!");
            return 0;
        default:
            puts("\n\nNo conozco esa opcion. . . . .\n\n");
    }
  }
    return 0;
}
