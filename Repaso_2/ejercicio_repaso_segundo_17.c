#include <stdio.h>

int main() {
    int edad = 0;
    float peso = 0.0;
    float unPorcientoDelPeso = 0.0;
    int detector = 0;
    float FCM = 0.0; 
    
//decoracion
    puts("¿Es hombre o mujer?");
    puts("Si es hombre ponga: 0");
    puts("Si es mujer ponga: 1");
    scanf("%d", &detector);
    
    puts("Ingrese la edad del individuo, por favor");
    scanf("%d", &edad);
    
    puts("Ingrese el peso del individuo, por favor");
    scanf("%f", &peso); 
    unPorcientoDelPeso = peso * 0.01; 
    
//detectores para saber con quien tratamos
    if (detector == 0) { // hombre
        FCM = ((210 - (0.5 * edad)) - unPorcientoDelPeso) + 4;
    } else if (detector == 1) { // mujer
        FCM = (210 - (0.5 * edad)) - unPorcientoDelPeso;
    }
    
    printf("FCM: %.2f\n", FCM); 
    
    return 0;
}
