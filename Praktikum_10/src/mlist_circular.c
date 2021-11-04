#include "list_circular.h"
#include "stdio.h"

int main() {
  List l;
  CreateList(&l);

  printf("%d\n", isEmpty(l));
  insertLast(&l, 1);
  insertLast(&l, 3);
  insertFirst(&l, 6);
  insertFirst(&l, 2);
  insertLast(&l, 4);
  insertLast(&l, 5);

  displayList(l);
  printf("\n");

  Address p = search(l, 5);
  Address p2 = search(l, 2);
  Address p3 = search(l, 3);

  printf("%d %d %d\n", INFO(p), INFO(p2), INFO(p3));
  printf("%d %d %d %d\n", addrSearch(l, NULL), addrSearch(l, p),
         addrSearch(l, p3), addrSearch(l, (Address)0x1234567));

  displayList(l);
  printf("\n");

  int val;
  deleteFirst(&l, &val);
  printf("%d ", val);
  deleteLast(&l, &val);
  deleteFirst(&l, &val);
  deleteFirst(&l, &val);
  deleteFirst(&l, &val);
  deleteFirst(&l, &val);
  printf("%d\n", val);

  displayList(l);
  printf("\n");
}