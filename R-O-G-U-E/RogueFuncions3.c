            #include <stdio.h>
            #include <stdlib.h>
            #include <time.h>
            #include <unistd.h>
            #include <termios.h>
            #include "RogueVoids.h"
            #include <locale.h>
            //ESTA PARTE DE LAS FUNCIONES INCLUYEN:
            // 1. pelea, una funcion aun en proceso para el momento en donde tengamos que luchar contra un enemigo.
            // 2. movimientos, el cual sirve para que el usuario mueva a su jugador, esta incluye muchas cosas como funciones de desactivarmodoCanonico (para sacar la necesidad de presionar "enter"), if's (Para lograr moverse), whiles, llamado de funciones como "imprimirMazmorra", etc.
//3. Mostrarmapa, el cual sirve para que el jugador abra el mapa y vea su ubicacion.

            #define YELLOW  "\033[1;33m"
            #define RED     "\033[1;31m"
            #define BLUE    "\033[1;34m"
            #define RESET   "\033[0m"
            #define GREEN   "\033[1;32m"
            #define MAGENTA "\033[1;35m"
            #define CYAN    "\033[1;36m"
            #define WHITE   "\033[1;37m"

            #define CRAW "\U0001f980"
            #define SKULL "💀"

            void pelea(char jugador, char enemigo) {
                setlocale(LC_ALL, "");
                limpiar_consola();
                if(enemigo == 'C') {cargarImagen("skull.txt");}
                if(enemigo == 'W') {cargarImagen("warrior.txt");}
                puts("");
                puts("--------------------------------------------------------------------------------------------------------------");
                printf("%c                       %c\n", jugador, enemigo);
                printf("Elija su movimiento:\n");
                printf(CYAN"Ataque basico (1)\n"RESET);
                printf(RED"Ataque pesado (2)\n"RESET);
                printf(CYAN"Defenderse (3)\n"RESET);
                printf(RED"Escapa! (4)\n"RESET);
            }
void mostrarmapa(int tamañomazmorra, char mazmorra[tamañomazmorra][tamañomazmorra], char jugador){
    limpiar_consola();
     printf("-----------------------------------------------------------------------------------------------------\n");
      for (int i = 0; i <= tamañomazmorra; i++) {
          for (int j = 0; j <= tamañomazmorra; j++) {
           if(mazmorra[i][j] == 'C' || mazmorra[i][j] == 'W'){
              printf("%c ", '?');
          } 
             else if(mazmorra[i][j] == '@'){
                     printf("%c", '*');
                 } 
          else{
              printf("%c ", mazmorra[i][j]);
          }
          }
            printf("\n");
          }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Presione enter para seguir moviendose\n");
    while (getchar() != '\n');
    limpiar_consola();
}
            int movimientos(int Nmazmorra, int tamañomazmorra, char mazmorra[tamañomazmorra][tamañomazmorra], char jugador) {
                srand(time(NULL));
                int fila = rand() % Nmazmorra;
                int columna = rand() % Nmazmorra;
                int nuevafila = fila;
                int nuevacolumna = columna;
                char movimiento;
                char original = mazmorra[fila][columna];
                mazmorra[fila][columna] = jugador;
                limpiar_consola();
                imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);

                struct termios old_tio;
                desactivarModoCanonico(&old_tio);

                while (1) {
                    movimiento = getchar();  // Lee un carácter sin necesidad de presionar Enter

                    if (movimiento == 'w') {
                        nuevafila = fila - 1;
                        nuevacolumna = columna;
                    } else if (movimiento == 'a') {
                        nuevafila = fila;
                        nuevacolumna = columna - 1;
                    } else if (movimiento == 's') {
                        nuevafila = fila + 1;
                        nuevacolumna = columna;
                    } else if (movimiento == 'd') {
                        nuevafila = fila;
                        nuevacolumna = columna + 1;
                    } else if(movimiento == 'm'){
                        mostrarmapa(tamañomazmorra, mazmorra, jugador);
                            }
                    else {
                        limpiar_consola();
                        imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);
                        puts("Opción inválida");
                        continue;
                    }

                    if (nuevafila < 0 || nuevafila >= Nmazmorra || nuevacolumna < 0 || nuevacolumna >= Nmazmorra) {
                        limpiar_consola();
                        imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);
                        puts("Movimiento fuera de los límites.");
                        continue;
                    }

                    actualizar_mazmorra(tamañomazmorra, mazmorra, fila, columna, nuevafila, nuevacolumna, &original);
                    fila = nuevafila;
                    columna = nuevacolumna;
                    limpiar_consola();
                    imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);

                    char guardado;
                    if (mazmorra[fila][columna + 1] == 'C' || mazmorra[fila][columna + 1] == 'W') {
                        guardado = mazmorra[fila][columna + 1];
                    }
                    if (mazmorra[fila][columna - 1] == 'C' || mazmorra[fila][columna - 1] == 'W') {
                        guardado = mazmorra[fila][columna - 1];
                    }
                    if (mazmorra[fila + 1][columna] == 'C' || mazmorra[fila + 1][columna] == 'W') {
                        guardado = mazmorra[fila + 1][columna];
                    }
                    if (mazmorra[fila - 1][columna] == 'C' || mazmorra[fila - 1][columna] == 'W') {
                        guardado = mazmorra[fila - 1][columna];
                    }
                    if ((mazmorra[fila][columna + 1] == 'C' || mazmorra[fila][columna + 1] == 'W') || 
                        (mazmorra[fila + 1][columna] == 'C' || mazmorra[fila + 1][columna] == 'W') || 
                        (mazmorra[fila][columna - 1] == 'C' || mazmorra[fila][columna - 1] == 'W') || 
                        (mazmorra[fila - 1][columna] == 'C' || mazmorra[fila - 1][columna] == 'W')) {
                         printf(RED"Aparecio un enemigo\n"RESET);
                        for(int i = 0; i < 5; i++){
                            usleep(200000);
                    }
                        limpiar_consola();
                        for (int cargando = 0; cargando <= 100; cargando += 10) {
                            printf("┌──────────────────────────────────┐\n");
                            printf("│          Cargando:%3d%%           │\n", cargando);
                            printf("│                                  │\n");
                            printf("└──────────────────────────────────┘\n");
                            usleep(200000); // Pausa de 0.2 segundos
                            limpiar_consola();
                        }
                        pelea(jugador, guardado);
                    }
                }
                restaurarModoCanonico(&old_tio);
                return 0;
            }
