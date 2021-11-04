/**
 * Nama : Bayu Samudra
 * NIM : 13520128
 *
 * Double Linked List
 */

#include <stdio.h>

#include "list_dp.h"
int main() {
  List l;

  CreateList(&l);
  // displayList(l);
  // displayListBackwards(l);

  // insertLast(&l, 2);
  // insertFirst(&l, 3);
  // insertFirst(&l, 4);

  // displayList(l);
  // printf("\n");

  // displayListBackwards(l);
  // printf("\n");

  // Address a = search(l, 3);
  // insertAfter(&l, allocate(10), a);

  // Address b = search(l, 2);
  // insertAfter(&l, allocate(20), b);

  // printf("%d %d\n", INFO(a), INFO(b));

  // displayList(l);
  // printf("\n");

  // displayListBackwards(l);
  // printf("\n");

  // Address HAHA;
  // deleteAfter(&l, &HAHA, b);

  // int val;
  // deleteLast(&l, &val);
  // printf("DEL : %d\n", val);
  // deleteFirst(&l, &val);
  // printf("DEL : %d\n", val);
  // deleteFirst(&l, &val);
  // printf("DEL : %d\n", val);
  // deleteFirst(&l, &val);
  // printf("DEL : %d\n", val);

  insertFirst(&l, 2);
  insertFirst(&l, 2);
  insertFirst(&l, 3);
  insertFirst(&l, 4);

  displayList(l);
  printf("\n");

  displayListBackwards(l);
  printf("\n");
}