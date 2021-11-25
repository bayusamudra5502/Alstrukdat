#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_idxo_1) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 11};

  List l = array2list(arr, 13);

  ck_assert_int_eq(indexOf(l, 1), 0);
  ck_assert_int_eq(indexOf(l, 6), 5);
  ck_assert_int_eq(indexOf(l, 10), 9);
  ck_assert_int_eq(indexOf(l, 13), IDX_UNDEF);
  ck_assert_int_eq(indexOf(l, -9), IDX_UNDEF);
  ck_assert_int_eq(indexOf(l, 11), 10);
}
END_TEST

TCase* test_idxo() {
  TCase* tc = tcase_create("Tes Index Of");
  tcase_add_test(tc, tc_idxo_1);

  return tc;
}