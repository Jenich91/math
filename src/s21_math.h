#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_E 2.71828182845904523536028747135266250        /* e          */
#define S21_LN2 0.693147180559945309417232121458176568     /* log e2     */
#define S21_PI 3.14159265358979323846264338327950288       /* pi         */
#define S21_PI_2 1.57079632679489661923132169163975144     /* pi/2       */

#define S21_NAN 0.f / 0.f
#define S21_INFINITY 1.0 / 0.0
#define S21_EPS 1e-17


// s21_functions
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
