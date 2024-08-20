
#include "Fixed.hpp"

const int  Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fixed_point(0) {
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
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

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called\n";
    return (this->_fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}