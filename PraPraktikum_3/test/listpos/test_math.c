#include <check.h>
#include <string.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(test_math) {
  ListPos l1, l2;

  CreateListPos(&l1);
  CreateListPos(&l2);

  int arr1[] = {1, 2, 3, 4, 5, 6};
  int arr2[] = {2, 5, 1, 2, 1, 0};
  int arp[] = {3, 7, 4, 6, 6, 6};
  int arm[] = {-1, -3, 2, 2, 4, 6};

  memcpy(l1.contents, arr1, sizeof(arr1));
  memcpy(l2.contents, arr2, sizeof(arr2));

  ListPos r1 = plusMinusTab(l1, l2, true);
  ListPos r2 = plusMinusTab(l1, l2, false);

  ck_assert_mem_eq(r1.contents, arp, 6);
  ck_assert_mem_eq(r2.contents, arm, 6);
}
END_TEST

START_TEST(test_ekstrim) {
  ListPos l1, l2;

  CreateListPos(&l1);
  CreateListPos(&l2);

  int arr1[] = {8, 2, 9, 1, 5, 6, 10, 8, 3, 10, 1, 2};
  int arr2[] = {9};

  memcpy(l1.contents, arr1, sizeof(arr1));
  memcpy(l2.contents, arr2, sizeof(arr2));

  int min, max;
  extremes(l1, &max, &min);
  ck_assert_int_eq(min, 1);
  ck_assert_int_eq(max, 10);

  extremes(l2, &max, &min);
  ck_assert_int_eq(min, 9);
  ck_assert_int_eq(max, 9);
}
END_TEST

TCase* test_math_listpos() {
  TCase* tc = tcase_create("Tes Matematika");
  tcase_add_test(tc, test_math);
  tcase_add_test(tc, test_ekstrim);

  return tc;
}