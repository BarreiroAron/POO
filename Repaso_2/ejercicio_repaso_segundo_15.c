#include <stdio.h>

int main() {
    int mujeres, hombres;
    puts("Ingrese la cantidad de hombres y mujeres en la misma línea con un espacio de separación, por favor");
    scanf("%d %d", &hombres, &mujeres);

    int cantidad_total = hombres + mujeres;
    float porcentaje_mujeres = (mujeres * 100.0) / cantidad_total;
    float porcentaje_hombres = (hombres * 100.0) / cantidad_total;

    printf("El porcentaje de hombres es: %.2f%%\n", porcentaje_hombres);
    printf("El porcentaje de mujeres es: %.2f%%\n", porcentaje_mujeres);
    
    return 0;
}
