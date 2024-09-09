#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    (void)src;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    isExecutable(executor);
    std::cout << "*drilling noises*" << std::endl;
    if (std::rand() % 2)  // fonksiyona bakılacak
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}
