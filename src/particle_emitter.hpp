#ifndef PARTICLE_EMITTER_H_
#define PARTICLE_EMITTER_H_

#include <vector>

#include "particle.hpp"
#include "entity.hpp"
#include "vector2d.hpp"

class Particle_Emitter : public Entity
{
private:
    std::vector
        <Particle*>     particles;
    SDL_Texture*        particle_texture;
    Entity*             attached_entity;

    /**Position for emitter**/
    Vector2D            position;

    /**Data for particles**/
    Vector2D            acceleration;
    Vector2D            velocity;

    /**
    * Emitters can be a Point or a Rectangle
    **/
    enum                emitter_shape{Point, Rectangle, Circle};

    emitter_shape       emitter_type;
    SDL_Rect            rect_emitter;

    unsigned int        max_particles;

    float               interval;
    float               velocity_cap;
    bool                alive;

    float               particle_life_span;

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

    void                setup(float, float, float, float, float, float);
    void                attach_to_entity(Entity*);

    void                set_shape(emitter_shape);
    void                set_rect(SDL_Rect&);
    void                update();
    void                draw(){};
};

#endif
