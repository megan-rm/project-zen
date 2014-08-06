#ifndef TIMER_H_
#define TIMER_H_

#include <SDL2/SDL.h>

/************************************
* TODO:
*  -Does this class serve a purpose?
************************************/

class Timer
{
private:
    int             start_tick;
    int             paused_tick;

    bool            paused;
    bool            started;

public:
    /*ctr*/         Timer();
    /*dtr*/         ~Timer();

    void            start();
    void            stop();
    void            pause();
    void            unpause();
    bool            is_started();
    bool            is_paused();
    int             get_ticks();
};
#endif
