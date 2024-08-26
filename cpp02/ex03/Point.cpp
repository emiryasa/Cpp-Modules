#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x) , y(y) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        // x = other.x;
        // y = other.y;
    }
    return *this;
}

Fixed const &Point::getX() const
{
    return this->x;
}

Fixed const &Point::getY() const
{
    return this->y;
}

Point::~Point() {}
