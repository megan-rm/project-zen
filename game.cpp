#include "game.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <iostream>
#include <string>

namespace globals
{
  const unsigned int SCREENWIDTH = 640;
  const unsigned int SCREENHEIGHT = 480;
  const std::string SCREENTITLE = "Project Zen";
  unsigned short MORNING = 7;
  unsigned short NOON = 12;
  unsigned short EVENING = 17;
  unsigned short NIGHT = 20;
};

Game::Game()
{
  time(&gameTime);
  timeInfo = localtime(&gameTime);

  gameWindow = SDL_CreateWindow(globals::SCREENTITLE.c_str(),
              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
              globals::SCREENWIDTH, globals::SCREENHEIGHT, SDL_WINDOW_SHOWN);

  gameRenderer = SDL_CreateRenderer(gameWindow, 0, SDL_RENDERER_ACCELERATED);

  loadTexture("raindrop.png");
  gameVector.push_back(&(textureLibrary["raindrop.png"]));
  Entity newEntity(&(textureLibrary["raindrop.png"]));
  gameVec.push_back(&(newEntity));
  running = true;
  while(running)
  {
    handleInput(gameInput);
    update();
    draw();
    SDL_Delay(16);
  }
};

Game::~Game()
{
  SDL_DestroyWindow(gameWindow);
  SDL_DestroyRenderer(gameRenderer);
  textureLibrary.clear();
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
  std::string titletime = asctime(timeInfo);
  //SDL_SetWindowTitle(gameWindow, titletime.c_str());
};

void Game::draw()
{
  using namespace globals;

  SDL_RenderClear(gameRenderer);
  hour = timeInfo->tm_hour;
  minute = timeInfo->tm_min;
  second = timeInfo->tm_sec;
  if(hour >= NIGHT)
    SDL_SetRenderDrawColor(gameRenderer, 0, 0, 50, 0);
  else if(hour >= MORNING && hour < NOON)
    SDL_SetRenderDrawColor(gameRenderer, 255, 252, 127, 0);
  else if(hour >= NOON && hour < EVENING)
    SDL_SetRenderDrawColor(gameRenderer, 64, 156, 255, 0);
  else if(hour >= EVENING && hour < NIGHT)
    SDL_SetRenderDrawColor(gameRenderer, 255, 183, 76, 0);

  for(int x = 0; x < gameVector.size(); x++)
  {
    //SDL_RenderCopy(gameRenderer, (*gameVector.at(x)), NULL, NULL);
    gameVec.at(x)->draw(gameRenderer);
  }
  SDL_RenderPresent(gameRenderer);
};

void Game::loadTexture(std::string filename)
{
  SDL_Texture* newTexture = NULL;

  SDL_Surface* loadedSurface = IMG_Load(filename.c_str());

  newTexture = SDL_CreateTextureFromSurface(gameRenderer, loadedSurface);

  SDL_FreeSurface(loadedSurface);
  textureLibrary[filename.c_str()] = newTexture;
  return;
};

