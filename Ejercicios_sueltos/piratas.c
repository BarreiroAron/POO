#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int l;
    int j;
    int n;
    int s;
    int e;
    int o;
    int movimiento;
    int pc;
    int pf;
    int tc;
    int tf;
    int intentos = 0;
    puts("Ingrese el espacio de su tablero: ");
    scanf("%d", &l);
    

    int fila = l, columna = l;
    //viendo si las dimensiones son positivas
    if (fila <= 0 || columna <= 0) {
        printf("Las dimensiones deben ser positivas.\n");
        return 1;
    }

    char a[fila][columna];
    srand(time(NULL));
     pc=(rand()%(l - 2))+1;
     pf=(rand()%(l - 2))+1;
     tc=(rand()%(l - 2))+1;
     tf=(rand()%(l - 2))+1;
    // int randomFila = (rand()% 6 ) +1;
    // int randomColumna = (rand() % 6)+ 1;
    // iniciar la a e imprimirla
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            // asignar "o" a los bordes de la a
            if (i == 0 || i == fila - 1 || j == 0 || j == columna - 1) {
                a[i][j] = 'o';
            } else{

                a[i][j] = 'x';  // asignar 'o' al interior de la a
                if(pf != tf && pc != tc){
                a[pf][pc] = 'P';
                a[tf][tc] = 'T';
                }
            }
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    while(intentos <= 50){
        printf("a donde te quieres mover:1 es de Norte, 2 es de Sur, 3 es de Este y 4 es de Oeste: ");
        scanf("%d", &movimiento);
        printf("\n");
        int pfn = pf;
        int pcn = pc;

        if(movimiento == 1){
            a[pf - 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn - 1;
            pc = pcn;
        }
        else if(movimiento == 2){
            a[pf + 1][pc] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn + 1;
            pc = pcn;
        }
        else if(movimiento == 3){
            a[pf ][pc - 1] = 'P';
            a[pfn][pcn] = 'x';
            pf = pfn;
            pc = pcn - 1;
        }
        else if(movimiento == 4){
            a[pf][pc] = 'P';
            a[pfn][pcn + 1] = 'x';
            pf = pfn;
            pc = pcn + 1;
        }
         
             for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%c ", a[i][j]);
            }
            printf("\n");
        }
        intentos++;
    }
    return 0;
    
}
