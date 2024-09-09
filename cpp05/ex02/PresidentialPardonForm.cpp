#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    (void)src;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    isExecutable(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
