#include <stdio.h>
#include <stdlib.h>

int main() {
    int calendario[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes;

    printf("Introduce un mes (1=enero, 12=diciembre): ");
    scanf("%d", &mes);

    if (mes >= 1 && mes <= 12) {
        printf("El mes %d tiene %d días.\n", mes, calendario[mes - 1]);
        for(int i = 0; i < calendario[mes - 1]; i++) {
            printf("%d ", i);
            if(i == 5 || i == 10 || i == 15 || i == 20 || i == 25 || i == 30)
            printf("\n");
        }
        printf("\n");
    } else {
        printf("Mes inválido. Introduce un número entre 1 y 12.\n");
    }
    return 0;
}
