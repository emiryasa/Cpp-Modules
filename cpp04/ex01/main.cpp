#include "Cat.hpp"
#include "Dog.hpp"
#include "Deneme.hpp"

int main()
{
    Batugotten obj;
    std::cout << obj.getType() << std::endl;
    Batugotten obj1;
    std::cout << obj1.getType() << std::endl;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // delete meta;
    // delete j;
    // delete i;
    // return 0;
}
