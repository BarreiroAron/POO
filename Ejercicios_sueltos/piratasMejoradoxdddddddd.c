#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pc;
    int pf;
    int tc;
    int tf;
    int fila = 8, columna = 8;
 //   puts("Ingrese fila:");
 //   scanf("%d", &fila);
 //   puts("Ingrese columna:");
 //   scanf("%d", &columna);

    //viendo si las dimensiones son positivas
    if (fila <= 0 || columna <= 0) {
        printf("Las dimensiones deben ser positivas.\n");
        return 1;
    }

    char a[fila][columna];
    srand(time(NULL));
     pc=(rand()%6)+1;
     pf=(rand()%6)+1;
     tc=(rand()%6)+1;
     tf=(rand()%6)+1;
    int randomFila = (rand()% 6 ) +1;
    int randomColumna = (rand() % 6)+ 1;
    // iniciar la matriz e imprimirla
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            // asignar "o" a los bordes de la matriz
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                a[i][j] = 'o';
            } else {
                                                        
                a[i][j] = 'x';  // asignar 'o' al interior de la matriz
                a[randomFila][randomColumna] = 'P';
            }
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
