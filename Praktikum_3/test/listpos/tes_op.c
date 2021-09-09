#include <check.h>
#include <stdlib.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_eq) {
  ListPos l1, l2, l3;

  CreateListPos(&l1);
  CreateListPos(&l2);

  int arr3[] = {1, 2, 3};

  for (int i = 0; i < CAPACITY; i++) {
    l1.contents[i] = rand();
    l2.contents[i] = l1.contents[i];
  }

  l2.contents[CAPACITY - 1] = l2.contents == 0 ? 1 : 0;

  memcpy(l3.contents, arr3, sizeof(arr3));

  ck_assert(isListEqual(l1, l1));
  ck_assert(!isListEqual(l1, l2));
  ck_assert(!isListEqual(l1, l3));
}
END_TEST

START_TEST(tes_all_even) {
  ListPos l1, l2, l3, l4;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  int arr1[] = {2, 4, 6, 8, 10, 0};
  int arr2[] = {2};
  int arr3[] = {1, 2, 3};

  memcpy(l1.contents, arr1, sizeof(arr1));
  memcpy(l2.contents, arr2, sizeof(arr2));
  memcpy(l3.contents, arr3, sizeof(arr3));

  ck_assert(isAllEven(l1));
  ck_assert(isAllEven(l2));
  ck_assert(!isAllEven(l3));
  ck_assert(isAllEven(l4));
}
END_TEST

TCase* test_op_listpos() {
  TCase* tc = tcase_create("Tes Kesamaan");
  tcase_add_test(tc, tes_eq);
  tcase_add_test(tc, tes_all_even);

  return tc;
}