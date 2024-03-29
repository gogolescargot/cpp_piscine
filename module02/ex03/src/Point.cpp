/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:24:50 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 06:24:50 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point()
{
	this->setX(0);
	this->setY(0);
}

Point::Point(const float x, const float y)
{
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point &point)
{
	this->setX(point._x);
	this->setY(point._y);
}

Point &Point::operator=(const Point &point)
{
	this->setX(point._x);
	this->setY(point._y);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.getX() << ";" << point.getY() << ")";
	return os;
}

Point::~Point()
{
	
}

float Point::getX() const
{
	return (_x.toFloat());
}

float Point::getY() const
{
	return (_y.toFloat());
}

void Point::setX(const Fixed &x)
{
	_x = x;
}

void Point::setY(const Fixed &y)
{
	_y = y;
}