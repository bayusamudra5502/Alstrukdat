#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_insertf_1) {
  List test;

  CreateList(&test);

  insertFirst(&test, 2);
  insertFirst(&test, 1);
  insertFirst(&test, 0);

  int res[] = {0, 1, 2};
  Address p = FIRST(test);

  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(INFO(p), res[i]);
    p = NEXT(p);
  }
}
END_TEST

START_TEST(tc_insertf_2) {
  List test;
  int tc[] = {1, 2, 3, 4, 5};

  CreateList(&test);

  insertFirst(&test, 5);
  insertFirst(&test, 4);
  insertFirst(&test, 3);
  insertFirst(&test, 2);
  insertFirst(&test, 1);

  equalitiyCheck_l2a(test, tc, 5);
}
END_TEST

TCase* test_insertf() {
  TCase* tc = tcase_create("Tes Insert First");
  tcase_add_test(tc, tc_insertf_1);
  tcase_add_test(tc, tc_insertf_2);

  return tc;
}