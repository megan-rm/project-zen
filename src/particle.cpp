#include "particle.hpp"
#include <iostream>

Particle::Particle(Emitter_Info& em_info)
        : Entity(em_info.get_texture())
{
    emitter_info = &em_info;
    alive = true;
    acceleration = emitter_info->get_acceleration();

    velocity = emitter_info->get_velocity();
    position = emitter_info->get_initial_position();

    color.r = emitter_info->get_start_color().r;
    color.g = emitter_info->get_start_color().g;
    color.b = emitter_info->get_start_color().b;
    color.a = emitter_info->get_start_color().a;

    life_span = emitter_info->get_life_span();

    velocity_cap = emitter_info->get_velocity_cap();

    particle_scale = emitter_info->get_start_size();

    spawn_time = SDL_GetTicks();
};

Particle::~Particle()
{
}

void Particle::kill_particle()
{
    alive = false;
};

bool Particle::is_alive()
{
    return alive;
};

void Particle::update()
{

    /*************************
    * TODO:
    *   -transition color
    *    based on time left
    *************************/

    unsigned int time_alive = SDL_GetTicks() - spawn_time;
    float life_percent = time_alive / life_span;

    /// FIX THESE EQUATIONS...
    /// Make an interpolation function for scale & color
    color.r += ((emitter_info->get_end_color().r - emitter_info->get_start_color().r) * life_percent);
    color.g = (emitter_info->get_end_color().g * life_percent);
    color.b = (emitter_info->get_end_color().b * life_percent);
    color.a = (emitter_info->get_end_color().a * life_percent);

    particle_scale =
    (emitter_info->get_start_size() + ((emitter_info->get_end_size() - emitter_info->get_start_size()) * life_percent));
    this->scale(particle_scale);

    center_on_rect();


    ///DEBUG///
    velocity_cap = 1.0;
    rotation += velocity.get_y();
    if(rotation > 360)
        rotation = 0;

    velocity = velocity + acceleration;
    if (velocity.get_x() > velocity_cap)
        velocity.set_x(velocity_cap);
    if (velocity.get_y() > velocity_cap)
        velocity.set_y(velocity_cap);
    position = position + velocity;
    move(position.get_x(), position.get_y());


    /************************************
    * Debugging.
    ************************************/
    if(position_rect.x >= 650)
        move(-10.0, position.get_y());
    if(position_rect.y >= 490)
        move(position.get_x(), -10.0);

    if(time_alive >= life_span)
        kill_particle();
}
