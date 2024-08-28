/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:19:01 by vvaalant          #+#    #+#             */
/*   Updated: 2024/08/27 14:45:52 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool    Fixed::operator>(const Fixed &other) const
{
    return (this->_fixed_point > other._fixed_point);
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (this->_fixed_point < other._fixed_point);
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (this->_fixed_point >= other._fixed_point);
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (this->_fixed_point <= other._fixed_point);
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (this->_fixed_point == other._fixed_point);
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (this->_fixed_point != other._fixed_point);
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed   &Fixed::operator++()
{
    this->_fixed_point++;
    return (*this);
}

Fixed   &Fixed::operator--()
{
    this->_fixed_point--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp = *this;
    this->_fixed_point++;
    return (temp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp = *this;
    this->_fixed_point--;
    return (temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed    &Fixed::min(Fixed &other1, Fixed &other2)
{
    if (other1.toFloat() <= other2.toFloat())
        return (other1);
    return (other2);
}
const Fixed    &Fixed::min(Fixed const &other1, Fixed const &other2)
{
    if (other1.toFloat() <= other2.toFloat())
        return (other1);
    return (other2);
}
Fixed    &Fixed::max(Fixed &other1, Fixed &other2)
{
    if (other1.toFloat() >= other2.toFloat())
        return (other1);
    return (other2);
}
const Fixed    &Fixed::max(Fixed const &other1, Fixed const &other2)
{
    if (other1.toFloat() >= other2.toFloat())
        return (other1);
    return (other2);
}
