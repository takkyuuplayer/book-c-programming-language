// Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.
// Kernighan, Brian W.. C Programming Language (pp. 112-113). Pearson Education. Kindle Edition.

#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int month, int *pmonth, int *pday);

int main(int argc, char const *argv[])
{
    printf("%d\n", day_of_year(1987, 12, 32));

    int month, day;
    month_day(1987, 365, &month, &day);
    printf("%d, %d\n", month, day);
    month_day(1987, 366, &month, &day);
    printf("%d, %d\n", month, day);
    month_day(1987, 400, &month, &day);
    printf("%d, %d\n", month, day);
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (month < 1 || 12 < month)
    {
        return -1;
    }
    if (day < 1 || daytab[leap][month] < day)
    {
        return -1;
    }
    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < 13 && yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    if (yearday < 1 || daytab[leap][i] < yearday)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    *pmonth = i;
    *pday = yearday;
}
