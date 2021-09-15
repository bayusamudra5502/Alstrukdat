#include <check.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_length) {
  ListDin l1, l2;
  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);

  ck_assert_int_eq(l1.capacity, 10);
  ck_assert_int_eq(l2.capacity, 10);
  ck_assert_int_eq(l1.nEff, 0);
  ck_assert_int_eq(l2.nEff, 0);

  l1.nEff = 10;
  l2.nEff = 90;

  dealocate(&l1);
  dealocate(&l2);

  ck_assert_int_eq(l1.capacity, 0);
  ck_assert_int_eq(l2.capacity, 0);
  ck_assert_int_eq(l1.nEff, 0);
  ck_assert_int_eq(l2.nEff, 0);
}
END_TEST

TCase* test_constructor_listdin() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tes_length);

  return tc;
}