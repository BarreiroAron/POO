#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3

//Una funcion para imrpimir la matriz
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

//una funcion para poner las x y o e los lugares 
void jugar(char matriz[FILAS][COLUMNAS], int numeroFila, int numeroColumna) {
    //Llamo a la funcion dentro de esta funcion "jugar" xd
    imprimirMatriz(matriz);
    char x, o;
    //hago un loop infinito que se va a parar solo cuando la condicion de vitoria se cumpla
    //(Aun no esta hecha la condicion de victoria)
    while (1) {
        //Esto es para el jugador 1, tiene numeroFila - 1 y numeroColumna - 1 para que en vez de ingresar:
        //0 0 hasta el 2 2, podamos poner 1 1 hasta el 3 3 y sea mas comodo para una persona normal
        printf("Escoja el lugar de movimiento, jugador 1: ");
        scanf("%d %d", &numeroFila, &numeroColumna);
        matriz[numeroFila - 1][numeroColumna - 1] = 'x';
        imprimirMatriz(matriz);

        //Lo mismo pero con jugador 2
        printf("Escoja el lugar de movimiento, jugador 2: ");
        scanf("%d %d", &numeroFila, &numeroColumna);
        matriz[numeroFila - 1][numeroColumna - 1] = 'o';
        imprimirMatriz(matriz);
        
    }
}

int main() {
    char matriz[FILAS][COLUMNAS];
    int numeroFila, numeroColumna;

    //Esto en el main hace que todas las matrices tengan "*" como default
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = '*';
        }
    }
    //Llamo a la funcion jugar, la cual llama primero y dentro de ella a la funcion imprimirMatriz, asi la imprime
    jugar(matriz, numeroFila, numeroColumna);

    return 0;
}
