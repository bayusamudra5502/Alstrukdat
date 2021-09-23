#include <stdio.h>

#include "matrix.h"

int main() {
  printf("Halo\n");
  Matrix m;
  readMatrix(&m, 2, 2);
  displayMatrix(m);

  return 0;
}
