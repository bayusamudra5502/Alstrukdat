#include <check.h>
#include <stdlib.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_sort) {
  ListPos l1, l2, l3, l4;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  // Uji naik turun
  for (int i = 0; i < CAPACITY; i++) {
    l1.contents[i] = rand();
  }

  sort(&l1, true);
  for (int i = 0; i < CAPACITY - 1; i++) {
    ck_assert_int_le(l1.contents[i], l1.contents[i + 1]);
  }

  sort(&l1, false);
  for (int i = 0; i < CAPACITY - 1; i++) {
    ck_assert_int_ge(l1.contents[i], l1.contents[i + 1]);
  }

  int arr2[] = {1};

  memcpy(l2.contents, arr2, sizeof(arr2));

  sort(&l2, true);
  ck_assert_mem_eq(l2.contents, arr2, sizeof(arr2));

  sort(&l2, false);
  ck_assert_mem_eq(l2.contents, arr2, sizeof(arr2));

  // Cek kosong
  sort(&l3, true);
  ck_assert_mem_eq(l3.contents, l4.contents, sizeof(int) * CAPACITY);

  sort(&l4, false);
  ck_assert_mem_eq(l3.contents, l4.contents, sizeof(int) * CAPACITY);
}
END_TEST

TCase* test_sort_listpos() {
  TCase* tc = tcase_create("Tes Sorting");
  tcase_add_test(tc, tes_sort);

  return tc;
}