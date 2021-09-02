#include <check.h>

#ifndef POINT_TEST_H
#define POINT_TEST_H

TCase* test_constructor_point();
TCase* test_jarak_point();
TCase* test_lokasi_point();
TCase* test_relasional_point();
TCase* test_operasi_point();
TCase* test_transformasi_point();

Suite* point_suite();

#endif