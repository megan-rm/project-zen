#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "spritesheet.hpp"
#include "vector2d.hpp"
/************************************
* Base drawable class. Anything that
* can appear on the screen must be
* a entity, or variety of.
************************************/


/************************************
* TODO:
*  -point to spritesheet, hold clip
*   rect to which sprite in sheet.
*  -Add gravity flag & support
************************************/
class Entity
{
protected:
    SDL_Rect            position_rect;
    Spritesheet*        spritesheet;
    SDL_Point           center;
    Vector2D            position;
    SDL_RendererFlip    flip_type;

    float               rotation;
    SDL_BlendMode       blending;
    uint8_t             alpha;
    bool                alive;

public:
  /*ctr*/               Entity(Spritesheet&); /// spritesheet
  virtual /*dtr*/       ~Entity();

  virtual void          draw(SDL_Renderer*);
  virtual void          update();

  void                  stretch(int, int);
  void                  scale(float);

  void                  move(float, float);
  void                  rotate(float angle);

  void                  center_on_rect();
  void                  set_center(int, int);
  void                  set_blending(SDL_BlendMode);
  void                  set_alpha(uint8_t);
  void                  flip_sprite(SDL_RendererFlip);
  Spritesheet* const    get_spritesheet();
  bool                  is_alive();
};

#endif
