#include <check.h>

#include "../../src/matrix.h"

#ifndef POINT_TEST_H
#define POINT_TEST_H

TCase* test_constructor_matrix();
TCase* test_selektor_matrix();
TCase* test_copy_matrix();
TCase* test_aritmatika_matrix();
TCase* test_determinant_matrix();

Suite* matrix_suite();

// Helper
Matrix arrayToMatrix(int* matrix, int rows, int cols);
void isEqualTC(Matrix a, Matrix b);

#endif