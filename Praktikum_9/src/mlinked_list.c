#include <stdio.h>

#include "linked_list.h"

List array2list(int* data, int len) {
  List res;
  CreateList(&res);

  for (int i = len - 1; i >= 0; i--) {
    insertFirst(&res, data[i]);
  }

  return res;
}

int main() {
  List haha;

  CreateList(&haha);
  displayList(haha);
  printf("\n");

  int dummy[] = {1, 2, 3, 4, 5, 6, 7, 8};
  List l1, l2;

  haha = array2list(dummy, 0);

  CreateList(&l1);
  CreateList(&l2);

  splitList(&l1, &l2, haha);
  printf("\n");

  displayList(haha);
  displayList(l1);
  displayList(l2);

  return 0;
}