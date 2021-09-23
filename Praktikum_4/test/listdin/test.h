#include <check.h>
#include "../../src/listdin.h"

#ifndef POINT_TEST_H
#define POINT_TEST_H

TCase* test_constructor_listdin();
TCase* test_selektor_listdin();
TCase* test_kosong_listdin();
TCase* test_math_listdin();
TCase* test_op_listdin();
TCase* test_cari_listdin();
TCase* test_sort_listdin();
TCase* test_pushpop_listdin();

Suite* listdin_suite();

// Helper
ListDin CreateListDinFromArray(int capacity, int* array, int n);
boolean isEqHelper(ListDin arr1, ListDin arr2);
boolean isAllEqHelper(ListDin arr1, ListDin arr2);
void copyFromArrayHelper(int n, int* arr, ListDin* l);

#endif