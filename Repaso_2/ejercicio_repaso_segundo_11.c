int main() {
    int cal_final = 0;

  
    for (int i = 1; i <= 3; i++) {
        int cal;
        printf("Ingrese calificacion %d: ", i);
        scanf("%d", &cal);
        cal_final += cal; 
    }

    //dividimos para que la nota de las 3 pruebas se unan
    float promedio_cal = cal_final / 3.0;

    //promedio y su trabajo
    int promedio, final;
    printf("Ingrese su calificacion de promedio: ");
    scanf("%d", &promedio);
    printf("Ingrese su calificacion de trabajo final: ");
    scanf("%d", &final);

    // Calcular la nota final 
    float Nota_final = (promedio_cal * 55 / 100) + (promedio * 30 / 100) + (final * 15 / 100);

    printf("Nota final: %.2f\n", Nota_final);

    return 0;
//Al final en las cifras: 3, 6 y 9 me queda mal: en el 9 9.50. en el 6 4.30 y en el 3 1.65. Supongo que tengo que arreglarlo
}
