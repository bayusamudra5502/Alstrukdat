#include <check.h>
#include <stdlib.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_copy) {
  ListDin l1, l2;
  CreateListDin(&l1, 10);

  int arr[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, arr, &l1);

  copyList(l1, &l2);

  ck_assert(isAllEqHelper(l1, l2));

  dealocate(&l1);
  dealocate(&l2);
}
END_TEST

START_TEST(tes_all_even) {
  ListDin l1, l2, l3, l4;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);
  CreateListDin(&l3, 10);
  CreateListDin(&l4, 10);

  int arr1[] = {2, 4, 6, 8, 10, 0};
  int arr2[] = {2};
  int arr3[] = {1, 2, 3};

  copyFromArrayHelper(sizeof(arr1) / sizeof(int), arr1, &l1);
  copyFromArrayHelper(sizeof(arr2) / sizeof(int), arr2, &l2);
  copyFromArrayHelper(sizeof(arr3) / sizeof(int), arr3, &l3);

  ck_assert(isAllEven(l1));
  ck_assert(isAllEven(l2));
  ck_assert(!isAllEven(l3));
  ck_assert(isAllEven(l4));

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
  dealocate(&l4);
}
END_TEST

TCase* test_op_listdin() {
  TCase* tc = tcase_create("Tes Operasi");
  tcase_add_test(tc, tes_copy);
  tcase_add_test(tc, tes_all_even);

  return tc;
}