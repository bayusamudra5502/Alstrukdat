#include <check.h>
#include <stdlib.h>

#include "../../src/listpos.h"
#include "test.h"

START_TEST(tes_kosong) {
  ListPos l1, l2, l3, l4, l5;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  int tes2[] = {1, 2, 3, VAL_UNDEF, 5, 6};
  int tes3[] = {VAL_UNDEF, 2, 3, 4, 5, 6};

  memcpy(l1.contents, tes1, sizeof(tes1));
  memcpy(l2.contents, tes2, sizeof(tes2));
  memcpy(l5.contents, tes3, sizeof(tes3));

  for (int i = 0; i < CAPACITY; i++) {
    l4.contents[i] = rand();
  }

  ck_assert(!isEmpty(l1));
  ck_assert(!isEmpty(l2));
  ck_assert(isEmpty(l3));
  ck_assert(!isEmpty(l4));
  ck_assert(isEmpty(l5));
}
END_TEST

START_TEST(tes_penuh) {
  ListPos l1, l2, l3, l4, l5;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  int tes2[] = {1, 2, 3, VAL_UNDEF, 5, 6};
  int tes3[] = {VAL_UNDEF, 2, 3, 4, 5, 6};

  memcpy(l1.contents, tes1, sizeof(tes1));
  memcpy(l2.contents, tes2, sizeof(tes2));
  memcpy(l5.contents, tes3, sizeof(tes3));

  for (int i = 0; i < CAPACITY; i++) {
    l4.contents[i] = rand();
  }

  ck_assert(!isFull(l1));
  ck_assert(!isFull(l2));
  ck_assert(!isFull(l3));
  ck_assert(isFull(l4));
  ck_assert(!isFull(l5));
}
END_TEST

START_TEST(tes_sama) {
  ListPos l1, l2, l3, l4;

  CreateListPos(&l1);
  CreateListPos(&l2);
  CreateListPos(&l3);
  CreateListPos(&l4);

  int tes1[] = {1, 2, 3, 4, 5, 6};
  int tes2[] = {1, 2, 3, VAL_UNDEF, 5, 6};
  int tes3[] = {1, 2, 3};
  int tes4[] = {1, 2, 3, 4, 5, 5};

  memcpy(l1.contents, tes1, sizeof(tes1));
  memcpy(l2.contents, tes2, sizeof(tes2));
  memcpy(l3.contents, tes3, sizeof(tes3));
  memcpy(l4.contents, tes4, sizeof(tes4));

  ck_assert(isListEqual(l1, l1));
  ck_assert(isListEqual(l2, l3));
  ck_assert(!isListEqual(l1, l3));
  ck_assert(!isListEqual(l1, l4));
}
END_TEST

TCase* test_kosong_listpos() {
  TCase* tc = tcase_create("Tes Kosong/Penuh");
  tcase_add_test(tc, tes_kosong);
  tcase_add_test(tc, tes_penuh);
  tcase_add_test(tc, tes_sama);

  return tc;
}