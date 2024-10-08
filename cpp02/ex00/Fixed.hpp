#pragma once
#include <iostream>

class Fixed {
    private:
        int num;
        static const int frac;
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();
        Fixed	&operator=(Fixed const &src);
        int		getRawBits(void) const;
	    void	setRawBits(int const raw);
};
