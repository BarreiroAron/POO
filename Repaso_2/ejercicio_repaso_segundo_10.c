#include <stdio.h>

int main() {
    int segundos_ingresados = 0;
    int minutos, horas, segundos = 0;

    puts("Ingrese los segundos para transformarlos:");
    scanf("%d", &segundos_ingresados);

    // Calcula las horas, minutos y segundos
    horas = segundos_ingresados / 3600; //cuenta normal
    minutos = (segundos_ingresados % 3600) / 60; // hacemos el resto dividido 60.
                                                //Ya que el resto es lo que sobra de las horas
    segundos = segundos_ingresados % 60; // hacemos solo el resto, sin necesidad de las sobras anteriores

    printf("%d segundos son %d horas, %d minutos y %d segundos.\n", segundos_ingresados, horas, minutos, segundos);

    return 0;
}
