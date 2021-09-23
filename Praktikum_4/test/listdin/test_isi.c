#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../src/listdin.h"
#include "test.h"

START_TEST(tes_kosong) {
  ListDin l1, l2, l3, l4;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);
  CreateListDin(&l3, 10);
  CreateListDin(&l4, 10);

  int tes1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, tes1, &l1);
  copyFromArrayHelper(6, tes1, &l2);
  copyFromArrayHelper(6, tes1, &l4);

  l2.nEff = 10;
  l4.nEff = 0;

  ck_assert(!isEmpty(l1));
  ck_assert(!isEmpty(l2));
  ck_assert(isEmpty(l3));
  ck_assert(isEmpty(l4));

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
  dealocate(&l4);
}
END_TEST

START_TEST(tes_penuh) {
  ListDin l1, l2, l3, l4, l5;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);
  CreateListDin(&l3, 6);
  CreateListDin(&l4, 10);
  CreateListDin(&l5, 10);

  int tes1[] = {1, 2, 3, 4, 5, 6};

  copyFromArrayHelper(6, tes1, &l1);
  copyFromArrayHelper(6, tes1, &l2);
  copyFromArrayHelper(6, tes1, &l3);

  ck_assert(isEmpty(l4));

  for (int i = 0; i < l4.capacity; i++) {
    l4.buffer[i] = rand();
    l4.nEff++;
  }

  ck_assert(!isFull(l1));
  ck_assert(!isFull(l2));
  ck_assert(isFull(l3));
  ck_assert(isFull(l4));
  ck_assert(!isFull(l5));

  dealocate(&l5);
  ck_assert(isFull(l5));

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
  dealocate(&l4);
}
END_TEST

START_TEST(tes_sama) {
  ListDin l1, l2, l3, l4;

  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);
  CreateListDin(&l3, 10);
  CreateListDin(&l4, 10);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  int tes3[] = {1, 2, 3};
  int tes4[] = {1, 2, 3, 4, 5, 5};

  copyFromArrayHelper(6, tes1, &l1);
  copyFromArrayHelper(6, tes1, &l2);
  copyFromArrayHelper(3, tes3, &l3);
  copyFromArrayHelper(6, tes4, &l4);

  l2.nEff = 3;

  ck_assert_int_eq(l2.nEff, l3.nEff);

  ck_assert(isListEqual(l1, l1));
  ck_assert(isListEqual(l2, l3));
  ck_assert(!isListEqual(l1, l3));
  ck_assert(!isListEqual(l1, l4));

  dealocate(&l1);
  dealocate(&l2);
  dealocate(&l3);
  dealocate(&l4);
}
END_TEST

START_TEST(tes_sum) {
  ListDin l1, l2;
  CreateListDin(&l1, 10);
  CreateListDin(&l2, 10);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  copyFromArrayHelper(6, tes1, &l1);
  copyFromArrayHelper(6, tes1, &l2);

  l2.nEff = 3;

  ck_assert_int_eq(sumList(l1), 21);
  ck_assert_int_eq(sumList(l2), 6);

  dealocate(&l1);
  dealocate(&l2);
}

TCase* test_kosong_listdin() {
  TCase* tc = tcase_create("Tes Kosong/Penuh");
  tcase_add_test(tc, tes_kosong);
  tcase_add_test(tc, tes_penuh);
  tcase_add_test(tc, tes_sama);
  tcase_add_test(tc, tes_sum);

  return tc;
}