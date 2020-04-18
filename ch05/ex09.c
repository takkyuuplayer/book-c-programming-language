// Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.
// Kernighan, Brian W.. C Programming Language (p. 114). Pearson Education. Kindle Edition.

#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int month, int *pmonth, int *pday);

int main(int argc, char const *argv[])
{
    printf("%d\n", day_of_year(1987, 7, 15));
    int pmonth, pday;
    month_day(1987, day_of_year(1987, 7, 15), &pmonth, &pday);
    printf("%d, %d\n", pmonth, pday);
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++)
    {
        day += *((*daytab + leap) + i);
    }
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; yearday > *((*daytab + leap) + i); i++)
    {
        yearday -= *((*daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yearday;
}