#include <stdio.h>

#include "listrec.h"

int main() {
  // Halo
  List l = NULL;

  printf("isEmpty : %d\n", isEmpty(l));
  printf("isOneElmt : %d\n", isOneElmt(l));
  printf("length : %d\n", length(l));
  printf("[");
  displayList(tail(l));
  printf("]\n\n");

  l = konsb(l, 10);
  printf("isEmpty : %d\n", isEmpty(l));
  printf("isOneELmt : %d\n", isOneElmt(l));
  printf("length : %d\n", length(l));

  printf("[");
  displayList(tail(l));
  printf("]\n\n");

  l = konso(l, 1);
  l = konso(l, 2);
  l = konso(l, 3);

  printf("isEmpty : %d\n", isEmpty(l));
  printf("isOneELmt : %d\n", isOneElmt(l));
  printf("length : %d\n\n", length(l));

  l = konsb(l, 4);
  l = konsb(l, 5);
  l = konsb(l, 6);

  printf("isEmpty : %d\n", isEmpty(l));
  printf("isOneELmt : %d\n", isOneElmt(l));
  printf("length : %d\n\n", length(l));

  printf("[\n");
  displayList(l);
  printf("]\n\n");

  printf("[\n");
  displayList(tail(l));
  printf("]\n");

  return 0;
}