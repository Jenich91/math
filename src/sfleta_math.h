#ifndef SRC_sfleta_MATH_H_
#define SRC_sfleta_MATH_H_

#define sfleta_E 2.71828182845904523536028747135266250        /* e          */
#define sfleta_LN2 0.693147180559945309417232121458176568     /* log e2     */
#define sfleta_PI 3.14159265358979323846264338327950288       /* pi         */
#define sfleta_PI_2 1.57079632679489661923132169163975144     /* pi/2       */

#define sfleta_NAN 0.f / 0.f
#define sfleta_INFINITY 1.0 / 0.0
#define sfleta_EPS 1e-17


// sfleta_functions
int sfleta_abs(int x);
long double sfleta_acos(double x);
long double sfleta_asin(double x);
long double sfleta_atan(double x);
long double sfleta_ceil(double x);
long double sfleta_cos(double x);
long double sfleta_exp(double x);
long double sfleta_fabs(double x);
long double sfleta_floor(double x);
long double sfleta_fmod(double x, double y);
long double sfleta_log(double x);
long double sfleta_pow(double base, double exp);
long double sfleta_sin(double x);
long double sfleta_sqrt(double x);
long double sfleta_tan(double x);

#endif  // SRC_sfleta_MATH_H_
