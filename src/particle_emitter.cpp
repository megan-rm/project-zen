#include "particle_emitter.hpp"

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
{
    particle_texture = p_texture;

    alive = false;

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
        if(particles[i] && particles[i]->is_alive() == false)
        {
            return i;
        }
    }
    return -1;
};

Particle* Particle_Emitter::create_particle()
{
    int new_location = this->make_new_particle();
    if(new_location)
    {
        particles[new_location]->revive_particle();
    };
};

void attach_to_entity(Entity*);
