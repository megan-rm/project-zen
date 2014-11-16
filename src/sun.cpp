#include "sun.hpp"
#include <iostream>
#include <math.h>

Sun::Sun(SDL_Texture* sun_texture, Realtime& game_time) : Entity(sun_texture)
{
    time = &game_time;
    visible = false;
};

Sun::~Sun()
{
};

void Sun::init(int x, int y)
{
    movement_center.x = x;
    movement_center.y = y;
};

void Sun::update()
{
    /// convert hours to minutes, and add current minute
    float simple_time = (60 * time->get_hour()) + time->get_minute();
    /// convert current time into seconds, and add current second
    simple_time *= 60;
    simple_time += time->get_second();

    simple_time += 21600;
    if (simple_time >= 86399)
        simple_time-=86399;

    simple_time /= 86399;

    simple_time *= ( 2 * M_PI);

    float vertical = sin(simple_time);
    float horizontal = -cos(simple_time);

    move(320 - center.x + (280 * horizontal), 480 - center.y + (380 * vertical));
    std::cout << position.get_x() << "\t" << position.get_y() << std::endl;
};

