#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *a = new Bureaucrat("a", 1);
    Bureaucrat *b = new Bureaucrat("b", 150);

    try {
        std::cout << *a << std::endl;
        std::cout << *b << std::endl;

        a->incrementGrade();
        b->decrementGrade();

        std::cout << *a << std::endl;
        std::cout << *b << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    delete a;
    delete b;

    return 0;
}
