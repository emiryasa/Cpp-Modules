#pragma once

#include "iostream"
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &src);
        void makeSound() const;
        void setBrainIdea(int index, const std::string &idea);
        std::string getBrainIdea(int index) const;
        ~Cat();
};
