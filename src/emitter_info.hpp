#ifndef EMITTER_INFO_H_
#define EMITTER_INFO_H_

#include <stdlib.h>

#include <SDL2/SDL.h>
#include "vector2d.hpp"
/*********************************
* TODO:
*  -Add variance for things like:
*   *spawn_time
*   *movement_angle (acceleration variance)
*   *Ability to be affected by gravity
*********************************/
class Emitter_Info
{
private:
    SDL_Texture*        particle_texture;

    Vector2D            acceleration;
    Vector2D            velocity;
    Vector2D            initial_position;

    SDL_Color           start_color;
    SDL_Color           end_color;

    float               life_span;
    float               velocity_cap;

    float               start_size;
    float               end_size;

    float               x_variance;
    float               y_variance;
public:
    /*ctr*/             Emitter_Info();
    /************************************
    * Constructor order:
    *   image, accel_x, accel_y, vel_x,
    *   vel_y, pos_x, pos_y, start_color,
    *   end_color, life_span, vel_cap,
    *   start_size, end_size
    ************************************/
                        Emitter_Info(SDL_Texture*, float, float,
                                     float, float, float, float,
                                     SDL_Color&, SDL_Color&,
                                     float, float, float, float);
    /*dtr*/             ~Emitter_Info();

    SDL_Texture*        get_texture();
    Vector2D            get_acceleration();
    Vector2D            get_velocity();
    Vector2D            get_initial_position();
    SDL_Color           get_start_color();
    SDL_Color           get_end_color();
    float               get_life_span();
    float               get_velocity_cap();
    float               get_start_size();
    float               get_end_size();
    float               get_x_variance();
    float               get_y_variance();

    void                set_acceleration(float, float);
    void                set_velocity(float, float);
    void                set_initial_position(float, float);
    void                set_particle_texture(SDL_Texture*);
    void                set_start_color(unsigned int, unsigned int, unsigned int, unsigned int);
    void                set_end_color(unsigned int, unsigned int, unsigned int, unsigned int);
    void                set_life_span(float);
    void                set_velocity_cap(float);
    void                set_start_size(float);
    void                set_end_size(float);
    void                set_variance(float, float);
};
#endif
