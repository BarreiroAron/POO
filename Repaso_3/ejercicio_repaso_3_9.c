#include <stdio.h>

int main() {
    float u1, u2; 
    float v1, v2; 
    float diferencia1, diferencia2; 

    printf("Ingresa las coordenadas del primer vector u:\nu1:");
    scanf("%f", &u1);
    printf("u2: ");
    scanf("%f", &u2);

    printf("Ingresa las coordenadas del segundo vector v:\nv1:");
    scanf("%f", &v1);
    printf("v2: ");
    scanf("%f", &v2);
    
    diferencia1 = u1 - v1;
    diferencia2 = u2 - v2;

    printf("La diferencia de los vectores (u - v) es: (%.2f, %.2f)\n", diferencia1, diferencia2);
    return 0;
}
