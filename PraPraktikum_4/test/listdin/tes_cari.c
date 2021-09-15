#include <check.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_pencarian) {
  ListDin l1, l2, l3, l4, l5;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);
  CreateListDin(&l3, 10);
  CreateListDin(&l4, 10);
  CreateListDin(&l5, 10);

  int arr1[] = {2, 4, 6, 8, 10, 0, 8, 12};
  int arr2[] = {2};
  int arr3[] = {1, 2, 3};
  int arr4[] = {1, 2, 9, 4, 4, 5};

  copyFromArrayHelper(8, arr1, &l1);
  copyFromArrayHelper(1, arr2, &l2);
  copyFromArrayHelper(3, arr3, &l3);
  copyFromArrayHelper(4, arr4, &l4);

  ck_assert_int_eq(indexOf(l1, 0), 5);
  ck_assert_int_eq(indexOf(l1, 8), 3);

  ck_assert_int_eq(indexOf(l2, 2), 0);

  ck_assert_int_eq(indexOf(l3, 3), 2);
  ck_assert_int_eq(indexOf(l3, 5), IDX_UNDEF);

  ck_assert_int_eq(indexOf(l4, 3), IDX_UNDEF);
  ck_assert_int_eq(indexOf(l5, 3), IDX_UNDEF);
}
END_TEST

TCase* test_cari_listdin() {
  TCase* tc = tcase_create("Tes Cari Elemen");
  tcase_add_test(tc, tes_pencarian);

  return tc;
}