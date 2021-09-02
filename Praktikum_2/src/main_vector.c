#include <stdio.h>

#include "vector.h"

int main() {
  VECTOR v1 = MakeVector(2, 9);
  VECTOR v2 = MakeVector(3, 1);

  TulisVector(v1);
  printf("\n");

  TulisVector(v2);
  printf("\n");

  printf("Magnitude v2 : %.2f\n", Magnitude(v2));

  VECTOR vadd = Add(v1, v2);
  TulisVector(vadd);
  printf("\n");

  VECTOR vsubs = Substract(v1, v2);
  TulisVector(vsubs);
  printf("\n");

  printf("Dot Product v1 : %f\n", Dot(v1, v2));

  VECTOR vkali = Multiply(v2, 2.5);
  TulisVector(vkali);
  printf("\n");

  return 0;
}