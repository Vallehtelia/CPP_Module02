#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int                 _fixed_point;
        static const int    _fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(Fixed const &other);
        Fixed &operator=(Fixed const &other);
        ~Fixed();

        bool    operator>(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;

        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;

        Fixed   &operator++();
        Fixed   &operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        float   toFloat() const;
        int     toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif