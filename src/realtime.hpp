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

    unsigned char       hour;
    unsigned char       minute;
    unsigned char       second;
    unsigned char       day_of_week;
    unsigned char       month;
    unsigned char       day_of_month;

    ///char?
    unsigned char       morning_time;
    unsigned char       noon_time;
    unsigned char       evening_time;
    unsigned char       night_time;

    enum                daylight{Morning, Noon, Afternoon, Evening, Night};
    daylight            time_of_day;

public:
    /*ctr*/             Realtime();
    /*dtr*/             ~Realtime();
    void                update();

    /// char?
    unsigned char       get_hour();
    unsigned char       get_minute();
    unsigned char       get_second();
    unsigned char       get_day_of_week();
    unsigned char       get_month();
    unsigned char       get_day_of_month();
    unsigned char       get_morning_time();
    unsigned char       get_noon_time();
    unsigned char       get_evening_time();
    unsigned char       get_night_time();
};
#endif
