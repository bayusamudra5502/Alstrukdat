#include <check.h>

#include "../../src/point.h"
#include "test.h"

START_TEST(tesjarak0) {
  POINT p1, p2, p3;
  p1 = MakePOINT(3, 4);
  p2 = MakePOINT(5, 12);
  p3 = MakePOINT(0, 0);

  ck_assert_float_eq(Jarak0(p1), 5.0);
  ck_assert_float_eq(Jarak0(p2), 13);
  ck_assert_float_eq(Jarak0(p3), 0);
}
END_TEST

START_TEST(tesjarak2titik) {
  POINT p1, p2;
  p1 = MakePOINT(10, 7);
  p2 = MakePOINT(7, 3);

  ck_assert_float_eq(Panjang(p1, p2), 5.0);
  ck_assert_float_eq(Panjang(p2, p1), 5.0);
  ck_assert_float_eq(Panjang(p2, p2), 0);
}
END_TEST

TCase* test_jarak_point() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tesjarak0);
  tcase_add_test(tc, tesjarak2titik);

  return tc;
}