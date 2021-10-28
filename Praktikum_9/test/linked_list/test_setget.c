#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_setget_1) {
  List test;

  int tc[] = {1, 2, 3, 4, 5};
  test = array2list(tc, 5);

  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(tc[i], getElmt(test, i));
  }
}
END_TEST

START_TEST(tc_setget_2) {
  List test;

  int tc[] = {1, 2, 3, 4, 5};
  test = array2list(tc, 5);

  for (int i = 0; i < 5; i++) {
    setElmt(&test, i, i - 2);
  }

  int actual[5];
  int ans[] = {-2, -1, 0, 1, 2};

  list2array(actual, test, 5);

  ck_assert_mem_eq(ans, actual, sizeof(int) * 5);
}
END_TEST

TCase* test_setget() {
  TCase* tc = tcase_create("Tes Setter Getter");
  tcase_add_test(tc, tc_setget_1);
  tcase_add_test(tc, tc_setget_2);

  return tc;
}
