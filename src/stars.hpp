#ifndef STARS_H_
#define STARS_H_

class Star : public Entity
{
private:
    void            twinkle();
    SDL_Color       color;
    unsigned int    animation_cycle
public:

};
#endif // STARS_H_
