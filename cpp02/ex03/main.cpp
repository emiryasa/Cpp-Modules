#include "Point.hpp"

int main(void)
{
    {
        Point a(-1, 0);
        Point b(10, 10);
        Point c(0, 10);
        Point point(1, 2);
        // true
        std::cout << bsp(a, b, c, point) << std::endl;
    }

    {
        Point a;
        Point b(10, 10);
        Point c(0, 10);
        Point point(1, 1);
        // false
        std::cout << bsp(a, b, c, point) << std::endl;
    }

    {
        Point a(10, 10);
        Point b(10, 10);
        Point c(0, 10);
        Point point(1, 1);
        // false
        std::cout << bsp(a, b, c, point) << std::endl;
    }

    {
        Point a(1.2, 0);
        Point b(12, 5);
        Point c(-2.5, 0.512);
        Point point(1, 1);
        // true
        std::cout << bsp(a, b, c, point) << std::endl;
    }

    {
        Point a(1.2032f, 0.0f);
        Point b(12, 5);
        Point c(-2.5, 1.2032f);
        Point point(1, 1);
        // true
        std::cout << bsp(a, b, c, point) << std::endl;
    }

    {
        Point a;
        Point b;
        Point c;
        Point point;
        // false
        std::cout << bsp(a, b, c, point) << std::endl;
    }
    return 0;
}
