#include <check.h>
#include <stdlib.h>

#include "../../src/linked_list.h"
#include "test.h"

START_TEST(tc_helper_1) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  List l = array2list(arr, 10);

  Address p = FIRST(l);
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(INFO(p), arr[i]);
    p = NEXT(p);
  }

  int conv[10];
  list2array(conv, l, 10);
  ck_assert_mem_eq(conv, arr, 10);

  equalitiyCheck_l2a(l, arr, 10);
}
END_TEST

TCase* test_helper() {
  TCase* tc = tcase_create("Tes Helper");
  tcase_add_test(tc, tc_helper_1);

  return tc;
}