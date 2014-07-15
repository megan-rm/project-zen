#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <iostream>
#include <string>

Game::Game()
{
    time(&gameTime);
    timeInfo = localtime(&gameTime);


    screen_width = 640;
    screen_height = 480;
    window_title = "Project Zen";

    morning = 7;
    noon = 12;
    evening = 17;
    night = 20;

    gameWindow = SDL_CreateWindow(window_title.c_str(),
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
              screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(!gameWindow)
    {
        std::cout << "Problem creating window: " << SDL_GetError()
                  << std::endl;
    }

    gameRenderer = SDL_CreateRenderer(gameWindow, 0, SDL_RENDERER_ACCELERATED);
    if(!gameRenderer)
    {
        std::cout << "Problem creating renderer: " << SDL_GetError()
                  << std::endl;
    }

    images = new Graphic_Cache(gameRenderer);
};

Game::~Game()
{
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(gameRenderer);
};

void Game::handleInput(SDL_Event& event)
{
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    time(&gameTime);
    timeInfo = localtime(&gameTime);
    //std::string titletime = asctime(timeInfo);
};

void Game::draw()
{

    SDL_RenderClear(gameRenderer);

    hour = timeInfo->tm_hour;
    minute = timeInfo->tm_min;
    second = timeInfo->tm_sec;
    if(hour >= night)
        SDL_SetRenderDrawColor(gameRenderer, 0, 0, 50, 0);
    else if(hour >= morning && hour < noon)
        SDL_SetRenderDrawColor(gameRenderer, 255, 252, 127, 0);
    else if(hour >= noon && hour < evening)
        SDL_SetRenderDrawColor(gameRenderer, 64, 156, 255, 0);
    else if(hour >= evening && hour < night)
        SDL_SetRenderDrawColor(gameRenderer, 255, 183, 76, 0);

    for(unsigned int x = 0; x < gameVec.size(); x++)
    {
        gameVec.at(x)->draw(gameRenderer);
    }
    SDL_RenderPresent(gameRenderer);
};

void Game::run()
{
    images->getTexture("raindrop.png");

    Entity* newEntity = new Entity(images->getTexture("raindrop.png"));
    newEntity->stretch(48.0, 48.0);
    newEntity->move(320.0, 240.0);
    newEntity->rotate(20.0);
    gameVec.push_back(newEntity);

    Entity* newEnt = new Entity(images->getTexture("raindrop.png"));
    newEnt->stretch(16.0, 16.0);
    newEnt->move(480.0, 320.0);
    newEnt->rotate(65.0);
    gameVec.push_back(newEnt);

    running = true;
    while(running)
    {
        handleInput(gameInput);
        update();
        draw();
        SDL_Delay(16);
    }
};
