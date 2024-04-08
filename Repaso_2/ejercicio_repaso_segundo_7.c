#include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char * argv[]) {
  int hh, mm;
  puts("oras owo");
  scanf("%d", &hh);
  puts("minutos");
  scanf("%d", &mm);
 
  if(hh >= 13) {
  printf("%d:%dpm\n", hh-12, mm);
 } else { printf("%d:%dam\n", hh, mm);
 }
  return 0;
 }
