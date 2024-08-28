#pragma once

#include <iostream>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal(/* args */);
    AAnimal(const AAnimal &copy);
    AAnimal &operator=(const AAnimal &src);
    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual ~AAnimal();
};
