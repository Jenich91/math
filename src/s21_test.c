#include "s21_math.h"
#include <math.h>
#include <check.h>
#include <stdlib.h>

START_TEST(abs_PassTest) {
    ck_assert_int_eq(s21_abs(-4), abs(-4));
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(10), abs(10));
    ck_assert_int_eq(s21_abs(4), abs(4));
    ck_assert_int_eq(s21_abs(-438), abs(-438));
}
END_TEST

START_TEST(exp_PassTest) {
    ck_assert_ldouble_eq_tol(s21_exp(35), expl(35), 6);
    ck_assert_ldouble_eq_tol(s21_exp(-4), expl(-4), 6);
    ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 6);
    ck_assert_float_eq(exp(0.00001), s21_exp(0.00001));
    ck_assert_float_eq(exp(-1.0), s21_exp(-1.0));
    ck_assert_float_eq(exp(0.0), s21_exp(0.0));
    ck_assert_ldouble_eq_tol(s21_exp(2.15), expl(2.15), 6);
    ck_assert_ldouble_eq_tol(s21_exp(-4.38), expl(-4.38), 6);
    ck_assert_ldouble_eq(s21_exp(S21_INFINITY), expl(S21_INFINITY));
    ck_assert_ldouble_eq(s21_exp(-S21_INFINITY), expl(-S21_INFINITY));
}
END_TEST

START_TEST(fabs_PassTest) {
    ck_assert_ldouble_eq(s21_fabs(50.0), fabs(50.0));
    ck_assert_ldouble_eq(s21_fabs(-40.0), fabs(-40.0));
    ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
    ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
    ck_assert_float_eq(s21_fabs(S21_INFINITY), fabs(S21_INFINITY));
}
END_TEST

START_TEST(log_PassTest) {
    ck_assert_ldouble_eq_tol(s21_log(50), log(50), 6);
    ck_assert_ldouble_eq_tol(s21_log(40), log(40), 6);
    ck_assert_ldouble_eq_tol(s21_log(4), log(4), 6);
    ck_assert_ldouble_eq_tol(s21_log(10), log(10), 6);
    ck_assert_ldouble_eq_tol(s21_log(2.15), log(2.15), 6);
    ck_assert_ldouble_eq_tol(s21_log(4.38), log(4.38), 6);
    ck_assert_float_eq(log(7777777), s21_log(7777777));
    ck_assert_float_eq(log(1), s21_log(1));
    ck_assert_float_eq(log(S21_INFINITY), s21_log(S21_INFINITY));
    ck_assert_ldouble_nan(s21_log(S21_NAN));
    ck_assert_ldouble_nan(s21_log(-4));
    ck_assert_ldouble_nan(s21_log(-S21_INFINITY));
}
END_TEST

START_TEST(s21_log_3) {
  double x = 1e-06;
  long double sub = (long double)log(x) - s21_log(x);
  if (sub < 0) sub *= -1;
  long double epsilon = 1e-7L;
  ck_assert_ldouble_ge(epsilon, sub);
}
END_TEST

START_TEST(sin_PassTest) {
    ck_assert_int_eq(s21_sin(-4), sin(-4));
    ck_assert_int_eq(s21_sin(0), sin(0));
    ck_assert_int_eq(s21_sin(10), sin(10));
    ck_assert_int_eq(s21_sin(4), sin(4));
    ck_assert_int_eq(s21_sin(-438), sin(-438));
}
END_TEST

START_TEST(cos_PassTest) {
    ck_assert_int_eq(s21_cos(-4), cos(-4));
    ck_assert_int_eq(s21_cos(0), cos(0));
    ck_assert_int_eq(s21_cos(10), cos(10));
    ck_assert_int_eq(s21_cos(4), cos(4));
    ck_assert_int_eq(s21_cos(-438), cos(-438));
}
END_TEST

START_TEST(tan_PassTest) {
    ck_assert_int_eq(s21_tan(-4), tan(-4));
    ck_assert_int_eq(s21_tan(0), tan(0));
    ck_assert_int_eq(s21_tan(10), tan(10));
    ck_assert_int_eq(s21_tan(4), tan(4));
    ck_assert_int_eq(s21_tan(-438), tan(-438));
}
END_TEST

START_TEST(ceil_PassTest) {
    ck_assert_msg(s21_ceil(12.01) == ceil(12.01), "1 test failed");
    ck_assert_msg(s21_ceil(-12.01) == ceil(-12.01), "2  test failed");
    ck_assert_msg(s21_ceil(9.99) == ceil(9.99), "3  test failed");
    ck_assert_msg(s21_ceil(5.00) == ceil(5.00), "4  test failed");
    ck_assert_msg(s21_ceil(5.0000000000001) == ceil(5.0000000000001),
                  "5  test failed");
    ck_assert_msg(s21_ceil(-5.0000000000001) == ceil(-5.0000000000001),
                  "6  false");
    ck_assert_msg(s21_ceil(-12.99) == ceil(-12.99), "7 test failed");
    ck_assert_msg(s21_ceil(0) == ceil(0), "8 test failed");
    ck_assert_msg(s21_ceil(3123.43242353523) == ceil(3123.43242353523),
                  "9 test failed");
}
END_TEST

