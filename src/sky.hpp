#ifndef SKY_HPP
#define SKY_HPP

class Sky
{
public:
    void        draw();
    void        update();

private:
    SDL_Rect    backdrop;
    Sun*        sun;
};
#endif // SKY_HPP
