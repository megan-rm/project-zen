#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <vector>
#include "entity.hpp"
#include "graphic_cache.hpp"
#include "timer.hpp"

using std::string;
using std::map;

class Game
{
private:
    bool                running;
    SDL_Window*         game_window;
    SDL_Renderer*       game_renderer;
    SDL_Event           game_input;
    time_t              game_time;
    struct tm*          time_info;

    unsigned int        hour;
    unsigned int        minute;
    unsigned int        second;
    unsigned short      day_of_week;
    unsigned short      month;
    unsigned short      day_of_month;

    unsigned int        screen_width;
    unsigned int        screen_height;
    std::string         window_title;

    unsigned short      morning;
    unsigned short      noon;
    unsigned short      evening;
    unsigned short      night;

    std::vector<Entity*>
                        entity_vector;
    Graphic_Cache*      texture_cache;
    void                event_loop();
    void                update();
    void                draw();
    void                handle_input(SDL_Event&);
    Timer               fps;

public:
    /*ctr*/             Game();
    /*dtr*/             ~Game();

    void                run();
};


#endif //GAME_H_
