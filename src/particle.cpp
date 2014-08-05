#include "particle.hpp"

Particle::Particle(Emitter_Info& emitter_info)
        : Entity(emitter_info.get_texture())
{
    alive = true;
    acceleration = emitter_info.get_acceleration();
    velocity = emitter_info.get_velocity();
    initial_position = emitter_info.get_initial_position();
    start_color = emitter_info.get_start_color();
    end_color = emitter_info.get_end_color();

    life_span = SDL_GetTicks() + emitter_info.get_life_span();

    velocity_cap = emitter_info.get_velocity_cap();
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

    ///DEBUG///
    acceleration.set(0.004, 0.02);
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
    * In the future, Kill the particle.
    ************************************/
    if(position_rect.x >= 650)
        move(-10.0, position.get_y());
    if(position_rect.y >= 490)
        move(position.get_x(), -10.0);

    if(SDL_GetTicks() >= life_span)
        kill_particle();
}
