/* File: mtime.c */
/* Tanggal: 2 September 2021 */

// Nama : Bayu Samudra
// NIM : 13520128

#include <stdio.h>

#include "time.h"

int main() {
  int n;
  TIME max = MakeTIME(0, 0, 0), min = MakeTIME(23, 59, 59);

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("[%d]\n", i + 1);

    TIME t1, t2;
    BacaTIME(&t1);
    BacaTIME(&t2);

    if (TLT(t1, t2)) {
      printf("%ld\n", Durasi(t1, t2));

      if (TLT(t1, min)) {
        min = t1;
      }

      if (TGT(t2, max)) {
        max = t2;
      }
    } else {
      printf("%ld\n", Durasi(t2, t1));

      if (TLT(t2, min)) {
        min = t2;
      }

      if (TGT(t1, max)) {
        max = t1;
      }
    }
  }

  // TulisTIME(min);
  // printf("\n");
  // TulisTIME(max);
  // printf("\n");
  printf("%d:%d:%d\n", Hour(min), Minute(min), Second(min));
  printf("%d:%d:%d\n", Hour(max), Minute(max), Second(max));

  return 0;
}