#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : num(0) {}

Fixed::Fixed(const int fixedp)
{
    this->num = fixedp << frac;
}

Fixed::Fixed(const float floatingp)
{
    this->num = roundf(floatingp * (1 << frac));
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed::~Fixed() {}
 
Fixed	&Fixed::operator=(Fixed const &src)
{
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

float	Fixed::toFloat(void) const
{
	return (float)this->num / (float)(1 << this->frac);
}

int	Fixed::toInt(void) const
{
	return roundf(this->num / (1 << this->frac));
}

bool	Fixed::operator>(Fixed const &src) const { 
    return this->num > src.num;
}

bool	Fixed::operator<(Fixed const &src) const {
    return this->num < src.num;
}

bool	Fixed::operator>=(Fixed const &src) const {
    return this->num >= src.num;
}
bool	Fixed::operator<=(Fixed const &src) const {
    return this->num <= src.num;
}
bool	Fixed::operator==(Fixed const &src) const {
    return this->num == src.num;
}
bool	Fixed::operator!=(Fixed const &src) const {
    return this->num != src.num;
}

Fixed Fixed::operator+(Fixed const &src) const {
    Fixed result;
    result.setRawBits(this->num + src.num);
    return result;
}

Fixed Fixed::operator-(Fixed const &src) const {
    Fixed result;
    result.setRawBits(this->num - src.num);
    return result;
}

Fixed Fixed::operator*(Fixed const &src) const {
    Fixed result;
    result.setRawBits((this->num * src.num) >> this->frac);
    return result;
}

Fixed Fixed::operator/(Fixed const &src) const {
    Fixed result;
    result.setRawBits((this->num << this->frac) / src.num);
    return result;
}

Fixed &Fixed::operator++() {
    this->num++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->num++;
    return tmp;
}

Fixed &Fixed::operator--() {
    this->num--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed cpy = *this;
    this->num--;
    return cpy;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}
