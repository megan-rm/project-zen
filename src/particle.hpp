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

    unsigned int    spawn_time;     /// When it was birthed.
    unsigned int    life_span;      /// Milliseconds

    float           velocity_cap; /// may want Vector2D

    float           particle_scale;

public:
    /*ctr*/         Particle(Emitter_Info& info);


    /*dtr*/         ~Particle();

    /// probably unneeded
    void            kill_particle();

    void            update(); /// need to push delta time into.

    void            lerp_size(float life_percent);
    void            lerp_colors(float life_percent);
};

#endif
