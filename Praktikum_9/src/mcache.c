#include <stdio.h>

#include "list_linked.h"

List buildCache(int n) {
  List l;
  CreateList(&l);

  for (int i = 1; i <= n; i++) {
    insertLast(&l, i);
  }

  return l;
}

void swap(List* l, int idx) {
  int val;
  deleteAt(l, idx, &val);
  insertFirst(l, val);
}

int main() {
  int n, op;

  scanf("%d", &n);
  scanf("%d", &op);
  List cache = buildCache(n);

  for (int i = 0; i < op; i++) {
    int val;
    scanf("%d", &val);

    int idx = indexOf(cache, val);

    if (idx == IDX_UNDEF) {
      int tmp;
      printf("miss ");
      deleteLast(&cache, &tmp);
      insertFirst(&cache, val);
    } else {
      printf("hit ");
      swap(&cache, idx);
    }

    displayList(cache);
    printf("\n");
  }

  return 0;
}