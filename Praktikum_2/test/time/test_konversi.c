#include <check.h>
#include <stdlib.h>

#include "../../src/time.h"
#include "test.h"

START_TEST(konversiTD) {
  TIME t1 = MakeTIME(12, 11, 10);
  TIME t2 = MakeTIME(0, 0, 0);
  TIME t3 = MakeTIME(23, 59, 59);

  long h = rand() % 24, m = rand() % 60, s = rand() % 60;
  TIME t4 = MakeTIME(h, m, s);

  ck_assert_int_eq(TIMEToDetik(t1), 43870L);
  ck_assert_int_eq(TIMEToDetik(t2), 0L);
  ck_assert_int_eq(TIMEToDetik(t3), 86400L - 1);
  ck_assert_int_eq(TIMEToDetik(t4), h * 3600 + m * 60 + s);
}
END_TEST

START_TEST(konversiDT) {
  TIME t1 = MakeTIME(0, 0, 0);
  TIME t2 = MakeTIME(2, 46, 40);
  TIME t3 = MakeTIME(7, 16, 16);

  TIME res1 = DetikToTIME(0);
  TIME res2 = DetikToTIME(10000);
  TIME res3 = DetikToTIME(198976);

  ck_assert_mem_eq(&t1, &res1, sizeof(TIME));
  ck_assert_mem_eq(&t2, &res2, sizeof(TIME));
  ck_assert_mem_eq(&t3, &res3, sizeof(TIME));
}
END_TEST

TCase* test_konversi() {
  TCase* tc = tcase_create("Tes Konversi");
  tcase_add_test(tc, konversiTD);
  tcase_add_test(tc, konversiDT);

  return tc;
}