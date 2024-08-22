#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain *dogBrain;
    public:
        Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();

        void makeSound() const;
};
