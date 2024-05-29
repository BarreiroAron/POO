#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3

void imprimirMatriz(char matriz[FILAS][COLUMNAS]) {
    puts("-----");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    puts("-----");
}

void jugar(char matriz[FILAS][COLUMNAS], int numeroFila, int numeroColumna) {
    imprimirMatriz(matriz);
    char x, o;
    while (1) {
        printf("Escoja el lugar de movimiento, jugador 1: ");
        scanf("%d %d", &numeroFila, &numeroColumna);
        matriz[numeroFila - 1][numeroColumna - 1] = 'x';
        imprimirMatriz(matriz);

        printf("Escoja el lugar de movimiento, jugador 2: ");
        scanf("%d %d", &numeroFila, &numeroColumna);
        matriz[numeroFila - 1][numeroColumna - 1] = 'o';
        imprimirMatriz(matriz);
        
    }
}

int main() {
    char matriz[FILAS][COLUMNAS];
    int numeroFila, numeroColumna;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = '*';
        }
    }

    jugar(matriz, numeroFila, numeroColumna);

    return 0;
}
