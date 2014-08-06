#include "realtime.hpp"

Realtime::Realtime()
{
    /// this will be more dynamic.
    morning_time = 7;
    noon_time = 11;
    evening_time = 17;
    night_time = 21;

    time(&game_time);
    time_info = localtime(&game_time);

    day_of_week = time_info->tm_wday;
    day_of_month = time_info->tm_mday;

    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;
};

Realtime::~Realtime()
{
};

unsigned short Realtime::get_day_of_month()
{
    return day_of_month;
};

unsigned short Realtime::get_day_of_week()
{
    return day_of_week;
};

unsigned short Realtime::get_hour()
{
    return hour;
};

unsigned short Realtime::get_minute()
{
    return minute;
};

unsigned short Realtime::get_second()
{
    return second;
};

unsigned short Realtime::get_morning_time()
{
    return morning_time;
};

unsigned short Realtime::get_noon_time()
{
    return noon_time;
};

unsigned short Realtime::get_evening_time()
{
    return evening_time;
};

unsigned short Realtime::get_night_time()
{
    return night_time;
};

void Realtime::update()
{
    time(&game_time);
    time_info = localtime(&game_time);

    day_of_week = time_info->tm_wday;
    day_of_month = time_info->tm_mday;

    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;
};
