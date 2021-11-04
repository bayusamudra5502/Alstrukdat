#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_length) {
  List t[3];

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[] = {1, 2, 3, 4};
  int arr3[] = {};

  t[0] = array2list(arr1, 8);
  t[1] = array2list(arr2, 4);
  t[2] = array2list(arr3, 0);

  ck_assert_int_eq(length(t[0]), 8);
  ck_assert_int_eq(length(t[1]), 4);
  ck_assert_int_eq(length(t[2]), 0);
}
END_TEST

START_TEST(tc_length_2) {
  List t;

  CreateList(&t);

  ck_assert_int_eq(length(t), 0);
}
END_TEST

TCase* test_length() {
  TCase* tc = tcase_create("Tes Length");
  tcase_add_test(tc, tc_length);
  tcase_add_test(tc, tc_length_2);

  return tc;
}