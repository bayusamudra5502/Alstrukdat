#include <check.h>
#include <stdlib.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_sort) {
  ListDin l1, l2, l3, l4;

  CreateListDin(&l1, 1000);
  CreateListDin(&l2, 1000);
  CreateListDin(&l3, 1000);
  CreateListDin(&l4, 1000);

  l1.nEff = 1000;
  l2.nEff = 1;
  l3.nEff = 0;
  l4.nEff = 0;

  // Uji naik turun

  for (int i = 0; i < l1.capacity; i++) {
    l1.buffer[i] = rand();
  }

  sort(&l1, true);
  for (int i = 0; i < l1.capacity - 1; i++) {
    ck_assert_int_le(l1.buffer[i], l1.buffer[i + 1]);
  }

  sort(&l1, false);
  for (int i = 0; i < l1.capacity - 1; i++) {
    ck_assert_int_ge(l1.buffer[i], l1.buffer[i + 1]);
  }

  int arr2[] = {1};

  memcpy(l2.buffer, arr2, sizeof(arr2));

  sort(&l2, true);
  ck_assert_mem_eq(l2.buffer, arr2, sizeof(arr2));

  sort(&l2, false);
  ck_assert_mem_eq(l2.buffer, arr2, sizeof(arr2));

  // Cek kosong
  sort(&l3, true);
  ck_assert_mem_eq(l3.buffer, l4.buffer, sizeof(int) * l3.nEff);

  sort(&l4, false);
  ck_assert_mem_eq(l3.buffer, l4.buffer, sizeof(int) * l4.nEff);

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
  dealocate(&l4);
}
END_TEST

TCase* test_sort_listdin() {
  TCase* tc = tcase_create("Tes Sorting");
  tcase_add_test(tc, tes_sort);

  return tc;
}