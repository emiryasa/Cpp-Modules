#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedp)
{
    std::cout << "Int constructor called" << std::endl;
    this->num = fixedp << frac;
}

Fixed::Fixed(const float floatingp)
{
    std::cout << "Float constructor called" << std::endl;
    this->num = roundf(floatingp * (1 << frac));
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
    return this->num;
}

void	Fixed::setRawBits(int const raw)
{
    this->num = raw;
}

float	Fixed::toFloat() const
{
	return (float)this->num / (float)(1 << this->frac);
}

int	Fixed::toInt() const
{
	return roundf(this->num / (1 << this->frac));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}
