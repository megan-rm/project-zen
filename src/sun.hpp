#ifndef SUN_H_
#define SUN_H_

#include "entity.hpp"
#include "realtime.hpp"

/************************************
* TODO:
*  -Sun Rays (use emitter?)
*  -Sun controls time_of_day in
*   Realtime.hpp
*  -Sun should also control how light
*   it is outside (influenced by clouds?)
*  -Should be able to affect temperature?
************************************/
class Sun : public Entity
{
private:
    SDL_Point       movement_center;
    Realtime*       time;
    unsigned int    sun_rise_h, sun_rise_m;
    unsigned int    sun_set_h, sun_set_m;

    bool            visible;
public:
    /*ctr*/         Sun(SDL_Texture* image, Realtime& current_time);
    /*dtr*/         ~Sun();


    void            init(int x_position, int y_position);

    void            update();
};

#endif
