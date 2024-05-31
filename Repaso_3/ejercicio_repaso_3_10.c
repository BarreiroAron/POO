#include <stdio.h>

int main() {
    float ux, uy, uz; 
    float vx, vy, vz; 
    float diferencia1, diferencia2, diferencia3;
    
    printf("Ingrese las coordenadas U en orden de x, y, z\nx y z:");
    scanf("%f %f %f", &ux, &uy, &uz);
    printf("Ingrese las coordenadas V en orden de x, y, z\nx y z:");
    scanf("%f %f %f", &vx, &vy, &vz);
    
    diferencia1 = ux * vx; diferencia2 = uy * vy; diferencia3 = uz * vz;
    
    printf("El producto escalar es: %2.f", (diferencia1 + diferencia2 + diferencia3));
    return 0;
}
