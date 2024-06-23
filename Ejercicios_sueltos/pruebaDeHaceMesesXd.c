#include <stdio.h>

void opcion1() {
	int anio;
	puts("ANIO BISIESTO O NO? ? ? \n");
	puts("Ingrese el anio que quiere:");
    scanf("%d", &anio);
//Hago una cuenta (condicion) con restos para determinar si es bisiesto o no.
if(anio % 4 == 0 && anio % 100 != 0) {
	printf("Es bisiesto. \n");
} else { 
printf("No es bisiesto. \n");
}
}

int opcion2() {
	int numero;
	puts("Ingrese un numero");
	scanf("%d", &numero);
	if(numero <= 0) { puts("No"); return 0; }
	//Hago un for para que el numero ingresado se multiplique en su tabla del 10. Si es negativo: Termina el programa.
	for(int i = 1; i <= 10; i++) {
		printf("numero: %d * %d = %d\n" , numero, i, numero * i);
	}
}

int opcion3() {
	float pago = 10000;
	int entradas;
	puts("Ingrese cuantas entradas va a comprar");
	scanf("%d", &entradas);
	if(entradas >= 5 || entradas <= 0)  printf("Rompiste el codigo!");  
	if(entradas == 1) printf("El coste de la entrada es %d: %.2f \n", entradas, (pago * entradas));
	
	if(entradas == 2) printf("El descuento de %d entradas es: %.2f \n", entradas, (pago * entradas) * 0.2);
	
	if(entradas == 3) printf("El descuento de %d es: %.2f \n", entradas, (pago * entradas) * 0.15);
	
	if(entradas == 4) printf("El descuento de %d es: %.2f \n", entradas, (pago * entradas) * 0.4);
	} //Hago el un * 0.x para determinar el resto de los descuentos
	
	void opcion4() {
		int tarifas = 6500;
		int personas;
		puts("Ingrese la cantidad de personas que hay en el lugar:");
		scanf("%d", &personas);
		if(personas > 300) {
			printf("Costo de las tarifas: %d \n", personas * 4500);
		} else if (personas > 200 && personas <= 300) {
			printf("Costo de las tarfias: %d \n", personas * 5500);
		} else {
		printf("Costo de las tarfias: %d \n", personas * tarifas);
		}
	} // Estoy haciendo la cantidad de personas por lo que cuesta si x cantidad de gente viene.
	
	int opcion5() { 
	char tipo;
	int tamanio;
	puts("Por favor, solo ponga A o B");
	puts("Ingrese el tipo:");
	scanf("%c", &tipo); 
	
	puts("Por favor, solo ponga 1 o 2");
	puts("Ingrese el tamanio:");
	scanf("%d", &tamanio);
	
	if(tipo == 65 && tamanio == 1) {
		printf("%d\n", 200);
	}	
	
	if(tipo == 65 && tamanio == 2) {
		printf("%d\n", 300);
	}
	
		
	if(tipo == 66 && tamanio == 1) {
		printf("%d\n", 300);
	}
	
		
	if(tipo == 66 && tamanio == 2) {
		printf("500\n");
	}
	} //Veo el tamaño y el tipo. Con eso imprimo cuanto deberia costar (Me siento mal por que no se me ocurre otra cosa que no se a if...)

int main() {
	int opcion;
	puts("Introduzca el ejercicio que quiere hacer.");
	puts("Hay 5 en total. Con la sexta opcion se sale");
	printf("Opcion: ");
	scanf("%d", &opcion);
	puts("\n");
	switch(opcion) {
		case 1: 
		opcion1();
		break;
		case 2:
			opcion2();
			break;
			case 3:
				opcion3();
				break;
				case 4:
				opcion4();
				break;
				case 5:
                opcion5();
				default:
					puts("No conozco esa opcion. . . .");
					break;
				}
return 0;
}
