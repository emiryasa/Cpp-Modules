#include "AForm.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

Form::~Form() {}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
        _isSigned = src.getIsSigned();
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (_gradeToSign < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    _isSigned = true;
}

void Form::isExecutable(const Bureaucrat &bureaucrat) const
{
    if (!_isSigned)
        throw Form::NotSignedException();
    if (_gradeToExecute < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high for this form";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low for this form";
}

const char *Form::NotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
    out << "Form name: " << src.getName() << ", ";
    out << "signed: " << src.getIsSigned() << ", ";
    out << "grade to sign: " << src.getGradeToSign() << ", ";
    out << "grade to execute: " << src.getGradeToExecute();

    return out;
}
