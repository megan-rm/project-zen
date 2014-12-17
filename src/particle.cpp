#include "particle.hpp"
#include <iostream>

Particle::Particle(Emitter_Info& em_info)
        : Entity(em_info.get_texture())
{
    emitter_info = &em_info;
    alive = true;
    acceleration = emitter_info->get_acceleration();
    /// TODO acceleration.set(float degrees);
    acceleration.set_x(acceleration.get_x() /*+ emitter_info->get_angle_variance()*/);
    acceleration.set_y(acceleration.get_y() /*+ emitter_info->get_angle_variance()*/);

    velocity = emitter_info->get_velocity();
    position = emitter_info->get_initial_position();

    color = emitter_info->get_start_color();

    life_span = emitter_info->get_life_span();

    velocity_cap = emitter_info->get_velocity_cap();

    particle_scale = emitter_info->get_start_size();

    spawn_time = SDL_GetTicks();
};

Particle::~Particle()
{
}

void Particle::kill()
{
    alive = false;
};


/// TODO: This is relatively slow. Maybe we don't have to do much of this?
void Particle::revive()
{
    alive = true;
    acceleration = emitter_info->get_acceleration();
    /// TODO acceleration.set(float degrees);
    acceleration.set_x(acceleration.get_x() /*+ emitter_info->get_angle_variance()*/);
    acceleration.set_y(acceleration.get_y() /*+ emitter_info->get_angle_variance()*/);

    velocity = emitter_info->get_velocity();
    position = emitter_info->get_initial_position();

    color = emitter_info->get_start_color();

    life_span = emitter_info->get_life_span();

    /// probably don't need this
    velocity_cap = emitter_info->get_velocity_cap();

    particle_scale = emitter_info->get_start_size();

    spawn_time = SDL_GetTicks();
};

void Particle::lerp_size(float life_percent)
{
    /**********************
    * This was probably slowing us down more than helping us.
    * Only lerp if they're different?
    ***********************
    if(emitter_info->get_start_size() == emitter_info->get_end_size())
        return;
    */

    particle_scale =
    (emitter_info->get_start_size() + ((emitter_info->get_end_size() - emitter_info->get_start_size()) * life_percent));

    this->scale(particle_scale);
    return;
};

/// TODO: overload SDL_Color + and SDL_Color -   this will lower function calls, I hope, by 3/4
void Particle::lerp_colors(float life_percent)
{
    color.r =
    (emitter_info->get_start_color().r + ((emitter_info->get_end_color().r - emitter_info->get_start_color().r) * life_percent));

    color.g =
    (emitter_info->get_start_color().g + ((emitter_info->get_end_color().g - emitter_info->get_start_color().g) * life_percent));

    color.b =
    (emitter_info->get_start_color().b + ((emitter_info->get_end_color().b - emitter_info->get_start_color().b) * life_percent));

    color.a =
    (emitter_info->get_start_color().a + ((emitter_info->get_end_color().a - emitter_info->get_start_color().a) * life_percent));

    set_alpha(color.a);
};

/// TODO: This takes wayyy too long.
void Particle::update(float dt)
{
    float time_alive = SDL_GetTicks() - spawn_time;
    float life_percent = time_alive / life_span;

    lerp_size(life_percent);
    lerp_colors(life_percent);

    ///center_on_rect();

    /// TODO: fix delta time updating
    velocity = (velocity + acceleration) * dt;
    if (velocity.get_x() > velocity_cap.get_x())
        velocity.set_x(velocity_cap.get_x());
    if (velocity.get_y() > velocity_cap.get_y())
        velocity.set_y(velocity_cap.get_y());

    position = position + velocity;
    move(position.get_x(), position.get_y());


    /************************************
    * Debugging.
    ************************************/

    if(time_alive >= life_span)
        kill();
}
