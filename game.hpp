#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <vector>
#include "entity.hpp"


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
    unsigned short int  dayOfWeek;
    unsigned short int  month;
    unsigned short int  dayOfMonth;


    map<string, SDL_Texture*>
                        textureLibrary;
    std::vector<SDL_Texture**>
                        gameVector;
    std::vector<Entity*>
                        gameVec;

    void                loadTexture(string);
    void                eventLoop();
    void                update();
    void                draw();
    void                handleInput(SDL_Event&);

public:
    Game();
    ~Game();
};


#endif //GAME_H_
