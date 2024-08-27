/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:05:23 by vvaalant          #+#    #+#             */
/*   Updated: 2024/08/27 11:05:25 by vvaalant         ###   ########.fr       */
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

        float   toFloat() const;
        int     toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