START_TEST(floor_PassTest) {
    ck_assert_msg(floor(12.873) == s21_floor(12.873), "1 test failed");
    ck_assert_msg(floor(-12.873) == s21_floor(-12.873), "2 test failed");
    ck_assert_msg(floor(12.00001) == s21_floor(12.00001), "3 test failed");
    ck_assert_msg(floor(-12.00001) == s21_floor(-12.00001), "4 test failed");
    ck_assert_msg(floor(-0.9999) == s21_floor(-0.9999), "5 test failed");
    ck_assert_msg(floor(0.9999) == s21_floor(0.9999), "6 test failed");
    ck_assert_msg(floor(5.000) == s21_floor(5.000), "7 test failed");
    END_TEST
}

START_TEST(fmod_PassTest) {
    ck_assert_msg(fmod(5.1, 3.0) == s21_fmod(5.1, 3.0), "1 test failed");
    ck_assert_msg(fmod(-5.1, 3.0) == s21_fmod(-5.1, 3.0), "2 test failed");
    ck_assert_msg(fmod(5.1, -3.0) == s21_fmod(5.1, -3.0), "3 test failed");
    ck_assert_msg(fmod(-5.1, -3.0) == s21_fmod(-5.1, -3.0), "4 test failed");
    ck_assert_msg(fmod(0.0, 1.0) == s21_fmod(0.0, 1.0), "5 test failed");
    ck_assert_msg(fmod(-0.0, 1.0) == s21_fmod(-0.0, 1.0), "6 test failed");
    ck_assert_msg(fmod(5.1, (int)INFINITY) == s21_fmod(5.1, (int)INFINITY),
                  "7 test failed");
    ck_assert_msg(fmod(5, 5) == s21_fmod(5, 5), "8 test failed");
    END_TEST
}

START_TEST(pow_PassTest) {
    ck_assert_ldouble_nan(s21_pow(S21_NAN, 3));  // nan
    ck_assert_ldouble_nan(s21_pow(3, S21_NAN));  // nan
    ck_assert_double_infinite(s21_pow(0, -9));  // pinf
    ck_assert_double_infinite(s21_pow(-S21_INFINITY, 2.375));  // pinf
    // ck_assert_double_infinite(s21_pow(0.25, -S21_INFINITY));  // pinf
    ck_assert_double_infinite(s21_pow(-7.25, S21_INFINITY));  // pinf
    ck_assert_double_infinite(s21_pow(-S21_INFINITY, 5));  // ninf
    ck_assert_double_infinite(s21_pow(-434, 434));  // pinf
    ck_assert_double_infinite(s21_pow(S21_INFINITY, 2.375));  // pinf
    ck_assert_ldouble_eq(pow(-0.25, S21_INFINITY), s21_pow(-0.25, S21_INFINITY));  // +0
    ck_assert_ldouble_eq(pow(-7.25, -S21_INFINITY), s21_pow(-7.25, -S21_INFINITY));  // +0
    ck_assert_ldouble_eq(pow(-S21_INFINITY, -5), s21_pow(-S21_INFINITY, -5));  // -0
    ck_assert_ldouble_eq(pow(+1, NAN), s21_pow(+1, S21_NAN));  // 1.0
    ck_assert_ldouble_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));  // 1
    ck_assert_ldouble_eq(pow(-1, S21_INFINITY), s21_pow(-1, S21_INFINITY));  // 1.0
    ck_assert_ldouble_eq(pow(-1, -S21_INFINITY), s21_pow(-1, -S21_INFINITY));  // 1.0
    ck_assert_ldouble_eq(pow(-S21_INFINITY, -5.98), s21_pow(-S21_INFINITY, -5.98));  // +0
    ck_assert_ldouble_eq(pow(S21_INFINITY, -2.375), s21_pow(S21_INFINITY, -2.375));  // +0
    ck_assert_ldouble_eq(pow(-1.0, 1), s21_pow(-1.0, 1));  // -1
    ck_assert_ldouble_eq(pow(1, 1), s21_pow(1, 1));  // 1
    ck_assert_ldouble_eq(pow(0, 0), s21_pow(0, 0));  // 1
    ck_assert_ldouble_eq_tol(pow(0.000001, -1), s21_pow(0.000001, -1), 7);  // 1000000
    ck_assert_ldouble_eq_tol(pow(5, 3), s21_pow(5, 3), 6);
    ck_assert_ldouble_eq_tol(pow(-5.1, 3.0), s21_pow(-5.1, 3.0), 6);
    ck_assert_ldouble_eq_tol(pow(5, 3.0), s21_pow(5, 3.0), 6);
    ck_assert_ldouble_eq_tol(pow(5.1, 3.0), s21_pow(5.1, 3.0), 6);
    ck_assert_ldouble_eq_tol(pow(0.0, 1.0), s21_pow(0.0, 1.0), 6);
    ck_assert_ldouble_eq_tol(pow(0.0, 1.0), s21_pow(0.0, 1.0), 6);
    ck_assert_ldouble_eq_tol(pow(5, 5), s21_pow(5, 5), 6);
    ck_assert_ldouble_eq_tol(pow(+1, 5), s21_pow(+1, 5), 6);
    ck_assert_ldouble_eq_tol(pow(4, 0), s21_pow(4, 0), 6);
    ck_assert_ldouble_eq_tol(pow(+0, 7), s21_pow(+0, 7), 6);
    ck_assert_ldouble_eq_tol(pow(-0, 9), s21_pow(-0, 9), 6);
    ck_assert_ldouble_eq_tol(pow(0, 3.25), s21_pow(0, 3.25), 6);
    ck_assert_double_infinite(s21_pow(S21_INFINITY, S21_INFINITY));  // pinf
    ck_assert_double_infinite(s21_pow(-S21_INFINITY, S21_INFINITY));  // pinf
    ck_assert_ldouble_eq(pow(S21_INFINITY, -S21_INFINITY), s21_pow(S21_INFINITY, -S21_INFINITY));  // 0
    ck_assert_ldouble_eq(pow(-S21_INFINITY, -S21_INFINITY), s21_pow(-S21_INFINITY, -S21_INFINITY));  // 0
    END_TEST
}

