/* File: main_time.c */
/* Tanggal: 31 Agustus 2021 */
// Driver ADT Jam

// Nama : Bayu Samudra
// NIM : 13520128

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