#include <check.h>

#include "../../src/point.h"
#include "test.h"

#define check_titik(x, y)                             \
  ck_assert_float_eq_tol(Absis(x), Absis(y), 1.2e-7); \
  ck_assert_float_eq_tol(Ordinat(x), Ordinat(y), 1.2e-7)

START_TEST(tesgeser) {
  POINT p[3], a[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, 12);
  p[2] = MakePOINT(0, 0);

  for (int i = 0; i < 3; i++)
    // COPYING
    a[i] = PlusDelta(p[i], 0, 0);

  Geser(p, 0, 0);
  Geser(p + 1, 2, 3);
  Geser(p + 2, 5.15, 5.15);

  check_titik(p[0], a[0]);
  check_titik(p[1], PlusDelta(a[1], 2, 3));
  check_titik(p[2], PlusDelta(a[2], 5.15, 5.15));
}
END_TEST

START_TEST(tesgeserSbx) {
  POINT p[3], a[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, 12);
  p[2] = MakePOINT(0, 0);

  for (int i = 0; i < 3; i++) {
    a[i] = PlusDelta(p[i], 0, 0);
    Ordinat(a[i]) = 0;

    GeserKeSbX(p + i);
  }

  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(Ordinat(p[i]), 0);
    check_titik(p[i], a[i]);
  }
}
END_TEST

START_TEST(tesgeserSby) {
  POINT p[3], a[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, 12);
  p[2] = MakePOINT(0, 0);

  for (int i = 0; i < 3; i++) {
    a[i] = PlusDelta(p[i], 0, 0);
    Absis(a[i]) = 0;

    GeserKeSbY(p + i);
  }

  for (int i = 0; i < 3; i++) {
    ck_assert_float_eq(Absis(p[i]), 0);
    check_titik(p[i], a[i]);
  }
}
END_TEST

START_TEST(tesmirror1) {
  POINT p[3], a[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, -12);
  p[2] = MakePOINT(0, 0);

  for (int i = 0; i < 3; i++) {
    a[i] = MirrorOf(p[i], true);

    Mirror(p + i, true);
  }

  for (int i = 0; i < 3; i++) {
    check_titik(p[i], a[i]);
  }
}
END_TEST

START_TEST(tesmirror2) {
  POINT p[3], a[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, -12);
  p[2] = MakePOINT(0, 0);

  for (int i = 0; i < 3; i++) {
    a[i] = MirrorOf(p[i], false);

    Mirror(p + i, false);
  }

  for (int i = 0; i < 3; i++) {
    check_titik(p[i], a[i]);
  }
}
END_TEST

START_TEST(tesrotasi) {
  POINT p[3];
  p[0] = MakePOINT(3, 4);
  p[1] = MakePOINT(5, -12);
  p[2] = MakePOINT(1, 3);

  Putar(p, 90);
  Putar(p + 1, -30);
  Putar(p + 2, -45);

  ck_assert_float_eq_tol(Absis(p[0]), -4, 1.2e-7);
  ck_assert_float_eq_tol(Ordinat(p[0]), 3, 1.2e-7);

  ck_assert_float_eq_tol(Absis(p[1]), -1.6698729810778, 1.2e-7);
  ck_assert_float_eq_tol(Ordinat(p[1]), -12.892304845413, 1.2e-7);

  ck_assert_float_eq_tol(Absis(p[2]), 2.8284271247462, 1.2e-7);
  ck_assert_float_eq_tol(Ordinat(p[2]), 1.4142135623731, 1.2e-7);
}
END_TEST

TCase* test_transformasi_point() {
  TCase* tc = tcase_create("Tes Konstruktor");
  tcase_add_test(tc, tesgeser);
  tcase_add_test(tc, tesgeserSbx);
  tcase_add_test(tc, tesgeserSby);
  tcase_add_test(tc, tesmirror1);
  tcase_add_test(tc, tesmirror2);
  tcase_add_test(tc, tesrotasi);

  return tc;
}