#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "SDL2/SDL.h"

#include "entity.hpp"
#include "mobile_vector.hpp"

class Particle : public Entity
{
private:
    float           life_span;
    Mobile_Vector   movement;
    bool            alive;
    float           initial_x;
    float           initial_y;

public:
    /********************************************************
    * Constructor order:
    * alive, life_span, accel_x, accel_y, vel_x, vel_y,
    * accel_cap, vel_cap
    ********************************************************/
    /*ctr*/         Particle(SDL_Texture*);
                    Particle(SDL_Texture*, bool, float);
                    Particle(SDL_Texture*, bool, float, float, float);
                    Particle(SDL_Texture*, bool, float, float, float, float, float);
                    Particle(SDL_Texture*, bool, float, float, float, float, float, float, float);

    /*dtr*/         ~Particle();
    void            kill_particle();
    void            revive_particle();
    void            revive_particle(float, float);
    void            revive_particle(float, float, float, float);
    void            revive_particle(float, float, float, float, float, float);
    void            set_initial_position(float, float);

    //void            draw(SDL_Renderer*);
};

#endif
