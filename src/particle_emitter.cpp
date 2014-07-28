#include "particle_emitter.hpp"

void Particle_Emitter::ctr_helper(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    particle_texture = p_texture;

    max_particles = p_cap;

    position_x = pos_x;
    position_y = pos_y;

    alive_particles = 0;
    alive = false;
    particle_life_span = 0.0;

    velocity_cap = 0.0;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
{
    ctr_helper(p_texture, 0, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap)
{
    ctr_helper(p_texture, p_cap, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    ctr_helper(p_texture, p_cap, pos_x, pos_y);
};

Particle_Emitter::~Particle_Emitter()
{
    for(int i = 0; i < particles.size(); i++)
      delete particles.at(i);

    particles.clear();
};

void Particle_Emitter::create_particle()
{
    /**
    * This is a little bit better; still needs loving.
    **/
    /// Reviving
    for(int i = 0; i < particles.size(); i++)
    {
        if( !particles.at(i)->is_alive() )
        {
            particles.at(i)->revive_particle(
            acceleration.get_x(), acceleration.get_y(),
            velocity.get_x(), velocity.get_y(),
            velocity_cap);
        }
    }
    /// Create new particle
    particles.push_back(new Particle(
        particle_texture, alive, particle_life_span,
        acceleration.get_x(), acceleration.get_y(),
        velocity.get_x(), velocity.get_y(),
        velocity_cap));
};

void attach_to_entity(Entity*)
{

};
