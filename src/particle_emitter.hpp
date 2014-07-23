#ifndef PARTICLE_EMITTER_H_
#define PARTICLE_EMITTER_H_

#include "particle.hpp"

class Particle_Emitter
{
private:
    Particle            particles[];
    unsigned int        particle_cap;
    unsigned int        alive_particles;
    bool                alive;

public:
    /*************************************
    * Constructor order:
    * Texture for particles, particle cap,
    * and the x & y coordinates of emitter.
    *************************************/
    /*ctr*/             Particle_Emitter(SDL_Texture*);
                        Particle_Emitter(SDL_Texture*, int)
                        Particle_Emitter(SDL_Texture*, int, int, int);

    /*dtr*/             ~Particle_Emitter();
};

#endif
