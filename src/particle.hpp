#ifndef PARTICLE_H_
#define PARTICLE_H_

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
    float           life_span;      /// Milliseconds
    float           velocity_cap;

    float           particle_scale;

    bool            alive;

public:
    /*ctr*/         Particle(Emitter_Info&);


    /*dtr*/         ~Particle();

    /// probably unneeded
    void            kill_particle();

    void            update(); /// need to push delta time into.
    bool            is_alive();
};

#endif
