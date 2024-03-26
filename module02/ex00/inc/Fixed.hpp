/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:41:57 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 05:52:54 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _integer;
		static const int _frac_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		Fixed &operator=(const Fixed&);
		int getRawBits() const;
		void setRawBits(int const);
};

#endif