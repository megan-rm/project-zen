#include "particle_emitter.hpp"

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
{
    particle_texture = p_texture;

    alive = false;

    particle_life_span = 0.0;

    position_x = 0;
    position_y = 0;

    max_particles = 0;
    alive_particles = 0;

    for(int i = 0; i < max_particles; i++)
        particles[i] = NULL;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap)
{
    particle_texture = p_texture;

    alive = false;

    particle_life_span = 0.0;

    position_x = 0;
    position_y = 0;

    max_particles = p_cap;
    alive_particles = 0;

    for(int i = 0; i < max_particles; i++)
        particles[i] = NULL;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    particle_texture = p_texture;

    alive = false;

    particle_life_span = 0.0;

    position_x = pos_x;
    position_y = pos_y;

    max_particles = p_cap;
    alive_particles = 0;

    for(int i = 0; i < max_particles; i++)
        particles[i] = NULL;
};

Particle_Emitter::~Particle_Emitter()
{
    delete[] particles;

    for(int i = 0; i < max_particles; i++)
        particles[i] = NULL;
};


int Particle_Emitter::make_new_particle()
{
    for(int i = 0; i < max_particles; i++)
    {
        if(particles[i] == NULL)
            return i;
        else if(particles[i] && particles[i]->is_alive() == false)
        {
            return i;
        }
    }
    return -1; /// there was no open spot in the particle array
};

Particle* Particle_Emitter::create_particle()
{
    int new_location = this->make_new_particle();
    /**
    * This is extremely ugly. Fix this mess.
    **/
    if( new_location > 0 && particles[new_location] != NULL ) /// Reviving
    {
        particles[new_location]->revive_particle(
            particle_movement_info.get_x_acceleration(), particle_movement_info.get_y_acceleration(),
            particle_movement_info.get_x_velocity(), particle_movement_info.get_y_velocity(),
            particle_movement_info.get_acceleration_cap(), particle_movement_info.get_velocity_cap());
    }
    else if( new_location > 0 && particles[new_location] == NULL ) /// creating
    {
        particles[new_location] = new Particle(
            particle_texture, alive, particle_life_span,
            particle_movement_info.get_x_acceleration(), particle_movement_info.get_y_acceleration(),
            particle_movement_info.get_x_velocity(), particle_movement_info.get_y_velocity(),
            particle_movement_info.get_acceleration_cap(), particle_movement_info.get_velocity_cap());
    }
};

void attach_to_entity(Entity*)
{

};
