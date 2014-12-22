#include "emitter_info.hpp"

Emitter_Info::Emitter_Info()
{
    particle_texture = nullptr;
    acceleration.set(0.0, 0.0);

    angle_variance = 0.0f;
    velocity.set(0.0, 0.0);

    /// No Color Change
    start_color.r = start_color.g = start_color.b = 255;
    start_color.a = 255;

    end_color.r = end_color.g = end_color.b = 255;
    end_color.a = 255;

    life_span = 0.0;
    velocity_cap.set(0,0);
    /// No size change
    start_size = 1.0;
    end_size = 1.0;
};

/// This needs to be cleaned up, I think.
Emitter_Info::Emitter_Info(SDL_Texture* p_texture, float accel_x, float accel_y,
             float vel_x, float vel_y, float pos_x, float pos_y, SDL_Color& s_color,
             SDL_Color& e_color, float life, float vel_x_cap, float vel_y_cap,
             float s_size, float e_size, float angle_var)
{
    particle_texture = p_texture;
    acceleration.set(accel_x, accel_y);
    velocity.set(vel_x, vel_y);
    initial_position.set(pos_x, pos_y);

    start_color = s_color;
    end_color = e_color;

    life_span = life;
    velocity_cap.set(vel_x_cap, vel_y_cap);

    start_size = s_size;
    end_size = e_size;

    angle_variance = angle_var;
};

Emitter_Info::~Emitter_Info()
{
    particle_texture = nullptr;
};

SDL_Texture* Emitter_Info::get_texture()
{
    return particle_texture;
};

float Emitter_Info::get_life_span()
{
    return life_span;
};

float Emitter_Info::get_start_size()
{
    return start_size;
};

float Emitter_Info::get_end_size()
{
    return end_size;
};

float Emitter_Info::get_angle_variance()
{
    return angle_variance;
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

void Emitter_Info::set_start_size(float scale)
{
    start_size = scale;
};

void Emitter_Info::set_end_size(float scale)
{
    end_size = scale;
};

void Emitter_Info::set_variance(float degrees)
{
    angle_variance = degrees;
};
