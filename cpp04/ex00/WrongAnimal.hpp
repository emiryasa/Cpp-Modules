#pragma once

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal();
		WrongAnimal(const WrongAnimal &);
		WrongAnimal& operator=(const WrongAnimal &);
		~WrongAnimal();

        std::string     getType() const;
        void    makeSound() const;
};
