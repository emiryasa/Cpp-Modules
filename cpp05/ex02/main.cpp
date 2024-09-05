#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("a", 11);
    Form form("b", 10, 20);

    bureaucrat.signForm(form);

    std::cout << form << std::endl;

    return 0;
}
