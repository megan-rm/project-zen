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
*  -entities refer to an image (the
*   way it was before), have a sprite
*   component (SDL_rect), which is
*   automatically set as the clipping
*   of the entire image, and can later
*   be set to refer upon a spritesheet.
************************************/
class Entity
{
protected:
    SDL_Rect            position_rect;
    SDL_Rect            sprite;
    SDL_Texture*        image;
    SDL_Point           center;
    Vector2D            position;
    SDL_RendererFlip    flip_type;

    float               rotation;
    SDL_BlendMode       blending;
    uint8_t             alpha;
    bool                alive;

public:
  /*ctr*/               Entity(SDL_Texture*);
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
  void                  set_sprite(unsigned int, unsigned int);
  void                  flip_sprite(SDL_RendererFlip);
  const SDL_Rect*       get_sprite();
  bool                  is_alive();
};

#endif
