#include "sfleta_math.h"

int check_pow_edge_cases(double base, double exp, long double *result);
long double factorial(int x);
long double power_int(double base, int exp);

long double sfleta_pow(double base, double exp) {
    long double result = 0;
    if (exp == (int)exp) {
        result = power_int(base, (int)exp);
    } else if (!check_pow_edge_cases(base, exp, &result)) {
        result = sfleta_exp(exp * (double)sfleta_log(base));
    }
    return result;
}

long double sfleta_exp(double x) {
    long double result;

    if (x == 0 || sfleta_fabs(x) == sfleta_INFINITY) {
        result = (x == 0) ? 1 : (x < 0) ? 0 : sfleta_INFINITY;
    } else {
        long double sum = 1.0;
        for (int i = 1; i <= 16; i++) {
            sum += power_int(x - (int)x, i) / factorial(i);
        }
        result = sum * power_int(sfleta_E, (int)x);
    }
    return result;
}

long double sfleta_log(double x) {
    long double result = 0;
    if (x != x) {
        result = sfleta_NAN;
    } else if (x == sfleta_INFINITY) {
        result = sfleta_INFINITY;
    } else if (x < 0.0) {
        result = sfleta_NAN;
    } else if (x == 0.0) {
        result = -sfleta_INFINITY;
    } else if (x < 2.0) {
        long double y = x - 1, ypow = y;
        for (int i = 1; sfleta_fabs(ypow / i) > sfleta_EPS; i++) {
            result += ypow / i * (i % 2 == 1 ? 1 : -1);
            ypow *= y;
        }
    } else {
        int k;
        for (k = 0; x >= 2.0; k++) {
            x /= 2;
        }
        result = k * sfleta_LN2 + sfleta_log(x);
    }
    return result;
}

