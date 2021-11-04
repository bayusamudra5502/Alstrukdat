#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_concat_1) {
  List t[2];

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[] = {1, 2, 3, 4};

  t[0] = array2list(arr1, 8);
  t[1] = array2list(arr2, 4);

  List lc1 = concat(t[0], t[1]);

  int ans1[] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4};
  equalitiyCheck_l2a(lc1, ans1, 12);
  ck_assert_int_eq(length(lc1), 12);
}
END_TEST

START_TEST(tc_concat_2) {
  List t[2];

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[] = {1, 2, 3, 4};

  t[0] = array2list(arr1, 8);
  t[1] = array2list(arr2, 4);

  List lc1 = concat(t[1], t[0]);

  int ans1[] = {1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8};
  equalitiyCheck_l2a(lc1, ans1, 12);
  ck_assert_int_eq(length(lc1), 12);
}
END_TEST

START_TEST(tc_concat_3) {
  List t[2];

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[] = {};

  t[0] = array2list(arr1, 8);
  t[1] = array2list(arr2, 0);

  List lc1 = concat(t[0], t[1]);

  int ans1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  equalitiyCheck_l2a(lc1, ans1, 8);
  ck_assert_int_eq(length(lc1), 8);
}
END_TEST

START_TEST(tc_concat_4) {
  List t[2];

  int arr1[] = {1};
  int arr2[] = {};

  t[0] = array2list(arr1, 1);
  t[1] = array2list(arr2, 0);

  List lc1 = concat(t[1], t[0]);

  int ans1[] = {1};
  equalitiyCheck_l2a(lc1, ans1, 1);
  ck_assert_int_eq(length(lc1), 1);
}
END_TEST

START_TEST(tc_concat_5) {
  List t[2];

  int arr1[] = {};
  int arr2[] = {};

  t[0] = array2list(arr1, 0);
  t[1] = array2list(arr2, 0);

  List lc1 = concat(t[1], t[0]);

  ck_assert(isEmpty(t[0]));
  ck_assert(isEmpty(t[1]));

  int ans1[] = {};
  equalitiyCheck_l2a(lc1, ans1, 0);
  ck_assert_ptr_null(lc1);
  ck_assert_int_eq(length(lc1), 0);
}
END_TEST

START_TEST(tc_concat_6) {
  List t[2];

  int arr1[] = {1};
  int arr2[] = {2};

  t[0] = array2list(arr1, 1);
  t[1] = array2list(arr2, 1);

  List lc1 = concat(t[0], t[1]);

  int ans1[] = {1, 2};
  equalitiyCheck_l2a(lc1, ans1, 2);
  ck_assert_int_eq(length(lc1), 2);
}
END_TEST

TCase* test_concat() {
  TCase* tc = tcase_create("Tes Concat");
  tcase_add_test(tc, tc_concat_1);
  tcase_add_test(tc, tc_concat_2);
  tcase_add_test(tc, tc_concat_3);
  tcase_add_test(tc, tc_concat_4);
  tcase_add_test(tc, tc_concat_5);
  tcase_add_test(tc, tc_concat_6);

  return tc;
}