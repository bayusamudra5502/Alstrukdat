/**
 * @file backspace.c
 * Nama: Bayu Samudra
 * NIM : 13520128
 *
 * @version 0.1
 * @date 2021-11-11
 *
 * Backspace
 *
 */
#include <stdio.h>

#include "stack_linked.h"

int main() {
  int m, n;
  Stack k1, k2;

  CreateStack(&k1);
  CreateStack(&k2);

  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    int s;
    scanf("%d", &s);

    if (!s && !isEmpty(k1)) {
      int x;
      pop(&k1, &x);
    } else if (s) {
      push(&k1, s);
    }
  }

  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);

    if (!s && !isEmpty(k2)) {
      int x;
      pop(&k2, &x);
    } else if (s) {
      push(&k2, s);
    }
  }

  // Cek kesamaan
  boolean isEq = true;
  while (!isEmpty(k1) && !isEmpty(k2) && isEq) {
    int val1, val2;

    pop(&k1, &val1);
    pop(&k2, &val2);

    if (val1 != val2) {
      isEq = false;
    }
  }

  if (isEq && isEmpty(k1) && isEmpty(k2)) {
    printf("Sama\n");
  } else {
    printf("Tidak sama\n");
  }

  return 0;
}