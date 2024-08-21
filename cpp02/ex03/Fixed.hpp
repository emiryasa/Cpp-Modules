#pragma once
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int num;
        static const int frac;
    public:
        Fixed();
        Fixed(const int fixedp);
        Fixed(const float floatingp);
        Fixed(Fixed const &src);
        Fixed	&operator=(Fixed const &src);
        ~Fixed();

        int		getRawBits(void) const;
	    void	setRawBits(int const raw);

        bool	operator>(Fixed const &src) const;
        bool	operator<(Fixed const &src) const;
        bool	operator>=(Fixed const &src) const;
        bool	operator<=(Fixed const &src) const;
        bool	operator==(Fixed const &src) const;
        bool	operator!=(Fixed const &src) const;

        Fixed	operator+(Fixed const &src) const;
        Fixed	operator-(Fixed const &src) const;
        Fixed	operator*(Fixed const &src) const;
        Fixed	operator/(Fixed const &src) const;

        Fixed   operator++(int);  
        Fixed&  operator++();
        Fixed   operator--(int);
        Fixed&  operator--(); 

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed  min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed  max(const Fixed& a, const Fixed& b);

        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);
