#include <check.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_pencarian) {
  ListPos l1, l2, l3, l4, l5;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);
  CreateListPos(&l5);

  int arr1[] = {2, 4, 6, 8, 10, 0, 8, 12};
  int arr2[] = {2};
  int arr3[] = {1, 2, 3};
  int arr4[] = {1, 2, VAL_UNDEF, 3, 4, 5};

  memcpy(l1.contents, arr1, sizeof(arr1));
  memcpy(l2.contents, arr2, sizeof(arr2));
  memcpy(l3.contents, arr3, sizeof(arr3));
  memcpy(l4.contents, arr4, sizeof(arr4));

  ck_assert_int_eq(indexOf(l1, 0), 5);
  ck_assert_int_eq(indexOf(l1, 8), 3);

  ck_assert_int_eq(indexOf(l2, 2), 0);

  ck_assert_int_eq(indexOf(l3, 3), 2);
  ck_assert_int_eq(indexOf(l3, 5), IDX_UNDEF);

  ck_assert_int_eq(indexOf(l4, 3), IDX_UNDEF);
  ck_assert_int_eq(indexOf(l5, 3), IDX_UNDEF);
}
END_TEST

TCase* test_cari_listpos() {
  TCase* tc = tcase_create("Tes Cari Elemen");
  tcase_add_test(tc, tes_pencarian);

  return tc;
}