#pragma once
#include "Fixed.hpp"

class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(Point const &src);
        Point(const float x, const float y);
        Point &operator=(Point const &src);
        Fixed const &getX() const;
        Fixed const &getY() const;
        ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
