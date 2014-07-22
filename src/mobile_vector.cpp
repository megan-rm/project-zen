#include "mobile_vector.hpp"

Mobile_Vector::Mobile_Vector()
{
    acceleration_x = 0.0;
    acceleration_y = 0.0;
    acceleration_cap = 0.0;

    velocity_x = 0.0;
    velocity_y = 0.0;
    velocity_cap = 0.0;

};

/*********************************
* Start off at a set acceleration
*********************************/
Mobile_Vector::Mobile_Vector(float accel_x, float accel_y)
{
    acceleration_x = accel_x;
    acceleration_y = accel_y;
    acceleration_cap = 0.0;

    velocity_x = 0.0;
    velocity_y = 0.0;
    velocity_cap = 0.0;
};

/*********************************
* Start off at a set acceleration
* and velocity.
*********************************/
Mobile_Vector::Mobile_Vector(float accel_x, float accel_y,
                             float vel_x, float vel_y)
{
    acceleration_x = accel_x;
    acceleration_y = accel_y;
    acceleration_cap = 0.0;

    velocity_x = vel_x;
    velocity_y = vel_y;
    velocity_cap = 0.0;
};

/*********************************
* Start off at a set acceleration
* and velocity, and set the caps
* for velocity and acceleration
**********************************/
Mobile_Vector::Mobile_Vector(float accel_x, float accel_y,
                             float vel_x, float vel_y,
                             float accel_cap, float vel_cap)
{

};


Mobile_Vector::~Mobile_Vector()
{
};

void Mobile_Vector::set_acceleration(float accel_x, float accel_y)
{
    acceleration_x = accel_x;
    acceleration_y = accel_y;
};

void Mobile_Vector::set_velocity(float vel_x, float vel_y)
{
    velocity_x = vel_x;
    velocity_y = vel_y;
};

void Mobile_Vector::scale_velocity(float vel_scale)
{
    velocity_x *= vel_scale;
    velocity_y *= vel_scale;
};

void Mobile_Vector::set_acceleration_cap(float accel_cap)
{
    acceleration_cap = accel_cap;
};

void Mobile_Vector::set_velocity_cap(float vel_cap)
{
    velocity_cap = vel_cap;
};

float Mobile_Vector::get_x_velocity()
{
    return velocity_x;
};

float Mobile_Vector::get_y_velocity()
{
    return velocity_y;
};

float Mobile_Vector::get_x_acceleration()
{
    return acceleration_x;
};

float Mobile_Vector::get_y_acceleration()
{
    return acceleration_y;
};

float Mobile_Vector::get_acceleration_cap()
{
    return acceleration_cap;
};

float Mobile_Vector::get_velocity_cap()
{
    return velocity_cap;
};
