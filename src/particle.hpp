#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>

#include "SDL2/SDL.h"

#include "entity.hpp"
#include "vector2d.hpp"
#include "emitter_info.hpp"

/******************************
* TODO:
* See how much we can pull out
* of particle, and just grab
* from emitter_info.
*******************************/

class Particle : public Entity
{
private:
    Vector2D        acceleration;
    Vector2D        velocity;
    Emitter_Info*   emitter_info;

    SDL_Color       color;

    /// Time is in milliseconds
    unsigned int    spawn_time;
    unsigned int    life_span;

    Vector2D        velocity_cap;

    float           particle_scale;

public:
    /*ctr*/         Particle(Emitter_Info& info);


    /*dtr*/         ~Particle();

    void            kill();
    void            revive();

    /// TODO: dt needs to go into update()
    void            update(float dt);

    void            lerp_size(float life_percent);
    void            lerp_colors(float life_percent);
};

#endif
