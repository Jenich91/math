#include "s21_math.h"

int check_pow_edge_cases(double base, double exp, long double *result);
long double factorial(int x);
long double power_int(double base, int exp);

long double s21_pow(double base, double exp) {
    long double result = 0;
    if (exp == (int)exp) {
        result = power_int(base, (int)exp);
    } else if (!check_pow_edge_cases(base, exp, &result)) {
        result = s21_exp(exp * (double)s21_log(base));
    }
    return result;
}

long double s21_exp(double x) {
    long double result;

    if (x == 0 || s21_fabs(x) == S21_INFINITY) {
        result = (x == 0) ? 1 : (x < 0) ? 0 : S21_INFINITY;
    } else {
        long double sum = 1.0;
        for (int i = 1; i <= 16; i++) {
            sum += power_int(x - (int)x, i) / factorial(i);
        }
        result = sum * power_int(S21_E, (int)x);
    }
    return result;
}

long double s21_log(double x) {
    long double result = 0;
    if (x != x) {
        result = S21_NAN;
    } else if (x == S21_INFINITY) {
        result = S21_INFINITY;
    } else if (x < 0.0) {
        result = S21_NAN;
    } else if (x == 0.0) {
        result = -S21_INFINITY;
    } else if (x < 2.0) {
        long double y = x - 1, ypow = y;
        for (int i = 1; s21_fabs(ypow / i) > S21_EPS; i++) {
            result += ypow / i * (i % 2 == 1 ? 1 : -1);
            ypow *= y;
        }
    } else {
        int k;
        for (k = 0; x >= 2.0; k++) {
            x /= 2;
        }
        result = k * S21_LN2 + s21_log(x);
    }
    return result;
}

long double s21_sqrt(double x) {
    long double res;
    if (x != x || x < 0 || x == -S21_INFINITY) {
        res = S21_NAN;
    } else {
        if (s21_fabs(x) == S21_INFINITY || s21_fabs(x) == 0) {
            res = x;
        } else {
            res = s21_pow(x, 0.5);
        }
    }
    return res;
}

int check_pow_edge_cases(double base, double exp, long double *result) {
    int edge_case = 1;
    double temp_result;
    int sign_exp = (exp < 0) ? -1 : 1;
    if (base == 1.0) {
        temp_result = 1.0;
    } else if (exp == 0.0) {
        temp_result = 1.0;
    } else if (exp == 1.0) {
        temp_result = base;
    } else if (base == -1.0 && (exp == S21_INFINITY || exp == -S21_INFINITY)) {
        temp_result = 1.0;
    } else if (base > -1 && base < 0) {
        if (exp == S21_INFINITY)
            temp_result = 0;
        else if (exp == -S21_INFINITY)
            temp_result = S21_INFINITY;
        else
            temp_result = S21_NAN;
    } else if (base < 0 && exp == S21_INFINITY) {
        temp_result = S21_INFINITY;
    } else if (base < 0 && exp == -S21_INFINITY) {
        temp_result = -0;
    } else if (base == -S21_INFINITY && exp > 0) {
        temp_result = S21_INFINITY;
    } else if (base == -S21_INFINITY && exp < 0) {
        temp_result = 0;
    } else if (base == 0.0 && exp == -S21_INFINITY) {
        temp_result = S21_INFINITY;
    } else if (base == S21_INFINITY) {
        temp_result = (sign_exp > 0) ? S21_INFINITY : 0.0;
    } else if (base == -S21_INFINITY) {
        temp_result = (sign_exp > 0) ? 0.0 : S21_INFINITY;
    } else if (exp == S21_INFINITY && base == 0.0) {
        temp_result = 0;
    } else if (exp == S21_INFINITY) {
        temp_result = (base > 0) ? S21_INFINITY : S21_NAN;
    } else if (exp == -S21_INFINITY) {
        temp_result = (base > 0) ? 0.0 : S21_NAN;
    } else if (base == 0.0 && exp > 0) {
        temp_result = 0.0;
    } else if (base == 0.0 && exp < 0) {
        temp_result = S21_INFINITY;
    } else if ((int)exp != exp && base < 0) {
        temp_result = S21_NAN;
    } else {
        edge_case = 0;
    }
    if (edge_case) {
        *result = temp_result;
    }
    return edge_case;
}

long double factorial(int x) {
    long double factorial = 1;
    for (long int i = 2; i <= x; i++) factorial *= i;
    return factorial;
}

long double power_int(double base, int exp) {
    long double result = 1;
    for (int i = 1; i <= s21_abs(exp); i++) result *= base;
    if (exp < 0) result = 1.0 / result;
    return result;
}

