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
protected:
    SDL_Rect            position_rect;
    Sprite              sprite;
    double              rotation;
    float               center_x;
    float               center_y;
    float               position_x;
    float               position_y;
    SDL_Point           center;
    SDL_RendererFlip    flip_type;

public:
  /*ctr*/               Entity(SDL_Texture*);
  virtual /*dtr*/       ~Entity();

  virtual void          draw(SDL_Renderer*);
  virtual void          update();

  void                  stretch(float, float);
  void                  move(float, float);
  void                  rotate(double angle);
  void                  center_on_clip();
  void                  set_center(float, float);
  void                  flip_sprite(SDL_RendererFlip);
  Sprite* const         get_sprite();
};

#endif
