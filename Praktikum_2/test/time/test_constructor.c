#include <check.h>

#include "../../src/time.h"
#include "test.h"

START_TEST(konversi) {
  TIME t1 = MakeTIME(13, 11, 10);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = MakeTIME(23, 59, 59);

  // Case 1
  ck_assert_int_eq(Hour(t1), 13);
  ck_assert_int_eq(Minute(t1), 11);
  ck_assert_int_eq(Second(t1), 10);

  // Case 2
  ck_assert_int_eq(Hour(t2), 0);
  ck_assert_int_eq(Minute(t2), 0);
  ck_assert_int_eq(Second(t2), 0);

  // Case 3
  ck_assert_int_eq(Hour(t3), 23);
  ck_assert_int_eq(Minute(t3), 59);
  ck_assert_int_eq(Second(t3), 59);
}
END_TEST

TCase* test_constructor() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, konversi);

  return tc;
}