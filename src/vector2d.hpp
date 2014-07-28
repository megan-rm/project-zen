#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D
{
private:
    float       x;
    float       y;
public:
    /*ctr*/     Vector2D();
                Vector2D(float, float);
    /*dtr*/     ~Vector2D();

    float       get_x();
    float       get_y();
    void        set_x(float);
    void        set_y(float);
    void        set(float, float);

    Vector2D    operator+(Vector2D&);
    Vector2D    operator-(Vector2D&);
    Vector2D    operator*(Vector2D&);
    Vector2D    operator/(Vector2D&);
};

#endif // VECTOR2D_H_
