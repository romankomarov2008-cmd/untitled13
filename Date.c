#include <stdio.h>
#include <stdbool.h>
#include "Date.h"

const int DAY_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *WEEK_DAYS[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return DAY_MONTH[month - 1];
}

void printDate(Date d) {
    printf("%d/%d/%d", d.year, d.month, d.day);
}

bool inputDate(Date* d) {
    printf("\n Input day, month, and year: ");
    int r1 = scanf("%d", &d -> year);
    if (r1 != 1) return false;
    int r2 = scanf("%d", &d -> month);
    if (r2 != 1) return false;
    int r3 = scanf("%d", &d -> day);
    if (r3 != 1) return false;
    if (d->month < 1 || d->month > 12) return false;
    if (d -> day < 1 || d -> day > getDaysInMonth(d->month, d->year)) return false;

    return true;

}

Date tomorrow(Date d) {
    Date result = d;
    int last_day_month = getDaysInMonth(d.month, d.year);
    if (d.day < last_day_month) {
        result.day++;
        return result;
    }
    result.day = 1;
    if (d.month < 12) {
        result.month++;
        return result;
    }
    result.year++;
    result.month = 1;

    return result;
}

Date yesterday(Date d) {
    Date result = d;

    if (d.day > 1) {
        result.day--;
        return result;
    }

    if (d.month == 1) {
        result.year--;
        result.month = 12;
        result.day = getDaysInMonth(12, result.year);
        return result;
    }

    result.month--;
    result.day = getDaysInMonth(result.month, result.year);
    return result;
}

int day_week(Date d) {
    int s = 0;
    for (int i = 0; i < d.month - 1; i++) {
        s += getDaysInMonth(i + 1, d.year);
    }
    s += d.day;
    return s % 7;
}
