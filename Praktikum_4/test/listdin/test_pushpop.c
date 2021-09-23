#include <check.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_push) {
  ListDin l, lans;
  CreateListDin(&l, 10);
  CreateListDin(&lans, 10);

  insertLast(&l, 12);
  insertLast(&l, 10);
  insertLast(&l, 30);

  int ans[] = {12, 10, 30};
  copyFromArrayHelper(3, ans, &lans);

  ck_assert(isAllEqHelper(l, lans));

  dealocate(&l);
  dealocate(&lans);
}
END_TEST

START_TEST(tes_pop) {
  ListDin l;
  CreateListDin(&l, 10);

  insertLast(&l, 12);
  insertLast(&l, 10);
  insertLast(&l, 30);

  int val;
  deleteLast(&l, &val);
  ck_assert_int_eq(length(l), 2);
  ck_assert_int_eq(ELMT(l, 0), 12);
  ck_assert_int_eq(ELMT(l, 1), 10);
  ck_assert_int_eq(val, 30);

  deleteLast(&l, &val);
  ck_assert_int_eq(val, 10);

  deleteLast(&l, &val);
  ck_assert_int_eq(val, 12);

  dealocate(&l);
}
END_TEST

START_TEST(test_growlist) {
  ListDin l;

  CreateListDin(&l, 20);

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  copyFromArrayHelper(10, arr, &l);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 20);

  growList(&l, 5);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 25);

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(arr[i], ELMT(l, i));
  }

  dealocate(&l);
}
END_TEST

START_TEST(test_shrinklist) {
  ListDin l;

  CreateListDin(&l, 20);

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  copyFromArrayHelper(10, arr, &l);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 20);

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(arr[i], ELMT(l, i));
  }

  shrinkList(&l, 5);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 15);

  shrinkList(&l, 5);
  ck_assert(isFull(l));

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(arr[i], ELMT(l, i));
  }

  dealocate(&l);
}
END_TEST

START_TEST(test_compactlist) {
  ListDin l;

  CreateListDin(&l, 20);

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  copyFromArrayHelper(10, arr, &l);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 20);

  compactList(&l);

  ck_assert(isFull(l));
  ck_assert_int_eq(CAPACITY(l), NEFF(l));
  ck_assert_int_eq(CAPACITY(l), 10);

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(arr[i], ELMT(l, i));
  }

  dealocate(&l);

  CreateListDin(&l, 10);

  copyFromArrayHelper(10, arr, &l);

  ck_assert_int_eq(length(l), 10);
  ck_assert_int_eq(CAPACITY(l), 10);

  compactList(&l);

  ck_assert(isFull(l));
  ck_assert_int_eq(CAPACITY(l), NEFF(l));
  ck_assert_int_eq(CAPACITY(l), 10);

  dealocate(&l);
}
END_TEST

TCase* test_pushpop_listdin() {
  TCase* tc = tcase_create("Tes Push Pop Element");
  tcase_add_test(tc, tes_push);
  tcase_add_test(tc, tes_pop);
  tcase_add_test(tc, test_growlist);
  tcase_add_test(tc, test_shrinklist);
  tcase_add_test(tc, test_compactlist);

  return tc;
}