#ifndef PARTICLE_EMITTER_H_
#define PARTICLE_EMITTER_H_

#include <vector>

#include "particle.hpp"
#include "entity.hpp"
#include "vector2d.hpp"
#include "emitter_info.hpp"

/*************************************
* TODO:
*  -attached_entity could probably be
*   part of entity. (chain links, like
*   the chomp-chomp in Mario, etc)
*  -Maybe constructor for default entity
*   to attach to.
*  -Burst emission; like fireworks.
*************************************/

class Particle_Emitter : public Entity
{
private:
    std::vector
        <Particle*>     particles;
    Entity*             attached_entity;
    SDL_Point           attached_point;
    /**Data for particles**/
    Emitter_Info        emitter_info;

    SDL_Rect            rect_emitter;
    unsigned int        max_particles;
    unsigned int        alive_particles;
    unsigned int        interval;
    unsigned int        next_spawn;

    float               velocity_cap;

    void                ctr_helper(SDL_Texture* image, int max_particles, int x_position, int y_position);

public:
    /*ctr*/             Particle_Emitter(SDL_Texture* image);
                        Particle_Emitter(SDL_Texture* image, int max_particles);
                        Particle_Emitter(SDL_Texture* image, int max_particles,
                                         int x_postion, int y_position);

    /*dtr*/             ~Particle_Emitter();

    void                create_particle();

    enum                emitter_shape{POINT, RECTANGLE, CIRCLE};
    enum                emitter_type{BURST, SPREAD};

    bool                is_attached;
    emitter_shape       shape;
    emitter_type        type;

    /*********************************
    * Use this to initialize particle
    * emission info.
    * TODO:
    *  -Make this way more pretty...
    *********************************/
    Emitter_Info* const get_info();

    void                attach_to_entity(Entity& entity,
                                         unsigned int x,
                                         unsigned int y);

    void                set_shape(emitter_shape shape);
    void                set_rect(unsigned int width, unsigned int height);
    void                set_interval(unsigned int milliseconds);
    void                update(float dt);
    void                draw(SDL_Renderer* game_renderer);
};

#endif
