#include "Deneme.hpp"

int Batugotten::num = 0;

Batugotten::Batugotten()
{
    num++;
}

int Batugotten::getType()
{
    return num;
}
