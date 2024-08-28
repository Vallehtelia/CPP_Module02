/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:18:58 by vvaalant          #+#    #+#             */
/*   Updated: 2024/08/27 14:45:48 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        static Fixed        &min(Fixed &other1, Fixed &other2);
        static const Fixed  &min(Fixed const &other1, Fixed const &other2);
        static Fixed        &max(Fixed &other1, Fixed &other2);
        static const Fixed  &max(Fixed const &other1, Fixed const &other2);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
