#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
 
Fixed	&Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		this->num = src.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->num = raw;
}
