/* File    : libpost.c
 * Tanggal : 7 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 * Topik   :
 *
 * Implementasi ABSTRACT DATA TYPE MOnolitic List
 *
 */

#include <stdio.h>

#include "boolean.h"
#include "listpos.h"

boolean ndml(ListPos l);
boolean naml(ListPos l);
boolean sml(ListPos l);

int main() {
  ListPos l;

  readList(&l);

  if (sml(l)) {
    printf("Static Monotonic List\n");
  } else if (naml(l)) {
    printf("Non-ascending Monotonic List\n");
  } else if (ndml(l)) {
    printf("Non-descending Monotonic List\n");
  } else {
    printf("Non-monotonic List\n");
  }

  return 0;
}

boolean ndml(ListPos l) {
  int len = length(l);
  int i;
  boolean res = true;

  for (i = 0; i < len - 1 && res; i++) {
    if (ELMT(l, i) > ELMT(l, i + 1)) {
      res = false;
    }
  }

  return res;
}

boolean naml(ListPos l) {
  int len = length(l);
  int i;
  boolean res = true;

  for (i = 0; i < len - 1 && res; i++) {
    if (ELMT(l, i) < ELMT(l, i + 1)) {
      res = false;
    }
  }

  return res;
}

boolean sml(ListPos l) {
  int len = length(l);
  int i;
  boolean res = true;

  for (i = 0; i < len - 1 && res; i++) {
    if (ELMT(l, i) != ELMT(l, i + 1)) {
      res = false;
    }
  }

  return res;
}