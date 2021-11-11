#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_setget_1) {
  List test;

  CreateList(&test);

  ck_assert_ptr_null(test);
  ck_assert(isEmpty(test));
}
END_TEST

TCase* test_constructor() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tc_setget_1);

  return tc;
}
