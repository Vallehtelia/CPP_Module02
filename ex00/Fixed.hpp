#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class   Fixed
{
    private:
        int                 _fixed_point;
        static const int    _fractional_bits;
    public:
        Fixed();
        Fixed(Fixed const &other);
        Fixed &operator=(Fixed const &other);
        ~Fixed();

        int     getRawBits();
        void    setRawBits(int const raw);
};

#endif