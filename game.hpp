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

using std::string;
using std::map;

class Game
{
private:
    bool                running;
    SDL_Window*         gameWindow;
    SDL_Renderer*       gameRenderer;
    SDL_Event           gameInput;
    time_t              gameTime;
    struct tm*          timeInfo;

    unsigned int        hour;
    unsigned int        minute;
    unsigned int        second;
    unsigned short      dayOfWeek;
    unsigned short      month;
    unsigned short      dayOfMonth;

    unsigned int        screen_width;
    unsigned int        screen_height;
    std::string         window_title;

    unsigned short      morning;
    unsigned short      noon;
    unsigned short      evening;
    unsigned short      night;

    std::vector<Entity*>
                        gameVec;
    Graphic_Cache*      images;
    void                eventLoop();
    void                update();
    void                draw();
    void                handleInput(SDL_Event&);

public:
    /*ctr*/             Game();
    /*dtr*/             ~Game();

    void                run();
};


#endif //GAME_H_
