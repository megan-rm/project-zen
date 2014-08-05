#include "particle_emitter.hpp"
#include <algorithm>


void Particle_Emitter::ctr_helper(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    emitter_info.set_particle_texture(p_texture);
    max_particles = p_cap;

    position.set(pos_x, pos_y);

    alive = false;
    particle_life_span = 0.0;

    velocity_cap = 0.0;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
                 : Entity(NULL)
{
    ctr_helper(p_texture, 0, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap)
                 : Entity(NULL)
{
    ctr_helper(p_texture, p_cap, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
                 : Entity(NULL)
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
    particles.push_back(new Particle(emitter_info));
};

void Particle_Emitter::attach_to_entity(Entity* n_entity)
{
    if(n_entity)
        attached_entity = &(*n_entity); /// need to check validity every tick
};

void Particle_Emitter::update()
{
    std::vector<Particle*>::iterator iter;
    for(int i = 0; i < particles.size(); i++)
    {
        particles.at(i)->update();
        /// check to see if current particle should be killed
        if(!(*iter)->is_alive())
        {
            std::swap(particles.at(i), particles.back());
            particles.pop_back();
        }
    }
}

