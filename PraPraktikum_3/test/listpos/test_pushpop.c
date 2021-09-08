#include <check.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_push) {
  ListPos l, lans;
  CreateListPos(&l);
  CreateListPos(&lans);

  insertLast(&l, 12);
  insertLast(&l, 10);
  insertLast(&l, 30);

  lans.contents[0] = 12;
  lans.contents[1] = 10;
  lans.contents[2] = 30;

  ck_assert(isListEqual(l, lans));
}
END_TEST

START_TEST(tes_pop) {
  ListPos l;
  CreateListPos(&l);

  insertLast(&l, 12);
  insertLast(&l, 10);
  insertLast(&l, 30);

  int val;
  deleteLast(&l, &val);
  ck_assert_int_eq(ELMT(l, 0), 12);
  ck_assert_int_eq(ELMT(l, 1), 10);
  ck_assert_int_eq(ELMT(l, 2), VAL_UNDEF);
  ck_assert_int_eq(val, 30);

  deleteLast(&l, &val);
  ck_assert_int_eq(val, 10);

  deleteLast(&l, &val);
  ck_assert_int_eq(val, 12);
}
END_TEST

TCase* test_pushpop_listpos() {
  TCase* tc = tcase_create("Tes Insert Delete Element");
  tcase_add_test(tc, tes_push);
  tcase_add_test(tc, tes_pop);

  return tc;
}