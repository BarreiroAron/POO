#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include "RogueVoids.h"
#include <locale.h>

void desactivarModoCanonico(struct termios *old_tio) {
  struct termios new_tio;

  // Guardar la configuración actual del terminal
  tcgetattr(STDIN_FILENO, old_tio);

  // Desactivar el modo canónico y el eco
  new_tio = *old_tio;
  new_tio.c_lflag &= (~ICANON & ~ECHO);
  new_tio.c_cc[VMIN] = 1;
  new_tio.c_cc[VTIME] = 0;

  // Establecer los nuevos atributos
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void restaurarModoCanonico(struct termios *old_tio) {
  // Restaurar los atributos del terminal
  tcsetattr(STDIN_FILENO, TCSANOW, old_tio);
}
