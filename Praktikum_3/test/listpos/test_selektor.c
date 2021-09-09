#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_length) {
  ListPos l1, l2, l3, l4;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  int tes2[] = {1, 2, 3, VAL_UNDEF, 5, 6};

  memcpy(l1.contents, tes1, sizeof(tes1));
  memcpy(l2.contents, tes2, sizeof(tes2));

  for (int i = 0; i < CAPACITY; i++) {
    l4.contents[i] = rand();
  }

  ck_assert_int_eq(length(l1), 6);
  ck_assert_int_eq(length(l2), 3);
  ck_assert_int_eq(length(l3), 0);
  ck_assert_int_eq(length(l4), CAPACITY);
}
END_TEST

START_TEST(tes_idx) {
  ListPos l1;

  CreateListPos(&l1);
  int tes1[] = {1, 2, 3, 4, 5, 6};

  memcpy(l1.contents, tes1, 6);

  ck_assert(isIdxValid(l1, 10));
  ck_assert(isIdxValid(l1, 1));
  ck_assert(isIdxValid(l1, 0));

  ck_assert(!isIdxValid(l1, CAPACITY));
  ck_assert(!isIdxValid(l1, -1));

  ck_assert(!isIdxEff(l1, 10));
  ck_assert(!isIdxEff(l1, 6));
  ck_assert(isIdxEff(l1, 1));
  ck_assert(isIdxEff(l1, 0));

  ck_assert(!isIdxEff(l1, CAPACITY));
  ck_assert(!isIdxEff(l1, -1));
}
END_TEST

TCase* test_selektor_listpos() {
  TCase* tc = tcase_create("Tes Selektor");
  tcase_add_test(tc, tes_length);
  tcase_add_test(tc, tes_idx);

  return tc;
}