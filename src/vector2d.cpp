#include "vector2d.hpp"

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
};

Vector2D::Vector2D(float new_x, float new_y)
{
    x = new_x;
    y = new_y;
};

Vector2D::~Vector2D(){};

float Vector2D::get_x()
{
    return x;
};

float Vector2D::get_y()
{
    return y;
};

void Vector2D::set_x(float new_x)
{
    x = new_x;
};

void Vector2D::set_y(float new_y)
{
    y = new_y;
};

void Vector2D::set(float new_x, float new_y)
{
    x = new_x;
    y = new_y;
};

Vector2D Vector2D::operator+(Vector2D& rhs)
{
    Vector2D temp;
    temp.x = this->x + rhs.x;
    temp.y = this->y + rhs.y;
    return temp;
};

Vector2D Vector2D::operator-(Vector2D& rhs)
{
    Vector2D temp;
    temp.x = this->x - rhs.x;
    temp.y = this->y - rhs.y;
    return temp;
};

Vector2D Vector2D::operator*(Vector2D& rhs)
{
    Vector2D temp;
    temp.x = this->x * rhs.x;
    temp.y = this->y * rhs.y;
    return temp;
};

Vector2D Vector2D::operator/(Vector2D& rhs)
{
    if(rhs.x == 0 && rhs.y == 0)
        return *this;

    Vector2D temp;
    if(rhs.x != 0)
    {
        temp.x = this->x / rhs.x;
    }
    else
        temp.x = this->x;

    if(rhs.y != 0)
    {
        temp.y = this->y / rhs.y;
    }
    else
        temp.y = this->y;
    return temp;
};
