#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "SDL2/SDL.h"

#include "entity.hpp"
#include "vector2d.hpp"

class Particle : public Entity
{
private:
    float           life_span;  /// Milliseconds
    float           time_alive; /// Milliseconds
    float           velocity_cap;
    Vector2D        acceleration;
    Vector2D        velocity;
    Vector2D        initial_position;

    bool            alive;

    SDL_Color       start_color;
    SDL_Color       end_color;

public:
    /********************************************************
    * Constructor order:
    * alive, life_span, accel_x, accel_y, vel_x, vel_y,
    * vel_cap
    ********************************************************/
    /*ctr*/         Particle(SDL_Texture*);
                    Particle(SDL_Texture*, bool, float);
                    Particle(SDL_Texture*, bool, float, float, float);
                    Particle(SDL_Texture*, bool, float, float, float, float, float);
                    Particle(SDL_Texture*, bool, float, float, float, float, float, float);

    /*dtr*/         ~Particle();
    void            kill_particle();
    void            revive_particle();
    void            revive_particle(float, float);
    void            revive_particle(float, float, float, float);
    void            revive_particle(float, float, float, float, float);
    void            set_initial_position(float, float);

    bool            is_alive();
};

#endif
