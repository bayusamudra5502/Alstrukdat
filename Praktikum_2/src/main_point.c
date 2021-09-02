/* File: main_point.c */
/* Tanggal: 31 Agustus 2021 */
// DRiver ADT Point

// Nama : Bayu Samudra
// NIM : 13520128

#include <math.h>
#include <stdio.h>

#include "point.h"

int main() {
  POINT p;

  printf("Silahkan masukan titik yang diinginkan\n");
  BacaPOINT(&p);

  printf("Titik yng diinput adalah ");
  TulisPOINT(p);

  printf("\n\nJarak dari titik (0,0) adalah %f\n", Jarak0(p));

  return 0;
}