#include <iostream>
#include <cmath>
#include <cassert>
#include <cfloat> 

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    return fmod(hours, 24.0);
}

int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    return fmod(time - utc_offset, 24.0);
}

double time_from_utc(int utc_offset, double time)
{
    return fmod(time + utc_offset, 24.0);
}

void main()
{
    // Проверка функции seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    assert(fabs(seconds_difference(3600.0, 7200.0) - 3600.0) < DBL_EPSILON);

    // Проверка функции hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);

    // Проверка функции to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_float_hours(2, 30, 0) - 2.5) < DBL_EPSILON);


    // Проверка функции to_24_hour_clock
    assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);

    // Проверка функций get_hours, get_minutes и get_seconds
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    // Проверка функций time_to_utc и time_from_utc
    assert(fabs(time_to_utc(3, 12.5) - 9.5) < DBL_EPSILON);
    assert(fabs(time_to_utc(-5, 17.5) - 22.5) < DBL_EPSILON);
    assert(fabs(time_from_utc(3, 9.5) - 12.5) < DBL_EPSILON);
    assert(fabs(time_from_utc(-5, 22.5) - 17.5) < DBL_EPSILON);

}
