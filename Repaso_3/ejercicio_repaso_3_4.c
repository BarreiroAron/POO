#include <stdio.h>
#include <stdlib.h>

int main() {
    int dias_acumulados[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int mes, dia, dia_del_anio;
    printf("Introduce el numero del mes: ");
    scanf("%d", &mes);
    printf("Introduce el dia del mes: ");
    scanf("%d", &dia);


    if (mes < 1 || mes > 12) {
        printf("No te salgas de los meses\n");
        return 1;  
    }
    if (dia < 1 || dia > 31) {
        printf("No te salgas de los dias.\n");
        return 1;  
    }

    dia_del_anio = dias_acumulados[mes - 1] + dia;
    printf("El dia %d del mes %d es el dia numero %d del anio.\n", dia, mes, dia_del_anio);

    return 0;
}
