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

    /****DEPRECTATED, REMOVE********/
    float               x_variance;
    float               y_variance;
    /******************************/

    /*******************************
    * Pretty sure I use Sine for this
    * bit...
    *******************************/
    float               angle_variance;
    float               life_variance;

    float               emission_angle;
public:
    /*ctr*/             Emitter_Info();
                        Emitter_Info(SDL_Texture* image, float x_acceleration,
                                     float y_acceleration, float x_velocity,
                                     float y_velocity, float x_position,
                                     float y_position, SDL_Color& start_color,
                                     SDL_Color& end_color, float life_span,
                                     float velocity_cap, float start_size, float end_size);
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

    void                set_acceleration(float x, float y);
    void                set_velocity(float x, float y);
    void                set_initial_position(float x, float y);
    void                set_particle_texture(SDL_Texture* image);
    void                set_start_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    void                set_end_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    void                set_life_span(float life);
    void                set_velocity_cap(float cap);
    void                set_start_size(float scale);
    void                set_end_size(float scale);
    void                set_variance(float x_angle, float y_angle);
};
#endif
