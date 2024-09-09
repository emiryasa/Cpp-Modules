#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    (void)src;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    isExecutable(executor);
    std::ofstream file;
    file.open((_target + "_shrubbery").c_str(), std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");
    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\n";
    file.close();
}
