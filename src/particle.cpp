#include "particle.hpp"

Particle::Particle(SDL_Texture* particle_texture)
        : Entity(particle_texture)
{
    alive = false;
    life_span = 0.0;
    initial_x = 0.0;
    initial_y = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_x = 0.0;
    initial_y = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_x = 0.0;
    initial_y = 0.0;

    movement.set_acceleration(accel_x, accel_y);
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y, float vel_x, float vel_y)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_x = 0.0;
    initial_y = 0.0;

    movement.set_acceleration(accel_x, accel_y);
    movement.set_velocity(vel_x, vel_y);
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y, float vel_x, float vel_y,
                   float accel_cap, float vel_cap)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_x = 0.0;
    initial_y = 0.0;

    movement.set_acceleration(accel_x, accel_y);
    movement.set_velocity(vel_x, vel_y);
    movement.set_acceleration_cap(accel_cap);
    movement.set_velocity_cap(vel_cap);
};

Particle::~Particle()
{
}


/************************************
* Reviving will move the particle
* back to it's last alive initial
* position. use set_intial_position
* to change particle production
* placement. 3-Ps haha. ha.
************************************/
void Particle::kill_particle()
{
    alive = false;
};

void Particle::revive_particle()
{
    alive = true;
    move(initial_x, initial_y);
};

void Particle::revive_particle(float accel_x, float accel_y)
{
    alive = true;
    move(initial_x, initial_y);

    movement.set_acceleration(accel_x, accel_y);
};

void Particle::revive_particle(float accel_x, float accel_y,
                               float vel_x, float vel_y)
{
    alive = true;
    move(initial_x, initial_y);

    movement.set_acceleration(accel_x, accel_y);
    movement.set_velocity(vel_x, vel_y);
};

void Particle::revive_particle(float accel_x, float accel_y,
                               float vel_x, float vel_y,
                               float accel_cap, float vel_cap)
{
    alive = true;
    move(initial_x, initial_y);
    movement.set_acceleration(accel_x, accel_y);
    movement.set_velocity(vel_x, vel_y);
    movement.set_acceleration_cap(accel_cap);
    movement.set_velocity_cap(vel_cap);
};

void Particle::set_initial_position(float init_x, float init_y)
{
    initial_x = init_x;
    initial_y = init_y;
};
