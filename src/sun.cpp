#include "sun.hpp"
#include <iostream>


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
    /************************************
    * Get time in hhmmss format
    ************************************/
    float simple_time = time->get_hour() * 10000;
    simple_time += time->get_minute() * 100;
    simple_time += time->get_second();
    simple_time /= 235959;
    simple_time *= (2 * M_PI);

    float vertical = sin(simple_time);
    float horizontal = (1-cos(simple_time))/2;

    move( (0 + (640 - 0) * horizontal), (320 * vertical) + 480);

    /************************************
    * More debugging~
    ************************************/
    std::cout << position.get_x() << "  " << position.get_y() << std::endl;
};

