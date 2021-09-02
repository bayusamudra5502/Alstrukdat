#include <check.h>

#ifndef TIME_TEST_H
#define TIME_TEST_H

TCase* test_constructor();
TCase* test_predikat();
TCase* test_konversi();
TCase* test_operator();
TCase* test_operasi();
TCase* test_durasi();

/* Time Suite Definition */
Suite* time_suite();

#endif