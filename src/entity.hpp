#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.hpp"

/************************************
* Base drawable class. Anything that
* can appear on the screen must be
* a entity, or variety of.
************************************/

class Entity
{
private:
    SDL_Rect            position_rect;
    Sprite              sprite;
    double              rotation;
    float               center_x;
    float               center_y;
    SDL_Point           center;
    SDL_RendererFlip    flip_type;

public:
  /*ctr*/               Entity(SDL_Texture* itsTex);
  /*dtr*/               ~Entity();

  void                  draw(SDL_Renderer*);
  void                  update();
  void                  stretch(float, float);
  void                  move(float, float);
  void                  rotate(double angle);
};

#endif
