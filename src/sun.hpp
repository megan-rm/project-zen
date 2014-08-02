#ifndef SUN_H_
#define SUN_H_

#include "entity.hpp"
#include "realtime.hpp"

class Sun : public Entity
{
private:
    /************************************
    * TODO:
    *  -Sun Rays
    ************************************/

    bool            visible;
public:
    /*ctr*/         Sun(SDL_Texture*);
    /*dtr*/         ~Sun();

    void            init(Realtime&);

    void            update();
};

#endif
