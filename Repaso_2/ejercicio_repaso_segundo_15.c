#include <stdio.h>

int main() {
    int mujeres, hombres;
    puts("Ingrese la cantidad de hombres y mujeres en la misma línea con un espacio de separación, por favor");
    scanf("%d %d", &hombres, &mujeres);

    //sumamos el total de hombres y mujeres para saber cuanta gentuza hay en el aula
    int cantidad_total = hombres + mujeres;
    //hacemos el promedio, multiplicandolo por cien y despues dividiendolo por la cantidad total
    float porcentaje_mujeres = (mujeres * 100.0) / cantidad_total;
    float porcentaje_hombres = (hombres * 100.0) / cantidad_total;

    printf("El porcentaje de hombres es: %.2f%%\n", porcentaje_hombres);
    printf("El porcentaje de mujeres es: %.2f%%\n", porcentaje_mujeres);
    
    return 0;
}
