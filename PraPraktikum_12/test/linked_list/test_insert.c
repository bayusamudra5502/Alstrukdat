#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_insert_1) {
  List test;

  int ans[] = {3, 6, 9, 2, 1, 9, 10};
  CreateList(&test);

  insertLast(&test, 3);
  insertLast(&test, 6);
  insertLast(&test, 9);
  insertLast(&test, 2);
  insertLast(&test, 1);
  insertLast(&test, 9);
  insertLast(&test, 10);

  ck_assert_int_eq(length(test), 7);

  int tc[7];
  list2array(tc, test, 7);

  ck_assert_mem_eq(ans, tc, sizeof(int) * 7);
}
END_TEST

START_TEST(tc_insert_2) {
  List test;

  int tc[] = {3, 6, 9, 2, 1, 9, 10};
  test = array2list(tc, 7);

  insertAt(&test, 99, 3);
  insertAt(&test, 20, 2);
  insertAt(&test, 3, 7);

  int ans[] = {3, 6, 20, 9, 99, 2, 1, 3, 9, 10};

  int actual[10];

  ck_assert_int_eq(length(test), 10);
  list2array(actual, test, 10);

  ck_assert_mem_eq(ans, actual, sizeof(int) * 10);
}
END_TEST

START_TEST(tc_insert_3) {
  List test;

  CreateList(&test);

  insertFirst(&test, 1);
  insertAt(&test, 2, 0);
  insertAt(&test, 3, 1);
  insertAt(&test, 4, 0);
  insertAt(&test, 5, 4);

  int actual[5];
  int ans[] = {4, 2, 3, 1, 5};

  list2array(actual, test, 5);

  ck_assert_int_eq(length(test), 5);

  ck_assert_mem_eq(ans, actual, sizeof(int) * 5);
}
END_TEST

TCase* test_insert() {
  TCase* tc = tcase_create("Tes Insert");
  tcase_add_test(tc, tc_insert_1);
  tcase_add_test(tc, tc_insert_2);
  tcase_add_test(tc, tc_insert_3);

  return tc;
}