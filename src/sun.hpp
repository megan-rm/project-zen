#ifndef SUN_H_
#define SUN_H_

#include "entity.hpp"
#include "realtime.hpp"

class Sun : public Entity
{
private:
    /************************************
    * TODO:
    *  -Sun Rays (use emitter?)
    *  -Sun controls time_of_day in
    *   Realtime.hpp
    ************************************/
    SDL_Point       movement_center;
    Realtime*       time;
    unsigned int    sun_rise_h, sun_rise_m;
    unsigned int    sun_set_h, sun_set_m;

    bool            visible;
public:
    /*ctr*/         Sun(SDL_Texture*, Realtime&);
    /*dtr*/         ~Sun();


    void            init(int, int);

    void            update();
};

#endif
