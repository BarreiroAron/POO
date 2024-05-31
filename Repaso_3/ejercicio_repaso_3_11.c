#include <stdio.h>

void calcularProductoVectorial(float ux, float uy, float uz, float vx, float vy, float vz, float *wx, float *wy, float *wz) {
    *wx = uy * vz - uz * vy;
    *wy = uz * vx - ux * vz;
    *wz = ux * vy - uy * vx;
}

int main() {
    float ux, uy, uz;
    float vx, vy, vz;
    float wx, wy, wz;
    
    printf("Ingresa las coordenadas de u en x, y, z\nU:");
    scanf("%f %f %f", &ux, &uy, &uz);
    printf("Ingresa las coordenadas de y en x, y, z\nY:");
    scanf("%f %f %f", &vx, &vy, &vz);
    
    calcularProductoVectorial(ux, uy, uz, vx, vy, vz, &wx, &wy, &wz);
    int a[3] = {wx, wy, wz};
    printf("El producto vectorial es: (%.2f, %.2f, %.2f)\n\n", wx, wy, wz);
    //Agrego algo de matricez xd porque no las estoy usando
    /*
    for(int i = 0; i < 3; i++) {
        printf("%d", a[i]);
        printf("\n\n");
    }
    */
    return 0;
}
