#include "realtime.h"

Realtime::Realtime()
{
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

unsigned int Realtime::get_day_of_month()
{
    return day_of_month;
};

unsigned int Realtime::get_day_of_week()
{
    return day_of_week;
};

unsigned int Realtime::get_hour()
{
    return hour;
};

unsigned int Realtime::get_minute()
{
    return minute;
};

unsigned int Realtime::get_second()
{
    return second;
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
