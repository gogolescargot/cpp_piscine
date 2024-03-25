/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:41:57 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/25 16:40:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <math.h>

class Fixed
{
    private:
        int _integer;
        static const int _fractional = 8;
        public:
            Fixed();
            Fixed(const Fixed&);
            Fixed(const int);
            Fixed(const float);
            ~Fixed();
            Fixed &operator=(const Fixed&);
            int getRawBits() const;
            void setRawBits(int const);
            float toFloat() const;
            int toInt() const;
};

std::ostream &operator<<(std::ostream&, const Fixed&);

#endif