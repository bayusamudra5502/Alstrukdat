#include <stdio.h>

#include "time.h"

int main() {
  TIME t;
  printf("Silahkan masukan jam yang diinginkan\n");
  BacaTIME(&t);

  printf("Jam yang diinput adalah ");
  TulisTIME(t);

  printf("\nJumlah detiknya adalah adalah %ld\n", TIMEToDetik(t));

  return 0;
}