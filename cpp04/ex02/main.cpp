#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal *aanimal1 = new Dog();
	AAnimal *aanimal2 = new Cat();

	aanimal1->makeSound(); 
	aanimal2->makeSound(); 

	delete aanimal1;
	delete aanimal2;
	// AAnimal a;
	return 0;
}
