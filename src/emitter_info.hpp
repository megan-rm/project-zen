#ifndef EMITTER_INFO_H_
#define EMITTER_INFO_H_

#include <stdlib.h>

#include <SDL2/SDL.h>
#include "vector2d.hpp"
/*********************************************
* TODO:
*   -Ability to be affected by gravity
*********************************************/
class Emitter_Info
{
private:
    SDL_Texture*        particle_texture;

    float               life_span;

    float               start_size;
    float               end_size;

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
                                     float velocity_x_cap, float velocity_y_cap,
                                     float start_size, float end_size,
                                     float angle_var);
    /*dtr*/             ~Emitter_Info();

    Vector2D            acceleration;
    Vector2D            velocity;
    Vector2D            initial_position;
    Vector2D            velocity_cap;

    SDL_Texture*        get_texture();
    Vector2D            get_acceleration();
    Vector2D            get_velocity();
    Vector2D            get_initial_position();
    Vector2D            get_velocity_cap();
    SDL_Color           start_color;
    SDL_Color           end_color;
    float               get_life_span();
    float               get_start_size();
    float               get_end_size();

    float               get_angle_variance();


    void                set_particle_texture(SDL_Texture* image);
    void                set_start_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    void                set_end_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    void                set_life_span(float life);
    void                set_start_size(float scale);
    void                set_end_size(float scale);
    void                set_variance(float degrees);
};
#endif
