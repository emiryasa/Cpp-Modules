#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *catBrain;
    public:
        Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();

        void makeSound() const;
};
