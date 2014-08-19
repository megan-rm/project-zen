#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D
{
private:
    float       x;
    float       y;
public:
    /*ctr*/     Vector2D();
                Vector2D(float x, float y);
    /*dtr*/     ~Vector2D();

    float       get_x();
    float       get_y();
    void        set_x(float x);
    void        set_y(float y);
    void        set(float x, float y);

    Vector2D    operator+(Vector2D& rhs);
    Vector2D    operator-(Vector2D& rhs);
    Vector2D    operator*(Vector2D& rhs);
    Vector2D    operator/(Vector2D& rhs);
};

#endif // VECTOR2D_H_
