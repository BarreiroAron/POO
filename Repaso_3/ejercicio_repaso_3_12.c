#include <stdio.h>


int lineal(float u1, float u2, float v1, float v2) {
    if (u1 * v2 == u2 * v1) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    float u1, u2, v1, v2;

    printf("Ingresa las coordenadas del primer vector (u1, u2): ");
    scanf("%f %f", &u1, &u2);
    printf("Ingresa las coordenadas del segundo vector (v1, v2): ");
    scanf("%f %f", &v1, &v2);
    
    if (lineal(u1, u2, v1, v2)) {
        printf("Los vectores son linealmente dependientes.\n");
    } else {
        printf("Los vectores son linealmente independientes.\n");
    }
    return 0;
}
