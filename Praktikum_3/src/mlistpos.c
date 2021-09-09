/* File    : libpost.c
 * Tanggal : 7 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 * Topik   :
 *
 * Praktikum ABSTRACT DATA TYPE LIST POSITIF
 *
 */

#include <stdio.h>
#include <string.h>

#include "listpos.h"

ElType median(ListPos l);

int main() {
  // FUngsi Utama
  ListPos l;

  // Baca List
  readList(&l);
  displayList(l);
  printf("\n");

  int val, idx;
  scanf("%d", &val);

  idx = indexOf(l, val);

  if (idx != IDX_UNDEF) {
    int max, min;

    printf("%d\n", idx);
    extremes(l, &max, &min);

    double med = median(l);

    if (val == max) {
      printf("maksimum\n");
    }

    if (val == min) {
      printf("minimum\n");
    }

    if (val == med) {
      printf("median\n");
    }

  } else {
    printf("%d tidak ada\n", val);
  }

  return 0;
}

ElType median(ListPos l) {
  sort(&l, true);

  int len = length(l);
  return len % 2 == 0 ? ELMT(l, len / 2 - 1) : ELMT(l, len / 2);
}