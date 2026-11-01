#ifndef DATE_H
#define DATE_H

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

extern bool isLeapYear(int year);
extern int getDaysInMonth(int month, int year);
extern void printDate(Date d);
extern bool inputDate(Date *d);
extern Date tomorrow(Date d);
extern Date yesterday(Date d);
extern int day_week(Date d);

#endif