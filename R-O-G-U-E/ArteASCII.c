#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include "RogueVoids.h"

void cargarImagen(char *nonvre) {
  FILE *f = fopen(nonvre, "r");
  if(f) {
    char CE;
    while((CE = fgetc(f)) != EOF) {
      putc(CE, stdout);
    }
    fclose(f);
  } else {
    printf("No existe un formato para este enemigo\n");
  }
}
