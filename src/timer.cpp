#include "timer.hpp"

Timer::Timer()
{
    start_tick = 0;
    paused_tick = 0;

    started = false;
    paused = false;
};

Timer::~Timer()
{

};

void Timer::start()
{
    started = true;
    paused = false;
    start_tick = SDL_GetTicks();
};

void Timer::stop()
{
    started = false;
    paused = false;
};

void Timer::pause()
{
    if (is_started() && !is_paused())
    {
        paused = true;
        paused_tick = SDL_GetTicks() - start_tick;
    }
};

void Timer::unpause()
{
    if (is_paused())
    {
        paused = false;
        start_tick = SDL_GetTicks() - paused_tick;
        paused_tick = 0;
    }
};

int Timer::get_ticks()
{
    if (is_started())
    {
        if(is_paused())
            return paused_tick;
        else
            return SDL_GetTicks() - start_tick;
    }
    else
        return 0;
};

bool Timer::is_paused()
{
    return paused;
};

bool Timer::is_started()
{
    return started;
};
