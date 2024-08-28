#include "Ice.hpp"

Ice::Ice() {}

Ice::Ice(const Ice &src)
{
    *this = src;
}

Ice &Ice::operator=(const Ice &src)
{
    if (this != &src)
    {
        *this = src;
    }
    return *this;
}

