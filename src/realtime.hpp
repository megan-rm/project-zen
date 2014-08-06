#ifndef REALTIME_H_
#define REALTIME_H_

#include <time.h>


/*******************************
* TODO:
*  -keep track of daylight, moon,
*   and sun(maybe?)
*  -use epoch time for daytime,
*   like hours, minutes, seconds
*******************************/

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

    ///char?
    unsigned short      morning_time;
    unsigned short      noon_time;
    unsigned short      evening_time;
    unsigned short      night_time;

    enum                daylight{Morning, Noon, Afternoon, Evening, Night};
    daylight            time_of_day;

public:
    /*ctr*/             Realtime();
    /*dtr*/             ~Realtime();
    void                update();

    /// char?
    unsigned short      get_hour();
    unsigned short      get_minute();
    unsigned short      get_second();
    unsigned short      get_day_of_week();
    unsigned short      get_month();
    unsigned short      get_day_of_month();
    unsigned short      get_morning_time();
    unsigned short      get_noon_time();
    unsigned short      get_evening_time();
    unsigned short      get_night_time();
};
#endif
