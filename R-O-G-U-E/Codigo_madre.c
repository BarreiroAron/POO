#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <conio.h>  // Biblioteca necesaria para getch()

#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

void limpiar_consola() {
    printf("\033[H\033[J");
}

void bienvenida(char nombre[20]) {
    while (1) {
        printf(WHITE"Bienvenido jugador. Ingrese su nombre: "RESET);
        scanf("%s", nombre);
        limpiar_consola();
        break;
    }
}

void rellenarMazmorras(int tamañomazmorra, char dungeon[tamañomazmorra][tamañomazmorra], int dificultad) {
    srand(time(NULL));
    int r;
    char enemigos[2] = {'1', '2'};
    for (int i = 0; i < tamañomazmorra; i++) {
        for (int j = 0; j < tamañomazmorra; j++) {
            r = rand() % 10;
            if (r > dificultad) {
                dungeon[i][j] = '*';
            } else {
                dungeon[i][j] = enemigos[rand() % 2];
            }
        }
    }
}

void imprimirMazmorra(int tamañomazmorra, char dungeon[tamañomazmorra][tamañomazmorra], int fila, int columna) {
    for (int i = fila - 1; i <= fila + 1; i++) {
        for (int j = columna - 1; j <= columna + 1; j++) {
            if (i >= 0 && i < tamañomazmorra && j >= 0 && j < tamañomazmorra) {
                printf("%c ", dungeon[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void actualizar_mazmorra(int n, char mazmorra[n][n], int fila, int columna, int fila_nueva, int columna_nueva, char *original) {
    mazmorra[fila][columna] = *original; // Restaurar el valor original
    *original = mazmorra[fila_nueva][columna_nueva]; // Guardar el valor de la nueva casilla
    mazmorra[fila_nueva][columna_nueva] = '5'; // Mover al jugador
}

// Función para desactivar el modo canonico y el eco
void desactivarModoCanonico(struct termios *old_tio) {
    struct termios new_tio;

    // Guardar la configuración actual del terminal
    tcgetattr(STDIN_FILENO, old_tio);

    // Desactivar el modo canónico y el eco
    new_tio = *old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    new_tio.c_cc[VMIN] = 1;
    new_tio.c_cc[VTIME] = 0;

    // Establecer los nuevos atributos
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

// Función para restaurar el modo canonico y el eco
void restaurarModoCanonico(struct termios *old_tio) {
    // Restaurar los atributos del terminal
    tcsetattr(STDIN_FILENO, TCSANOW, old_tio);
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
        } else {
            limpiar_consola();
            imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);
            puts("Opción inválida");
            continue;
        }

        if (nuevafila < 0 || nuevafila >= Nmazmorra || nuevacolumna < 0 || nuevacolumna >= Nmazmorra) {
            puts("Movimiento fuera de los límites.");
            continue;
        }

        actualizar_mazmorra(tamañomazmorra, mazmorra, fila, columna, nuevafila, nuevacolumna, &original);
        fila = nuevafila;
        columna = nuevacolumna;
        limpiar_consola();
        imprimirMazmorra(tamañomazmorra, mazmorra, fila, columna);
    }

    restaurarModoCanonico(&old_tio);
    return 0;
}

void opcion2() {
    limpiar_consola();
    printf(BLUE"┌───────────────────────────────┐\n" RESET);
    printf(BLUE"│    Reglas del juego:           │\n"RESET);
    printf(BLUE"├────────────────────────────────┤\n"RESET);
    printf(BLUE"│- Tienes que llegar hasta       │\n"RESET);
    printf(BLUE"│  la mazmorra 3 y vencer al     │\n"RESET);
    printf(BLUE"│  jefe.                         │\n"RESET);
    printf(BLUE"│                                │\n"RESET);
    printf(BLUE"│- En cada mazmorra              │\n"RESET);
    printf(BLUE"│  habrán enemigos que           │\n"RESET);
    printf(BLUE"│  tratarán de matarte           │\n"RESET);
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
    printf(MAGENTA"        ┌─────┐               w: moverte hacia arriba\n"RESET);
    printf(MAGENTA"        │  w  │\n"RESET);
    printf(MAGENTA"        └─────┘               a: moverte hacia la izquierda\n"RESET);
    printf(MAGENTA"┌────┐ ┌─────┐  ┌─────┐\n"RESET);
    printf(MAGENTA"│  a  │ │  s  │  │  d  │      s: moverte hacia abajo\n"RESET);
    printf(MAGENTA"└─────┘ └─────┘  └────┘\n"RESET);
    printf(MAGENTA"                              d: moverte hacia la derecha\n"RESET);
     printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
}

void opcion4() {
    limpiar_consola();
    printf(RED"1: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
    printf(RED"2: Tiene x cantidad de vida. Te quita x cantidad de vida\n"RESET);
     printf(WHITE"Presiona Enter para salir\n"RESET);
    while (getchar() != '\n');
    limpiar_consola();
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
    printf(CYAN"┌──────────────┐\n"RESET);
    printf(CYAN"│ Menú:         │\n"RESET);
    printf(CYAN"│ 1. Jugar      │\n"RESET);
    printf(CYAN"│ 2. Reglas     │\n"RESET);
    printf(CYAN"│ 3. Controles  │\n"RESET);
    printf(CYAN"│ 4. Enemigos   │\n"RESET);
    printf(CYAN"│ 5. Items      │\n"RESET);
    printf(CYAN"│ 6. Salir      │\n"RESET);
    printf(CYAN"└──────────────┘\n"RESET);
}

int main(int argc, char *argv[]) {
    char jugador = '5';
    char mazmorra1[15][15];
    int opcion;
    char nombre[20];
    
    printf(YELLOW"┌───────────────────────────────────────┐\n"RESET);
    printf(YELLOW"│           Juego de Mazmorra           │\n"RESET);
    printf(YELLOW"└──────────────────────────────────────┘\n"RESET);
    bienvenida(nombre);
    limpiar_consola();
    mostrarMenu();
    
    while (1) {
        printf(WHITE"Ingrese una opción: "RESET);
        int l = 0;
        if (scanf("%d", &opcion) != 1) {
            // Limpiar el buffer de entrada en caso de entrada no válida
            while ((l = getchar()) != '\n');
            printf(RED"Opción inválida. Por favor, ingrese una opción válida.\n" RESET);
            continue;
        }
        
        getchar(); // Captura el Enter después de ingresar la opción
        
        switch (opcion) {
            case 1:
                limpiar_consola();
                 for (int cargando = 0; cargando <= 100; cargando += 5) {
          printf("┌─────────────────────────────────┐\n");
          printf("│          Cargando:%3d%%           │\n", cargando);
          printf("│                                  │\n");
          printf("└──────────────────────────────────┘\n");
          usleep(200000); // Pausa de 0.2 segundos
          limpiar_consola();
        }
                rellenarMazmorras(15, mazmorra1, 4);
                movimientos(15, 15, mazmorra1, jugador);
                limpiar_consola();
                mostrarMenu();
                break;
            case 2:
                opcion2();
                limpiar_consola();
                mostrarMenu();
                break;
            case 3:
                opcion3();
                limpiar_consola();
                mostrarMenu();
                break;
            case 4:
                opcion4();
                limpiar_consola();
                mostrarMenu();
                break;
            case 5:
                opcion5();
                limpiar_consola();
                mostrarMenu();
                break;
            case 6:
                limpiar_consola();
                 for (int i = 0; i <= 100; i += 10) {
               for (int i = 0; i < 3; i++) {
    printf(WHITE"┌─────────────────────────┐\n"RESET);
    printf(WHITE"│       Saliendo"RESET);
    for (int j = 0; j <= i; j++) {
        printf(WHITE"."RESET);
    }
    printf(WHITE"       │\n"RESET);
    printf(WHITE"└─────────────────────────┘\n"RESET);
    usleep(200000); // 200,000 microsegundos = 0.2 segundos
    limpiar_consola();
}
                 usleep(200000);
                 limpiar_consola();
                 }
                return 0;
            default:
                printf(RED"Opción inválida. Por favor, ingrese una opción válida.\n"RESET);
                break;
        }
    }
    
    return 0;
}
