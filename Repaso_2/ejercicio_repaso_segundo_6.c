#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	double sueldo;
	double impuesto;
	double sueldototal;
	
	printf("Ingrese su sueldo: ");
	scanf("%lf", &sueldo);

	if(sueldo <= 202){
	    impuesto = 0;
	}
	else if(sueldo > 202 && sueldo <= 607){
	    impuesto = sueldo / 100 * 5;
	}
	else if(sueldo > 607 && sueldo <= 1013){
	    impuesto = sueldo / 100 * 10;
	}
	else if(sueldo > 1013 && sueldo <= 1418){
	    impuesto = sueldo / 100 * 15;
	}
	else if(sueldo > 1418){
	    impuesto = sueldo / 100 * 25;
	}
	
	sueldototal = sueldo - impuesto;
	
	printf("\nSu sueldo es: %.2f", sueldototal);
	
return 0;
}
