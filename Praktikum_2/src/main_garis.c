#include <stdio.h>

#include "garis.h"
#include "point.h"

int main() {
  // Testing Garis
  POINT p1 = MakePOINT(7, 10);
  POINT p2 = MakePOINT(10, 14);

  POINT p30 = MakePOINT(0, 0);
  POINT p40 = MakePOINT(5, 0);

  GARIS g1, g0;
  MakeGARIS(p1, p2, &g1);
  MakeGARIS(p30, p40, &g0);

  TulisGARIS(g1);
  // printf("\n\n");
  // printf("============\nBaca Garis\n\n");

  // GARIS g2;
  // BacaGARIS(&g2);
  // printf("Hasil Baca Garis : ");
  // TulisGARIS(g2);
  // printf("\n");

  printf("\n%.2f\n", PanjangGARIS(g1));
  printf("Gradien : %f \n", Gradien(g1));
  printf("Gradien 2 : %f \n", Gradien(g0));

  GeserGARIS(&g1, 3, -2);
  TulisGARIS(g1);
  printf("\n");

  // Cek tegak lurus
  POINT p3 = MakePOINT(0, 0);
  POINT p4 = MakePOINT(-4, 3);

  GARIS g2, g3;
  MakeGARIS(p3, p4, &g2);
  MakeGARIS(p1, p2, &g3);

  printf("Tegak Lurus : %d\n", IsTegakLurus(g1, g2));
  printf("Tegak Lurus : %d\n", IsTegakLurus(g2, g1));
  printf("Tegak Lurus : %d\n", IsTegakLurus(g1, g3));

  printf("\n");

  printf("Sejajar : %d\n", IsSejajar(g1, g2));
  printf("Sejajar : %d\n", IsSejajar(g2, g1));
  printf("Sejajar : %d\n", IsSejajar(g1, g3));

  return 0;
}
