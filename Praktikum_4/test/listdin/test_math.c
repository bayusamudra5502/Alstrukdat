#include <check.h>
#include <string.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(test_math) {
  ListDin l1, l2;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);

  int arr1[] = {1, 2, 3, 4, 5, 6};
  int arr2[] = {2, 5, 1, 2, 1, 0};
  int arp[] = {3, 7, 4, 6, 6, 6};
  int arm[] = {-1, -3, 2, 2, 4, 6};

  copyFromArrayHelper(6, arr1, &l1);
  copyFromArrayHelper(6, arr2, &l2);

  ListDin r1 = plusMinusList(l1, l2, true);
  ListDin r2 = plusMinusList(l1, l2, false);

  ck_assert_mem_eq(r1.buffer, arp, 6);
  ck_assert_mem_eq(r2.buffer, arm, 6);
  dealocate(&l1);
  dealocate(&l2);
}
END_TEST

START_TEST(test_ekstrim) {
  ListDin l1, l2, l3;

  CreateListDin(&l1, 20);
  CreateListDin(&l2, 20);
  CreateListDin(&l3, 20);

  int arr1[] = {8, 2, 9, 1, 5, 6, 10, 8, 3, 10, 1, 2};
  int arr2[] = {9};
  int arr3[] = {1, 1, 1, 1};

  copyFromArrayHelper(12, arr1, &l1);
  copyFromArrayHelper(1, arr2, &l2);
  copyFromArrayHelper(4, arr3, &l3);

  int min, max;
  extremes(l1, &max, &min);
  ck_assert_int_eq(min, 1);
  ck_assert_int_eq(max, 10);

  extremes(l2, &max, &min);
  ck_assert_int_eq(min, 9);
  ck_assert_int_eq(max, 9);

  extremes(l3, &max, &min);
  ck_assert_int_eq(min, 1);
  ck_assert_int_eq(max, 1);

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
}
END_TEST

START_TEST(tes_jumlah_semua) {
  ListDin l1, l2, l3;
  CreateListDin(&l1, 20);
  CreateListDin(&l2, 20);
  CreateListDin(&l3, 20);

  int arr1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, arr1, &l1);
  copyFromArrayHelper(6, arr1, &l2);

  l2.nEff = 3;

  ck_assert_int_eq(sumList(l1), 21);
  ck_assert_int_eq(sumList(l2), 6);
  ck_assert_int_eq(sumList(l3), 0);

  dealocate(&l2);
  ck_assert_int_eq(sumList(l2), 0);

  dealocate(&l1);
  dealocate(&l3);
}

START_TEST(tes_count) {
  ListDin l1, l2, l3;
  CreateListDin(&l1, 20);
  CreateListDin(&l2, 20);
  CreateListDin(&l3, 20);

  int arr1[] = {1, 2, 3, 1, 3, 1, 1, 4, 5, 6};

  copyFromArrayHelper(10, arr1, &l1);
  copyFromArrayHelper(10, arr1, &l2);

  l2.nEff = 3;

  ck_assert_int_eq(countVal(l1, 1), 4);
  ck_assert_int_eq(countVal(l1, 0), 0);
  ck_assert_int_eq(countVal(l1, 10), 0);

  ck_assert_int_eq(countVal(l2, 1), 1);
  ck_assert_int_eq(countVal(l2, 0), 0);
  ck_assert_int_eq(countVal(l2, 4), 0);

  ck_assert_int_eq(countVal(l3, 1), 0);
  ck_assert_int_eq(countVal(l3, 0), 0);
  ck_assert_int_eq(countVal(l3, 4), 0);

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
}

TCase* test_math_listdin() {
  TCase* tc = tcase_create("Tes Matematika");
  tcase_add_test(tc, test_math);
  tcase_add_test(tc, test_ekstrim);
  tcase_add_test(tc, tes_jumlah_semua);
  tcase_add_test(tc, tes_count);

  return tc;
}