#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational reduce(Rational r) {
    if (r.denominator == 0) {
        r.denominator = 1;
        return r;
    }

    unsigned int abs_num = abs(r.numerator);
    unsigned int common_div = gcd(r.denominator, abs_num);
    r.numerator /= (int)common_div;
    r.denominator /= common_div;
    return r;
}
