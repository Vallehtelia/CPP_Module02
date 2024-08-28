/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:05:02 by vvaalant          #+#    #+#             */
/*   Updated: 2024/08/28 18:10:37 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class   Fixed
{
    private:
        int                 _fixed_point;
        static const int    _fractional_bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &other);
        Fixed &operator=(Fixed const &other);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);
};

#endif
