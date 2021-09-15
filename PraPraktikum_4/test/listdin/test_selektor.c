#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_length) {
  ListDin l1, l2;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);

  int arr1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, arr1, &l1);

  ck_assert_int_eq(length(l1), 6);
  ck_assert_int_eq(length(l2), 0);

  dealocate(&l1);
  dealocate(&l2);
}
END_TEST

START_TEST(tes_idx) {
  ListDin l1;

  CreateListDin(&l1, 20);
  int tes1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, tes1, &l1);

  ck_assert(isIdxValid(l1, 10));
  ck_assert(isIdxValid(l1, 1));
  ck_assert(isIdxValid(l1, 0));

  ck_assert(!isIdxValid(l1, l1.capacity));
  ck_assert(!isIdxValid(l1, -1));

  ck_assert(!isIdxEff(l1, 10));
  ck_assert(!isIdxEff(l1, 6));
  ck_assert(isIdxEff(l1, 1));
  ck_assert(isIdxEff(l1, 0));

  ck_assert(!isIdxEff(l1, l1.capacity));
  ck_assert(!isIdxEff(l1, -1));

  dealocate(&l1);
}
END_TEST

START_TEST(tes_last_idx) {
  ListDin l1;

  CreateListDin(&l1, 20);
  int tes1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, tes1, &l1);

  ck_assert_int_eq(getLastIdx(l1), 5);

  dealocate(&l1);
}

TCase* test_selektor_listdin() {
  TCase* tc = tcase_create("Tes Selektor");
  tcase_add_test(tc, tes_length);
  tcase_add_test(tc, tes_idx);
  tcase_add_test(tc, tes_last_idx);

  return tc;
}