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

  int dummy[] = {9, 10, 0, -1, 4, 5, 8};

  haha = array2list(dummy, 7);
  displayList(haha);
  printf("\n");

  int kucing[] = {1};
  List belalang = array2list(kucing, 1);
  displayList(belalang);
  printf("\n");

  return 0;
}