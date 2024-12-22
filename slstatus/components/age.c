/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

#define YEAR 31557600.0

const char *
age_cal(const char *birth)
{
    static char age_buf[16];
    int year, month, day;
    sscanf(birth, "%4d%2d%2d", &year, &month, &day);
    struct tm birth_time = {0};
    birth_time.tm_year = year - 1900;
    birth_time.tm_mon = month - 1;
    birth_time.tm_mday = day;

    time_t birth_timestamp = mktime(&birth_time);

    time_t current_timestamp = time(NULL);

    double seconds_difference = difftime(current_timestamp, birth_timestamp);

    double super_age  = seconds_difference/YEAR;

    //return snprintf(age_buf, sizeof(age_buf), "%.4lf", super_age);
    snprintf(age_buf, sizeof(age_buf), "%.8lf", super_age);
    return age_buf;
}
