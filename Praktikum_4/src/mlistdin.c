/* File    : mlistdin.c
 * Tanggal : 16 September 2021
 * Nama	   : Bayu Samudra
 * NIM     : 13520128
 * Topik   :
 *
 * Implementasi ABSTRACT DATA TYPE LIST POSITIF
 *
 */

#include <stdio.h>
#include <string.h>

#include "listdin.h"

void printListHelper(ListDin l);

int main() {
  ListDin l;
  int c, q;

  scanf("%d", &c);
  CreateListDin(&l, c);

  readList(&l);

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int op, data;

    scanf("%d", &op);

    switch (op) {
      case 1:
        scanf("%d", &data);
        if (isFull(l)) {
          printf("list sudah penuh\n");
        } else {
          insertLast(&l, data);
          printListHelper(l);
        }

        break;
      case 2:
        scanf("%d", &data);
        growList(&l, data);
        printListHelper(l);
        break;
      case 3:
        scanf("%d", &data);
        if (CAPACITY(l) - data < 0) {
          printf("list terlalu kecil\n");
        } else {
          shrinkList(&l, data);
          printListHelper(l);
        }

        break;
      case 4:
        compactList(&l);
        printListHelper(l);
        break;
    }
  }

  return 0;
}

void printListHelper(ListDin l) {
  printf("%d ", CAPACITY(l));
  displayList(l);
  printf("\n");
}