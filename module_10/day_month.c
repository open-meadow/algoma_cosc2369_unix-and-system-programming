#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_of_day(int year, int yearday, int *pmonth, int *pday);

static int daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int main() {
    int month, day;
    int year = 2024;
    int yearday = 74;
    
    int doy = day_of_year(year, 3, 15);
    printf("Day of year for March 15: %d\n", doy);
    
    month_of_day(year, yearday, &month, &day);
    printf("Day of year for day %d: %d/%d\n", yearday, month, day);
    
    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;
    int *p;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    
    for(i = 1; i < month; i++)
        day += *(p + i);
}

void month_of_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    int *p;
    
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = daytab[leap];
    
    for (i = 1; yearday > *(p + i); i++) {
        yearday -= *(p + i);
    }
    *pmonth = i;
    *pday = yearday;
    
}