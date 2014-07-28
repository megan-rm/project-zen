#ifndef PARTICLE_EMITTER_H_
#define PARTICLE_EMITTER_H_

#include <vector>

#include "particle.hpp"
#include "entity.hpp"
#include "mobile_vector.hpp"
#include "vector2d.hpp"

class Particle_Emitter
{
private:
    std::vector
        <Particle*>    particles;
    SDL_Texture*        particle_texture;

    Entity*             attached_entity;

    Vector2D            acceleration;
    Vector2D            velocity;

    unsigned int        max_particles;
    unsigned int        alive_particles;

    float               interval;
    float               velocity_cap;
    bool                alive;

    float               position_x;
    float               position_y;

    float               particle_life_span;

    void                ctr_helper(SDL_Texture*, int, int, int);

public:
    /*************************************
    * Constructor order:
    * Texture for particles, particle cap,
    * and the x & y coordinates of emitter.
    *************************************/
    /*ctr*/             Particle_Emitter(SDL_Texture*);
                        Particle_Emitter(SDL_Texture*, int);
                        Particle_Emitter(SDL_Texture*, int, int, int);

    /*dtr*/             ~Particle_Emitter();

    void                create_particle();

    void                setup(float, float, float, float, float, float);
    void                attach_to_entity(Entity*);

};

#endif
