#include <check.h>

#include "../../src/point.h"
#include "test.h"

START_TEST(konversi) {
  POINT p1, p2;
  p1 = MakePOINT(2, 5);
  p2 = MakePOINT(3.143, 8.9233);

  ck_assert_float_eq(Absis(p1), 2.0);
  ck_assert_float_eq(Ordinat(p1), 5.0);

  ck_assert_float_eq(Absis(p2), 3.143);
  ck_assert_float_eq(Ordinat(p2), 8.9233);
}
END_TEST

TCase* test_constructor_point() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, konversi);

  return tc;
}