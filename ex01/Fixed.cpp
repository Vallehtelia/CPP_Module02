
#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    this->_fixed_point = value << this->_fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    this->_fixed_point = roundf(value * (1 << this->_fractional_bits));
}

Fixed::Fixed(Fixed const &other) : _fixed_point(other._fixed_point)
{
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(Fixed const &other)
{
    std::cout << "Copy assignment operator called\n";
    this->_fixed_point = other._fixed_point;
    return (*this);
}

float   Fixed::toFloat() const
{
    return (static_cast<float>(this->_fixed_point) / (1 << this->_fractional_bits));
}

int Fixed::toInt() const
{
    return (this->_fixed_point >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}