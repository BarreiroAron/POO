//RogueGame.c 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include "RogueVoids.h"
//#include "miniaudio.h"

//ESTA PARTE DE LAS FUNCIONES INCLUYEN:
//Las opciones del 2 al 4 (La opcion 1 es un conjunto de llamadas en el main).
//mostrarMenu, una funcion para mostrar el menu el cual aparece despues de ingresar el nombre

#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

void opcion2() {
    limpiar_consola();
    printf(BLUE"┌────────────────────────────────┐\n"RESET);
    printf(BLUE"│    Reglas del juego:           │\n"RESET);
    printf(BLUE"├────────────────────────────────┤\n"RESET);
    printf(BLUE"│- Tienes que llegar hasta       │\n"RESET);
    printf(BLUE"│  la mazmorra 3 y vencer al     │\n"RESET);
    printf(BLUE"│  jefe.                         │\n"RESET);
    printf(BLUE"│                                │\n"RESET);
    printf(BLUE"│- En cada mazmorra              │\n"RESET);
    printf(BLUE"│  habrán enemigos que           │\n"RESET);
    printf(BLUE"│  tratarán de matarte           │\n"RESET);
    printf(BLUE"│ estos traen sus stats:         │\n"RESET);
    printf(BLUE"│ Fuerza, Vida. Al igual         │\n"RESET);
    printf(BLUE"│ que tu personaje.              │\n"RESET);
    printf(BLUE"│                                │\n"RESET);
    printf(BLUE"│- También habrán                │\n"RESET);
    printf(BLUE"│  objetos que mejorarán tus     │\n"RESET);
    printf(BLUE"│  capacidades, como la vida     │\n"RESET);
    printf(BLUE"│  o la fuerza.                  │\n"RESET);
    printf(BLUE"└────────────────────────────────┘\n"RESET);
    printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
}

void opcion3() {
    limpiar_consola();
    printf(MAGENTA"                            ┌─────┐               w: moverte hacia arriba\n"RESET);
    printf(MAGENTA"                            │  w  │\n"RESET);
    printf(MAGENTA"                            └─────┘               a: moverte hacia la izquierda\n"RESET);
    printf(MAGENTA"                    ┌─────┐ ┌─────┐  ┌─────┐\n"RESET);
    printf(MAGENTA"                    │  a  │ │  s  │  │  d  │      s: moverte hacia abajo\n"RESET);
    printf(MAGENTA"                    └─────┘ └─────┘  └─────┘\n"RESET);
    printf(MAGENTA"                                                  d: moverte hacia la derecha\n"RESET);
     printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
}

/*void opcion4() {
    limpiar_consola();
    printf(RED"Skull: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
    cargarImagen("skull.txt");

    printf(RED"Warrior: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
    cargarImagen("warrior.txt");
            
     printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
}*/
void opcion4() {
    struct termios old_tio;
    desactivarModoCanonico(&old_tio);
    limpiar_consola();
    char tecla;

    printf(RED"Skull: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
    printf(RED"Warrior: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
    printf(WHITE"Presiona 'S' para ver a Skull y 'W' para ver a Warrior.\n"RESET);
    printf(RED"'Esc' para salir\n"RESET);

    while (1) {
        tecla = getchar();
        if (tecla == 'S' || tecla == 's') {
            limpiar_consola();
            cargarImagen("skull.txt");
            puts("");
            printf(RED"'Esc' para salir\n"RESET);
        } else if (tecla == 'W' || tecla == 'w') {
            limpiar_consola();
            cargarImagen("warrior.txt");
            puts("");
            printf(RED"'Esc' para salir\n"RESET);
        } else if (tecla == 27) {
            limpiar_consola();
            break;
        }
    }
     restaurarModoCanonico(&old_tio);
}

void opcion5() {
    limpiar_consola();
    printf(GREEN"3: te da un aumento de vida de x cantidad\n"RESET);
    printf(GREEN"4: te da un aumento de vida de x cantidad\n"RESET);
     printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
}

void mostrarMenu() {
    //char nombreArchivo[] = "ROGUESONGCUBECAVERN.mp3"; // Cambia esto por la ruta de tu archivo de música
    //reproducirMusica(nombreArchivo);

    cargarImagen("ROGUE.txt");
    puts("");
    printf(CYAN"                                        ┌───────────────┐\n"RESET);
    printf(CYAN"                                        │ Menú:         │\n"RESET);
    printf(CYAN"                                        │---------------│\n"RESET);
    printf(CYAN"                                        │ 1. Jugar      │\n"RESET);
    printf(CYAN"                                        │ 2. Reglas     │\n"RESET);
    printf(CYAN"                                        │ 3. Controles  │\n"RESET);
    printf(CYAN"                                        │ 4. Enemigos   │\n"RESET);
    printf(CYAN"                                        │ 5. Items      │\n"RESET);
    printf(CYAN"                                        │ 6. Salir      │\n"RESET);
    printf(CYAN"                                        └───────────────┘\n"RESET);   
}
