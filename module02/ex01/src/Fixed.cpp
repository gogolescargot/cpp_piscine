/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:41:51 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/25 17:47:56 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << _fractional);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(n * (1 << _fractional)));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixed.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}


int Fixed::getRawBits() const
{
	return (_integer);
}

void Fixed::setRawBits(int const raw)
{
	_integer = raw;
}


float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / (1 << _fractional));
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> _fractional);
}