START_TEST(atan_PassTest) {
    ck_assert_ldouble_nan(s21_atan(S21_NAN));
    ck_assert_ldouble_eq_tol(atan(+0), s21_atan(+0), 6);
    ck_assert_ldouble_eq_tol(atan(-0), s21_atan(-0), 6);
    ck_assert_ldouble_eq_tol(atan(S21_INFINITY), s21_atan(S21_INFINITY), 6);
    ck_assert_ldouble_eq_tol(atan(-S21_INFINITY), s21_atan(-S21_INFINITY), 6);
    ck_assert_ldouble_eq_tol(atan(100), s21_atan(100), 6);
    ck_assert_ldouble_eq_tol(atan(-5.1), s21_atan(-5.1), 6);
    ck_assert_ldouble_eq_tol(atan(-2.0), s21_atan(-2.0), 6);
    ck_assert_ldouble_eq_tol(atan(3.0), s21_atan(3.0), 6);
    ck_assert_ldouble_eq_tol(atan(1.0), s21_atan(1.0), 6);
    ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 6);
    ck_assert_ldouble_eq_tol(atan((int)INFINITY), s21_atan((int)INFINITY), 6);
    ck_assert_ldouble_eq_tol(atan(5), s21_atan(5), 6);
    ck_assert_float_eq(atan(0.000001), s21_atan(0.000001));
    ck_assert_float_eq(atan(-2), s21_atan(-2));
    ck_assert_float_eq(atan(0.0), s21_atan(0.0));
    END_TEST
}

START_TEST(acos_PassTest) {
    ck_assert_int_eq(acos(1.0), s21_acos(1.0));
    ck_assert_int_eq(acos(0.0), s21_acos(0.0));
    ck_assert_int_eq(acos((int)INFINITY), s21_acos((int)INFINITY));

    END_TEST
}

START_TEST(sqrt_PassTest) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 6);
    ck_assert_ldouble_eq_tol(s21_sqrt(23436423456432), sqrt(23436423456432), 6);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.000009), sqrt(0.000009), 6);
    ck_assert_float_eq(sqrt(22.123), s21_sqrt(22.123));
    ck_assert_float_eq(sqrt(25), s21_sqrt(25));
    ck_assert_float_eq(sqrt(1), s21_sqrt(1));
    ck_assert_float_eq(sqrt(0), s21_sqrt(0));
    ck_assert_float_eq(sqrt(1234567.35243), s21_sqrt(1234567.35243));
}
END_TEST

START_TEST(asin_PassTest) {
    ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), 6);
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 6);
    ck_assert_ldouble_eq_tol(s21_asin(0.000005), asin(0.000005), 6);
    ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 6);
    ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 6);
}
END_TEST

int main() {
    Suite *s1 = suite_create("s21_math");
    TCase *tc1_1 = tcase_create("s21_math");
    SRunner *sr = srunner_create(s1);
    int nf;
    tcase_set_timeout(tc1_1, 90);
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, abs_PassTest);
    tcase_add_test(tc1_1, log_PassTest);
    tcase_add_test(tc1_1, s21_log_3);
    tcase_add_test(tc1_1, exp_PassTest);
    tcase_add_test(tc1_1, floor_PassTest);
    tcase_add_test(tc1_1, fabs_PassTest);
    tcase_add_test(tc1_1, tan_PassTest);
    tcase_add_test(tc1_1, cos_PassTest);
    tcase_add_test(tc1_1, sin_PassTest);
    tcase_add_test(tc1_1, ceil_PassTest);
    tcase_add_test(tc1_1, fmod_PassTest);
    tcase_add_test(tc1_1, pow_PassTest);
    tcase_add_test(tc1_1, atan_PassTest);
    tcase_add_test(tc1_1, acos_PassTest);
    tcase_add_test(tc1_1, sqrt_PassTest);
    tcase_add_test(tc1_1, asin_PassTest);
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nf == 0 ? 0 : 1;
}
