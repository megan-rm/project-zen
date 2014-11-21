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
*  -need to be able to get_width()
*   and height of my entities (after
*   scaling and such!
************************************/
class Entity
{
protected:
    SDL_Rect            position_rect;
    SDL_Rect            sprite;
    SDL_Texture*        image;
    SDL_Point           center;
    SDL_RendererFlip    flip_type;

    float               rotation;
    SDL_BlendMode       blending;
    uint8_t             alpha;
    bool                alive;

public:
  /*ctr*/               Entity(SDL_Texture* image);
  virtual /*dtr*/       ~Entity();

  virtual void          draw(SDL_Renderer* renderer);
  virtual void          update();

  void                  stretch(int width, int height);
  void                  scale(float scale);

  void                  move(float x, float y);
  void                  rotate(float angle);

  void                  center_on_rect();
  void                  set_center(int relative_x, int relative_y);
  void                  set_blending(SDL_BlendMode blending);
  void                  set_alpha(uint8_t alpha);
  void                  set_sprite(unsigned int width, unsigned int height); /// this may be wrong
  void                  flip_sprite(SDL_RendererFlip flip);
  const SDL_Rect*       get_sprite();
  bool                  is_alive();

  Vector2D              position;
};

#endif
