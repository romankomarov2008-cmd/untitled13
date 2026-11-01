#include <stdio.h>
#include "Date.h"

int main() {
    Date date_tests[] = {
        {2026, 10, 8},
        {2024, 7, 31},
        {2017, 12, 31},
        {2020, 2, 29}
    };

    Date date_tests_res[] =
        {
        {2026, 10, 9},
        {2024, 8, 1},
        {2018, 1, 1},
        {2020, 3, 1}
    };
    int n_tests = sizeof(date_tests)/sizeof(Date);
    for (int i=0; i<n_tests; i++) {
        printDate(date_tests[i]);
        if (tomorrow(date_tests[i]) != date_tests_res[i]) {
            printf(" test %d failed", i);
        }
    }

}
