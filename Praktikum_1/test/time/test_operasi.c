#include <check.h>
#include <limits.h>

#include "../../src/time.h"
#include "test.h"

START_TEST(tambah1) {
  TIME t1 = MakeTIME(12, 0, 0);
  TIME t2 = MakeTIME(12, 0, 1);

  TIME t3 = MakeTIME(11, 59, 59);

  TIME t4 = MakeTIME(23, 59, 59);
  TIME t5 = MakeTIME(0, 0, 0);

  ck_assert(TEQ(t2, NextDetik(t1)));
  ck_assert(TEQ(t1, NextDetik(t3)));
  ck_assert(TEQ(t5, NextDetik(t4)));
}
END_TEST

START_TEST(tambahN) {
  TIME t1 = MakeTIME(12, 0, 0);
  TIME t4 = MakeTIME(23, 59, 59);
  TIME t5 = MakeTIME(0, 0, 0);
  TIME t6 = MakeTIME(12, 0, 5);

  ck_assert(TEQ(t1, NextNDetik(t1, 0)));
  ck_assert(TEQ(t6, NextNDetik(t1, 5)));

  ck_assert(TEQ(t5, NextNDetik(t4, 1)));

  // TES OVERFLOW
  const int MAXIMA = INT_MAX % 86400;
  ck_assert_int_eq(TIMEToDetik(NextNDetik(t4, INT_MAX)), MAXIMA - 1);

  TIME res = NextNDetik(t4, INT_MAX);
  ck_assert_int_ge(Hour(res), 0);
  ck_assert_int_ge(Minute(res), 0);
  ck_assert_int_ge(Second(res), 0);
}
END_TEST

START_TEST(kurang1) {
  TIME t1 = MakeTIME(12, 0, 0);
  TIME t2 = MakeTIME(12, 0, 1);

  TIME t3 = MakeTIME(11, 59, 59);

  TIME t4 = MakeTIME(23, 59, 59);
  TIME t5 = MakeTIME(0, 0, 0);

  ck_assert(TEQ(t1, PrevDetik(t2)));
  ck_assert(TEQ(t3, PrevDetik(t1)));
  ck_assert(TEQ(t4, PrevDetik(t5)));
}
END_TEST

START_TEST(kurangN) {
  TIME t1 = MakeTIME(12, 0, 0);
  TIME t4 = MakeTIME(23, 59, 59);
  TIME t5 = MakeTIME(0, 0, 0);
  TIME t6 = MakeTIME(12, 0, 5);

  ck_assert(TEQ(t1, PrevNDetik(t1, 0)));
  ck_assert(TEQ(t1, PrevNDetik(t6, 5)));

  ck_assert(TEQ(t4, PrevNDetik(t5, 1)));

  // TES OVERFLOW
  const int MAXIMA = INT_MAX % 86400;
  ck_assert_int_eq(TIMEToDetik(PrevNDetik(t5, INT_MAX)), 86400 - MAXIMA);

  TIME res = PrevNDetik(t5, INT_MAX);
  ck_assert_int_ge(Hour(res), 0);
  ck_assert_int_ge(Minute(res), 0);
  ck_assert_int_ge(Second(res), 0);
}
END_TEST

TCase* test_operasi() {
  TCase* tc = tcase_create("Tes Operasi");
  tcase_add_test(tc, tambah1);
  tcase_add_test(tc, tambahN);
  tcase_add_test(tc, kurang1);
  tcase_add_test(tc, kurangN);

  return tc;
}
END_TEST

START_TEST(tesDurasi) {
  TIME t1 = MakeTIME(1, 1, 1);
  TIME t2 = MakeTIME(1, 1, 3);
  TIME t3 = MakeTIME(1, 1, 0);

  ck_assert_int_eq(Durasi(t1, t1), 0);
  ck_assert_int_eq(Durasi(t1, t2), 2);
  ck_assert_int_eq(Durasi(t1, t3), 86399);
}
END_TEST

TCase* test_durasi() {
  TCase* tc = tcase_create("Tes Durasi");
  tcase_add_test(tc, tesDurasi);

  return tc;
}