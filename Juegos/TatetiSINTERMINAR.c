#include <stdio.h>
#include <stdlib.h>
//Esta va a ser la funcion que imprima la matriz
void imprimirMatriz(char fila, char columna, char matriz[3][3]) {
  //creamos la matriz mediante dos fors juntos
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      //Imprimir "-" para que el tablero en limpio se vea bien
      matriz[i][j]= '-';
      printf("%c ", matriz[i][j]);
    }
    //Imprimimos un salto de linea para que cambie al llegar a tres pritns
    printf("\n");
  }
}
//Esta va a ser la funcion que permita jugar al Ta te ti
void movimientoJuego(char jugador, char fila, char columna, int i, int j, char matriz[3][3], int filMov, int colMov, int jf1, int jf2, int jc1, int jc2){
  while(1){
    //creamos puts y scanf f para decoracion del programa, entendimiento y tambien el uso del juego 
  //(Jugador Uno)
    puts("j u g a d o r U N O");
    puts("Donde ira tu movimiento...?");
    puts("(Primer numero fila, segundo columna)");
    scanf("%d %d", &filMov, &colMov);
    matriz[filMov][colMov] = 'X';
    jf1 = fila;
    jc1 = columna;
    //creamos puts y scanf f para decoracion del programa,         entendimiento y tambien el uso del juego 
    //(Jugador Dos)
    puts("j u g a d o r D O S");
    puts("Donde ira tu movimiento...?");
    puts("(Primer numero fila, segundo columna)");
    scanf("%d %d", &filMov, &colMov);
    matriz[filMov][colMov] = 'O';
    jf2 = filMov;
    jc2 = colMov;
    //Movimientos de los jugadores
    if(jc1 == 1 && jc1 == 2 && jc1 == 3){
      puts("El jugador uno(X) es el ganador");
      return;
    }
    if(jf1 == 1 && jf1 == 2 && jf1 == 3){
      puts("El jugador uno(X) es el ganador");
      return;
    }
    if(jc2 == 1 && jc2 == 2 && jc2 == 3){
      puts("El jugador dos(O) es el ganador");
      return;
    }
    if(jf2 == 1 && jf2 == 2 && jf2 == 3){
      puts("El jugador dos(O) es el ganador");
      return;
    }
  }
}
//La funcion principal
int main() {
  //Creamos las variales que necesitamos
  int jf1, jc2, jf2, jc1;
  char jugador;
  int filMov, colMov;
  int tablero;
  int i, j;
  char matriz[3][3];
  int fila, columna;
  //Llamamos a las funciones que contiene el programa
  //Esta es para imprimir la matriz
  imprimirMatriz(fila, columna, matriz);
  //Esta es para los movimientos del juego
  movimientoJuego(jugador, fila, columna, i, j, matriz, fila, filMov, colMov, jf1, jf2, jc1, jc2);
  return 0;
  }