int s21_abs(int x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

long double s21_acos(double x) {
    long double res;
    if (x < -1 || x > 1) {
        res = S21_NAN;
    } else if (x == -1.) {
        res = S21_PI;
    } else if (x == 1.) {
        res = 0;
    } else {
        long double tal = x;
        res = S21_PI / 2;
        int i = 0;
        do {
            res -= tal;
            tal *= (x * x * (2 * i + 1) * (2 * i + 1)) /
                   (2 * (i + 1) * (2 * i + 3));
            ++i;
        } while (s21_fabs(tal) > S21_EPS);
    }
    return res;
}

long double s21_asin(double x) {
    long double res;
    if (1 / x == -S21_INFINITY) {
        res = -0.0;
    } else if ((x < -1) || (x > 1)) {
        res = S21_NAN;
    } else if (x == -1.) {
        res = -S21_PI / 2;
    } else if (x == 1.) {
        res = S21_PI / 2;
    } else {
        long double tal = x;
        res = 0.0;
        int i = 0;
        do {
            res -= tal;
            tal *= (x * x * (2 * i + 1) * (2 * i + 1)) /
                   (2 * (i + 1) * (2 * i + 3));
            ++i;
        } while (s21_fabs(tal) > S21_EPS);
        res = -res;
    }
    return res;
}

long double s21_atan(double x) {
  long double atan21 = 0;
    if (x == S21_INFINITY) {
        atan21 = S21_PI_2;
    } else if (x == S21_INFINITY) {
        atan21 = -1.L * S21_PI_2;
  } else if (x != x) {
    atan21 = S21_NAN;
  } else if (s21_fabs(x) == 0) {
      atan21 = x;
    } else if (s21_fabs(x) < 10) {
      atan21 = s21_asin(x / s21_sqrt(1.0 + x * x));
    } else {
      if (x > 0) atan21 = S21_PI_2 - s21_atan(1. / x);
      if (x < 0) atan21 = -(S21_PI_2 - s21_atan(1. / (-x)));
    }
  return atan21;
}

long double s21_ceil(double x) {
    if (x == 0.0) {
        x *= (1.0);
    } else if ((x != S21_INFINITY) && (x != S21_INFINITY * -1) && (x == x)) {
        if ((signed long long)x < x) {
            x = (signed long long)((signed long long)x + 1.0);
        } else {
            if (x > -1 && x < 0) {
                x = -(long double)((signed long long)x);
            } else {
                x = (long double)((signed long long)x);
            }
        }
    }
    return (x);
}

long double s21_cos(double x) {
    long double eps = 1e-30;
    long double sum = 0;
    double an = 0;
    int i = 1;
    int sign = 1;
    int k = 0;
    if (x < 0) {
        sign *= -1;
    }
    x = s21_fabs(x);
    while (x >= k * 2 * S21_PI) {
        k++;
    }
    x = (x - ((k - 1) * 2 * S21_PI)) * sign;
    an = 1;
    while (s21_fabs(an) > eps) {
        sum += an;
        an *= -(x * x / ((2 * i) * (2 * i - 1)));
        i++;
    }
    return sum;
}

long double s21_fabs(double x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

long double s21_floor(double x) {
    if (x == 0) {
        x *= (1);
    } else if ((x != S21_INFINITY) && (x != S21_INFINITY * -1) && (x == x)) {
        if ((signed long long)x <= x) {
            x = (long double)((signed long long)x);
        } else {
            x = (long double)((signed long long)x - 1);
        }
    }

    return (x);
}

long double s21_fmod(double x, double y) {
    long double ostatok = 0;

    if (y == 0. || x == S21_INFINITY || x == S21_INFINITY * -1 || x != x) {
        ostatok = S21_NAN;
    } else if (y == S21_INFINITY || y == S21_INFINITY * -1) {
        ostatok = x;
    } else {
        __int128_t reuslt = 0;
        reuslt = x / y;
        ostatok = x - (reuslt * y);
    }

    return ostatok;
}

long double s21_sin(double x) {
    long double res;
    if (x == S21_INFINITY || x == -S21_INFINITY || x == S21_NAN) {
        res = S21_NAN;
    } else {
        double x_f = s21_fmod(x, (2 * S21_PI));
        long double shift = x_f;
        res = shift;
        for (int n = 1; n < 100; n++) {
            shift *=
                (-x_f * x_f) / (2 * (long double)n * (2 * (long double)n + 1));
            res += shift;
        }
    }
    return res;
}

long double s21_tan(double x) {
    x = s21_sin(x) / s21_cos(x);
    return x;
}
