#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_delete_1) {
  List test;

  CreateList(&test);
  int tc[] = {1, 2, 3, 4, 5};

  test = array2list(tc, 5);

  int val;

  deleteFirst(&test, &val);
  ck_assert_int_eq(val, 1);
  ck_assert_int_eq(length(test), 4);

  deleteFirst(&test, &val);
  ck_assert_int_eq(val, 2);
  ck_assert_int_eq(length(test), 3);

  deleteFirst(&test, &val);
  ck_assert_int_eq(val, 3);
  ck_assert_int_eq(length(test), 2);

  deleteFirst(&test, &val);
  ck_assert_int_eq(val, 4);
  ck_assert_int_eq(length(test), 1);

  deleteFirst(&test, &val);
  ck_assert_int_eq(val, 5);
  ck_assert_int_eq(length(test), 0);

  ck_assert(isEmpty(test));
}
END_TEST

START_TEST(tc_delete_2) {
  List test;

  CreateList(&test);
  int tc[] = {1, 2, 3, 4, 5};

  test = array2list(tc, 5);

  int val;

  deleteLast(&test, &val);
  ck_assert_int_eq(val, 5);
  ck_assert_int_eq(length(test), 4);

  deleteLast(&test, &val);
  ck_assert_int_eq(val, 4);
  ck_assert_int_eq(length(test), 3);

  deleteLast(&test, &val);
  ck_assert_int_eq(val, 3);
  ck_assert_int_eq(length(test), 2);

  deleteLast(&test, &val);
  ck_assert_int_eq(val, 2);
  ck_assert_int_eq(length(test), 1);

  deleteLast(&test, &val);
  ck_assert_int_eq(val, 1);
  ck_assert_int_eq(length(test), 0);

  ck_assert(isEmpty(test));
}
END_TEST

START_TEST(tc_delete_3) {
  List test;

  CreateList(&test);
  int tc[] = {1, 2, 3, 4, 5};

  test = array2list(tc, 5);

  int val;

  deleteAt(&test, 0, &val);
  ck_assert_int_eq(val, 1);
  ck_assert_int_eq(length(test), 4);

  deleteAt(&test, 3, &val);
  ck_assert_int_eq(val, 5);
  ck_assert_int_eq(length(test), 3);

  deleteAt(&test, 1, &val);
  ck_assert_int_eq(val, 3);
  ck_assert_int_eq(length(test), 2);

  deleteAt(&test, 1, &val);
  ck_assert_int_eq(val, 4);
  ck_assert_int_eq(length(test), 1);

  deleteAt(&test, 0, &val);
  ck_assert_int_eq(val, 2);
  ck_assert_int_eq(length(test), 0);
}
END_TEST

TCase* test_delete() {
  TCase* tc = tcase_create("Tes Delete");
  tcase_add_test(tc, tc_delete_1);
  tcase_add_test(tc, tc_delete_2);
  tcase_add_test(tc, tc_delete_3);

  return tc;
}