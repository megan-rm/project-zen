#include "emitter_info.hpp"

Emitter_Info::Emitter_Info()
{
    particle_texture = NULL;
    acceleration.set(0.0, 0.0);
    x_variance = 0.0;
    y_variance = 0.0;

    velocity.set(0.0, 0.0);

    /// No Color Change
    start_color.r = start_color.g = start_color.b = 255;
    start_color.a = 255;

    end_color.r = end_color.g = end_color.b = 255;
    end_color.a = 255;

    life_span = 0.0;
    velocity_cap = 0.0;

    /// No size change
    start_size = 1.0;
    end_size = 1.0;
};

/// This needs to be cleaned up, I think.
Emitter_Info::Emitter_Info(SDL_Texture* p_texture, float accel_x, float accel_y,
             float vel_x, float vel_y, float pos_x, float pos_y, SDL_Color& s_color,
             SDL_Color& e_color, float life, float vel_cap, float s_size, float e_size)
{
    particle_texture = p_texture;
    acceleration.set(accel_x, accel_y);
    velocity.set(vel_x, vel_y);
    initial_position.set(pos_x, pos_y);

    start_color = s_color;
    end_color = e_color;

    life_span = life;
    velocity_cap = vel_cap;

    start_size = s_size;
    end_size = e_size;
};

Emitter_Info::~Emitter_Info()
{
    particle_texture = NULL;
};

SDL_Texture* Emitter_Info::get_texture()
{
    return particle_texture;
};

Vector2D Emitter_Info::get_acceleration()
{
    return acceleration;
};

Vector2D Emitter_Info::get_velocity()
{
    return velocity;
};

Vector2D Emitter_Info::get_initial_position()
{
    return initial_position;
};

SDL_Color Emitter_Info::get_start_color()
{
    return start_color;
};

SDL_Color Emitter_Info::get_end_color()
{
    return end_color;
};

float Emitter_Info::get_life_span()
{
    return life_span;
};

float Emitter_Info::get_velocity_cap()
{
    return velocity_cap;
};

float Emitter_Info::get_start_size()
{
    return start_size;
};

float Emitter_Info::get_end_size()
{
    return end_size;
};

float Emitter_Info::get_x_variance()
{
    if(x_variance <= 0)
        return 0.0;
    float temp_variance = x_variance * 10000;
    float proper_variance = rand() % 10000 - temp_variance;
    temp_variance = proper_variance / 100000;
    return temp_variance;
};

float Emitter_Info::get_y_variance()
{
    if(y_variance <= 0)
        return 0.0;
    float temp_variance = y_variance * 1000;
    float proper_variance = rand() % 1000 - temp_variance;
    temp_variance = proper_variance / 1000;

    unsigned int sign = rand() % 2;
    if(sign == 0) temp_variance*=-1;

    return temp_variance;
};

void Emitter_Info::set_acceleration(float accel_x, float accel_y)
{
    acceleration.set(accel_x, accel_y);
};

void Emitter_Info::set_velocity(float vel_x, float vel_y)
{
    velocity.set(vel_x, vel_y);
};

void Emitter_Info::set_initial_position(float x_pos, float y_pos)
{
    initial_position.set(x_pos, y_pos);
};

void Emitter_Info::set_particle_texture(SDL_Texture* p_texture)
{
    particle_texture = p_texture;
};

void Emitter_Info::set_start_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    start_color.r = r;
    start_color.g = g;
    start_color.b = b;
    start_color.a = a;
};

void Emitter_Info::set_end_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    end_color.r = r;
    end_color.g = g;
    end_color.b = b;
    end_color.a = a;
};

void Emitter_Info::set_life_span(float life)
{
    life_span = life;
};

void Emitter_Info::set_velocity_cap(float vel_cap)
{
    velocity_cap = vel_cap;
};

void Emitter_Info::set_start_size(float scale)
{
    start_size = scale;
};

void Emitter_Info::set_end_size(float scale)
{
    end_size = scale;
};

void Emitter_Info::set_variance(float x_val, float y_val)
{
    x_variance = x_val;
    y_variance = y_val;
};
