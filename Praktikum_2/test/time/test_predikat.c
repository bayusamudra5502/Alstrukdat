#include <check.h>

#include "../../src/time.h"
#include "test.h"

START_TEST(konversi) {
  ck_assert(IsTIMEValid(12, 0, 0));
  ck_assert(IsTIMEValid(0, 0, 0));
  ck_assert(IsTIMEValid(23, 59, 59));
  ck_assert(IsTIMEValid(3, 58, 12));

  ck_assert(!IsTIMEValid(24, 0, 60));
  ck_assert(!IsTIMEValid(-1, 0, 0));
  ck_assert(!IsTIMEValid(0, -1, 0));
  ck_assert(!IsTIMEValid(0, 0, -1));
  ck_assert(!IsTIMEValid(0, 90, 0));
}
END_TEST

TCase* test_predikat() {
  TCase* tc = tcase_create("Tes Predikat");
  tcase_add_test(tc, konversi);

  return tc;
}