long double sfleta_sqrt(double x) {
    long double res;
    if (x != x || x < 0 || x == -sfleta_INFINITY) {
        res = sfleta_NAN;
    } else {
        if (sfleta_fabs(x) == sfleta_INFINITY || sfleta_fabs(x) == 0) {
            res = x;
        } else {
            res = sfleta_pow(x, 0.5);
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
    } else if (base == -1.0 && (exp == sfleta_INFINITY || exp == -sfleta_INFINITY)) {
        temp_result = 1.0;
    } else if (base > -1 && base < 0) {
        if (exp == sfleta_INFINITY)
            temp_result = 0;
        else if (exp == -sfleta_INFINITY)
            temp_result = sfleta_INFINITY;
        else
            temp_result = sfleta_NAN;
    } else if (base < 0 && exp == sfleta_INFINITY) {
        temp_result = sfleta_INFINITY;
    } else if (base < 0 && exp == -sfleta_INFINITY) {
        temp_result = -0;
    } else if (base == -sfleta_INFINITY && exp > 0) {
        temp_result = sfleta_INFINITY;
    } else if (base == -sfleta_INFINITY && exp < 0) {
        temp_result = 0;
    } else if (base == 0.0 && exp == -sfleta_INFINITY) {
        temp_result = sfleta_INFINITY;
    } else if (base == sfleta_INFINITY) {
        temp_result = (sign_exp > 0) ? sfleta_INFINITY : 0.0;
    } else if (base == -sfleta_INFINITY) {
        temp_result = (sign_exp > 0) ? 0.0 : sfleta_INFINITY;
    } else if (exp == sfleta_INFINITY && base == 0.0) {
        temp_result = 0;
    } else if (exp == sfleta_INFINITY) {
        temp_result = (base > 0) ? sfleta_INFINITY : sfleta_NAN;
    } else if (exp == -sfleta_INFINITY) {
        temp_result = (base > 0) ? 0.0 : sfleta_NAN;
    } else if (base == 0.0 && exp > 0) {
        temp_result = 0.0;
    } else if (base == 0.0 && exp < 0) {
        temp_result = sfleta_INFINITY;
    } else if ((int)exp != exp && base < 0) {
        temp_result = sfleta_NAN;
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
    for (int i = 1; i <= sfleta_abs(exp); i++) result *= base;
    if (exp < 0) result = 1.0 / result;
    return result;
}

int sfleta_abs(int x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

long double sfleta_acos(double x) {
    long double res;
    if (x < -1 || x > 1) {
        res = sfleta_NAN;
    } else if (x == -1.) {
        res = sfleta_PI;
    } else if (x == 1.) {
        res = 0;
    } else {
        long double tal = x;
        res = sfleta_PI / 2;
        int i = 0;
        do {
            res -= tal;
            tal *= (x * x * (2 * i + 1) * (2 * i + 1)) /
                   (2 * (i + 1) * (2 * i + 3));
            ++i;
        } while (sfleta_fabs(tal) > sfleta_EPS);
    }
    return res;
}

long double sfleta_asin(double x) {
    long double res;
    if (1 / x == -sfleta_INFINITY) {
        res = -0.0;
    } else if ((x < -1) || (x > 1)) {
        res = sfleta_NAN;
    } else if (x == -1.) {
        res = -sfleta_PI / 2;
    } else if (x == 1.) {
        res = sfleta_PI / 2;
    } else {
        long double tal = x;
        res = 0.0;
        int i = 0;
        do {
            res -= tal;
            tal *= (x * x * (2 * i + 1) * (2 * i + 1)) /
                   (2 * (i + 1) * (2 * i + 3));
            ++i;
        } while (sfleta_fabs(tal) > sfleta_EPS);
        res = -res;
    }
    return res;
}

long double sfleta_atan(double x) {
  long double atan21 = 0;
    if (x == sfleta_INFINITY) {
        atan21 = sfleta_PI_2;
    } else if (x == sfleta_INFINITY) {
        atan21 = -1.L * sfleta_PI_2;
  } else if (x != x) {
    atan21 = sfleta_NAN;
  } else if (sfleta_fabs(x) == 0) {
      atan21 = x;
    } else if (sfleta_fabs(x) < 10) {
      atan21 = sfleta_asin(x / sfleta_sqrt(1.0 + x * x));
    } else {
      if (x > 0) atan21 = sfleta_PI_2 - sfleta_atan(1. / x);
      if (x < 0) atan21 = -(sfleta_PI_2 - sfleta_atan(1. / (-x)));
    }
  return atan21;
}

long double sfleta_ceil(double x) {
    if (x == 0.0) {
        x *= (1.0);
    } else if ((x != sfleta_INFINITY) && (x != sfleta_INFINITY * -1) && (x == x)) {
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

long double sfleta_cos(double x) {
    long double eps = 1e-30;
    long double sum = 0;
    double an = 0;
    int i = 1;
    int sign = 1;
    int k = 0;
    if (x < 0) {
        sign *= -1;
    }
    x = sfleta_fabs(x);
    while (x >= k * 2 * sfleta_PI) {
        k++;
    }
    x = (x - ((k - 1) * 2 * sfleta_PI)) * sign;
    an = 1;
    while (sfleta_fabs(an) > eps) {
        sum += an;
        an *= -(x * x / ((2 * i) * (2 * i - 1)));
        i++;
    }
    return sum;
}

long double sfleta_fabs(double x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

long double sfleta_floor(double x) {
    if (x == 0) {
        x *= (1);
    } else if ((x != sfleta_INFINITY) && (x != sfleta_INFINITY * -1) && (x == x)) {
        if ((signed long long)x <= x) {
            x = (long double)((signed long long)x);
        } else {
            x = (long double)((signed long long)x - 1);
        }
    }

    return (x);
}

long double sfleta_fmod(double x, double y) {
    long double ostatok = 0;

    if (y == 0. || x == sfleta_INFINITY || x == sfleta_INFINITY * -1 || x != x) {
        ostatok = sfleta_NAN;
    } else if (y == sfleta_INFINITY || y == sfleta_INFINITY * -1) {
        ostatok = x;
    } else {
        __int128_t reuslt = 0;
        reuslt = x / y;
        ostatok = x - (reuslt * y);
    }

    return ostatok;
}

long double sfleta_sin(double x) {
    long double res;
    if (x == sfleta_INFINITY || x == -sfleta_INFINITY || x == sfleta_NAN) {
        res = sfleta_NAN;
    } else {
        double x_f = sfleta_fmod(x, (2 * sfleta_PI));
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

long double sfleta_tan(double x) {
    x = sfleta_sin(x) / sfleta_cos(x);
    return x;
}
