#include "particle.hpp"

Particle::Particle(SDL_Texture* particle_texture)
        : Entity(particle_texture)
{
    alive = false;
    life_span = 0.0;
    initial_position.set(0,0);
    velocity_cap = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_position.set(0,0);
    velocity_cap = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;

    initial_position.set(0,0);

    acceleration.set(accel_x, accel_y);
    velocity_cap = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y, float vel_x, float vel_y)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_position.set(0,0);

    acceleration.set(accel_x, accel_y);

    velocity.set(vel_x, vel_y);
    velocity_cap = 0.0;
};

Particle::Particle(SDL_Texture* particle_texture, bool active, float life,
                   float accel_x, float accel_y, float vel_x, float vel_y,
                   float vel_cap)
        : Entity(particle_texture)
{
    alive = active;
    life_span = life;
    initial_position.set(0,0);

    acceleration.set(accel_x, accel_y);
    velocity.set(vel_x, vel_y);
    velocity_cap = vel_cap;
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
    move(initial_position.get_x(), initial_position.get_y());
    acceleration.set(0,0);
};

void Particle::revive_particle(float accel_x, float accel_y)
{
    alive = true;
    move(initial_position.get_x(), initial_position.get_y());

    acceleration.set_x(accel_x);
    acceleration.set_y(accel_y);

};

void Particle::revive_particle(float accel_x, float accel_y,
                               float vel_x, float vel_y)
{
    alive = true;
    move(initial_position.get_x(), initial_position.get_y());

    acceleration.set(accel_x, accel_y);
    velocity.set(vel_x, vel_y);
};

void Particle::revive_particle(float accel_x, float accel_y,
                               float vel_x, float vel_y,
                               float vel_cap)
{
    alive = true;
    move(initial_position.get_x(), initial_position.get_y());
    acceleration.set(accel_x, accel_y);
    velocity.set(vel_x, vel_y);
    velocity_cap = vel_cap;
};

void Particle::set_initial_position(float init_x, float init_y)
{
    initial_position.set(init_x, init_y);
};

bool Particle::is_alive()
{
    return alive;
};
