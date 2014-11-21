#include "particle_emitter.hpp"
#include <algorithm>
#include <iostream>

void Particle_Emitter::ctr_helper(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    emitter_info.set_particle_texture(p_texture);
    emitter_info.set_initial_position(pos_x, pos_y);
    emitter_info.set_life_span(0);

    max_particles = p_cap;
    particles.reserve(max_particles);


    position.set(pos_x, pos_y);

    rect_emitter.x = pos_x;
    rect_emitter.y = pos_y;

    alive = true;
    is_attached = false;
    velocity_cap = 0.0;

    shape = POINT;
    type = SPREAD;

    /// DEBUG
    interval = 0;
    next_spawn = 0;

    attached_entity = NULL;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
                 : Entity(p_texture)
{
    ctr_helper(p_texture, 0, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap)
                 : Entity(p_texture)
{
    ctr_helper(p_texture, p_cap, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
                 : Entity(p_texture)
{
    ctr_helper(p_texture, p_cap, pos_x, pos_y);
};

Particle_Emitter::~Particle_Emitter()
{
    for(unsigned int i = 0; i < particles.size(); i++)
      delete particles.at(i);

    particles.clear();

    attached_entity = NULL;
};

void Particle_Emitter::create_particle()
{
    next_spawn = SDL_GetTicks() + interval;
    particles.push_back(new Particle(emitter_info));
};

void Particle_Emitter::attach_to_entity(Entity& n_entity,
                                        unsigned int relative_x, unsigned int relative_y)
{
    if(&n_entity)
    {
        attached_entity = &n_entity; /// need to check validity every tick
        attached_point.x = relative_x;
        attached_point.y = relative_y;
        emitter_info.set_initial_position(n_entity.position.get_x() + relative_x,
                                          n_entity.position.get_y() + relative_y);
    }
};

void Particle_Emitter::update()
{
    if(alive == false)
        return;

    if(attached_entity != NULL)
    {
        if (shape == RECTANGLE)
        {
            rect_emitter.x = attached_entity->position.get_x() + attached_point.x;
            rect_emitter.y = attached_entity->position.get_y() + attached_point.y;
        }
        else if (shape == POINT)
        {
            position.set(attached_entity->position.get_x() + attached_point.x,
                         attached_entity->position.get_y() + attached_point.y);
        }
    }
    /******************************************************
    * We may not want to kill emitters attached to their
    * entities, immediately (smoke from fire, explosions,
    * etc)
    *******************************************************/
    else if (attached_entity == NULL && is_attached == true)
    {
        alive = false;
        return;
    }
    else /// Not Attached to anything
    {
        if(shape == RECTANGLE)
        {
            rect_emitter.x = position.get_x();
            rect_emitter.y = position.get_y();
        }
    }

    /// rect spawn-zone
    if(shape == RECTANGLE)
    {
        float nx, ny;
        nx = rand() % rect_emitter.w + position.get_x();
        ny = rand() % rect_emitter.h + position.get_y();

        emitter_info.set_initial_position(nx, ny);
    }
    else if(shape == POINT)
    {
        emitter_info.set_initial_position(position.get_x(), position.get_y());
    }
    /// create new particles
    if( (particles.size() < max_particles)
       &&(next_spawn < SDL_GetTicks()))
    {
        create_particle();
    }

    /// update existing particles
    for(unsigned int i = 0; i < particles.size(); i++)
    {
        particles.at(i)->update();
        /// check to see if current particle should be killed
        if(!particles.at(i)->is_alive())
        {
            delete particles.at(i);
            std::swap(particles.at(i), particles.back());
            particles.pop_back();
            i--; /// because we need to check the previous back() particle
        }
    }
};

void Particle_Emitter::draw(SDL_Renderer* game_renderer)
{
    for (unsigned int i = 0; i < particles.size(); i++)
    {
        particles.at(i)->draw(game_renderer);
    }
};

void Particle_Emitter::set_shape(emitter_shape new_shape)
{
    shape = new_shape;
};

void Particle_Emitter::set_rect(unsigned int width, unsigned int height)
{
    rect_emitter.w = width;
    rect_emitter.h = height;
    rect_emitter.x = position.get_x();
    rect_emitter.y = position.get_y();
};

void Particle_Emitter::set_interval(unsigned int milliseconds) /// i_rate? that's perfect. ha.
{
    interval = milliseconds; /// it needs to calm down.
};

Emitter_Info* const Particle_Emitter::get_info()
{
    return &emitter_info;
}
