#include <check.h>

#ifndef POINT_TEST_H
#define POINT_TEST_H

TCase* test_constructor_listpos();
TCase* test_selektor_listpos();
TCase* test_kosong_listpos();
TCase* test_math_listpos();
TCase* test_op_listpos();
TCase* test_cari_listpos();
TCase* test_sort_listpos();
TCase* test_pushpop_listpos();

Suite* listpos_suite();

#endif