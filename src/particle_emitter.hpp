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

    /**Data for particles**/
    Emitter_Info        emitter_info;

    /**Emitters can be a Point or a Rectangle**/
    enum                emitter_shape{POINT, RECTANGLE, CIRCLE};
    /**Emitters can burst, like fireworks, or spread like smoke**/
    enum                emitter_type{BURST, SPREAD};

    emitter_shape       shape;
    emitter_type        type;

    SDL_Rect            rect_emitter;

    unsigned int        max_particles;

    unsigned int        interval;
    unsigned int        next_spawn;

    float               velocity_cap;

    void                ctr_helper(SDL_Texture*, int, int, int);

public:
    /*************************************
    * Constructor order:
    * Texture for particles, max particles,
    * and the x & y coordinates of emitter.
    *************************************/
    /*ctr*/             Particle_Emitter(SDL_Texture*);
                        Particle_Emitter(SDL_Texture*, int);
                        Particle_Emitter(SDL_Texture*, int, int, int);

    /*dtr*/             ~Particle_Emitter();

    void                create_particle();

    /*********************************
    * Use this to initialize particle
    * emission info.
    * TODO:
    *  -Make this way more pretty...
    *  -Probably want revive() back.
    *********************************/
    Emitter_Info* const get_info();

    void                attach_to_entity(Entity&);

    void                set_shape(emitter_shape);
    void                set_rect(unsigned int, unsigned int);
    void                set_interval(unsigned int);
    void                update();
    void                draw(SDL_Renderer*);
};

#endif
