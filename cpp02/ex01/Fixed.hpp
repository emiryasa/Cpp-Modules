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
        ~Fixed();
        Fixed	&operator=(Fixed const &src);
        int		getRawBits(void) const;
	    void	setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);
