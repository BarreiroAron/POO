#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int primer_numero = atoi(argv[1]);
  int segundo_numero = atoi(argv[2]);
//se crea un loop para leer el primer numero y segundo, los cuales ingresa el usuario.
//     En eso. Detecta si el resto de una division entre el primero numero ingresado y 2 es 0. Si es asi: Imprime esos numeros (los cuales son pares)
//     el programa acaba cuando el primer numero llega al segundo
  for(int i = primer_numero; i <= segundo_numero; i++) {
    if(i % 2 == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}
