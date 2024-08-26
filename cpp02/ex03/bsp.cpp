#include "Point.hpp"

static float area(const Point a, const Point b, const Point c)
{
    float area;
    area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
    area /= 2;
    if (area >= 0)
        return area;
    return area * -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

    float area1 = area(a, b, c);
    float area2 = area(point, a, b);
    float area3 = area(point, b, c);
    float area4 = area(point, a, c);

    // std::cout << "area2: " << area2 << std::endl;
    // std::cout << "area3: " << area3 << std::endl;
    // std::cout << "area4: " << area4 << std::endl;
    // std::cout << "area1: " << area1 << std::endl;

    if (area2 == 0 || area3 == 0 || area4 == 0 || ((area2 + area3 + area4) != area1))
        return false;
    return true;
}
