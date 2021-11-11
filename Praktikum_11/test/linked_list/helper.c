#include <check.h>

#include "../../src/linked_list.h"
#include "test.h"

List array2list(int* data, int len) {
  List res;
  CreateList(&res);

  for (int i = len - 1; i >= 0; i--) {
    insertFirst(&res, data[i]);
  }

  return res;
}

void list2array(int* result, List data, int len) {
  Address p = FIRST(data);

  for (int i = 0; i < len; i++) {
    result[i] = INFO(p);
    p = NEXT(p);
  }
}

void equalitiyCheck_l2a(List l, int* data, int len) {
  int llen = length(l);

  ck_assert_int_eq(len, llen);

  if (len == llen) {
    int larr[llen];

    list2array(larr, l, llen);
    ck_assert_mem_eq(larr, data, llen * sizeof(int));
  }
}