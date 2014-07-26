#ifndef PARTICLE_EMITTER_H_
#define PARTICLE_EMITTER_H_

#include "particle.hpp"
#include "entity.hpp"

class Particle_Emitter
{
private:
    Particle*           particles[];
    unsigned int        max_particles;
    unsigned int        alive_particles;
    bool                alive;

    SDL_Texture*        particle_texture;

    float               position_x;
    float               position_y;

    int                make_new_particle();

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

    Particle*           create_particle();

    void                attach_to_entity(Entity*);

};

#endif
