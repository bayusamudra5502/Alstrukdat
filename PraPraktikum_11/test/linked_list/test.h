#include <check.h>

#include "../../src/linked_list.h"

#ifndef LINKED_TEST_H
#define LINKED_TEST_H

TCase* test_constructor();
TCase* test_insertf();
TCase* test_helper();
TCase* test_idxo();
TCase* test_length();
TCase* test_concat();
TCase* test_insert();
TCase* test_delete();
TCase* test_setget();

Suite* linked_suite();

List array2list(int* data, int len);
void list2array(int* result, List data, int len);
void equalitiyCheck_l2a(List l, int* data, int len);

#endif