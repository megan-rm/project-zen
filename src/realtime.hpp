#ifndef REALTIME_H_
#define REALTIME_H_

#include <time.h>

class Realtime
{
private:
    time_t              game_time;
    struct tm*          time_info;

    unsigned short      hour;
    unsigned short      minute;
    unsigned short      second;
    unsigned short      day_of_week;
    unsigned short      month;
    unsigned short      day_of_month;

    unsigned short      morning_time;
    unsigned short      evening_time;
    unsigned short      night_time;

    enum                daylight{Morning, Noon, Afternoon, Evening, Night};
    daylight            time_of_day;

public:
    /*ctr*/             Realtime();
    /*dtr*/             ~Realtime();
    void                update();

    unsigned int        get_hour();
    unsigned int        get_minute();
    unsigned int        get_second();
    unsigned int        get_day_of_week();
    unsigned int        get_month();
    unsigned int        get_day_of_month();
};
#endif
