/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:41:51 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 06:22:10 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int n)
{
	this->setRawBits(n << _frac_bits);
}

Fixed::Fixed(const float n)
{
	this->setRawBits(roundf(n * (1 << _frac_bits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed &fixed)
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed)
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed temp(this->toFloat() + fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed temp(this->toFloat() - fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed temp(this->toFloat() * fixed.toFloat());
	return (temp);
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return (temp);
}

Fixed &Fixed::operator++()
{
	_integer++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_integer--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_integer++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_integer--;
	return (temp);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / (1 << _frac_bits));
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> _frac_bits);
}

int Fixed::getRawBits() const
{
	return (_integer);
}

void Fixed::setRawBits(int const raw)
{
	_integer = raw;
}