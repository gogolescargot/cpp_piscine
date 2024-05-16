/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:48:31 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 12:01:25 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size)
{
	_max = size;
}

Span::~Span()
{
	
}

Span::Span(const Span& src)
{
	_max = src._max;
	_array = src._array;
}

Span& Span::operator=(const Span& src)
{
	_max = src._max;
	_array = src._array;
	return (*this);
}

void Span::addNumber(int nbr)
{
	if (_array.size() == _max)
		throw (std::logic_error("Max size"));
	else
		_array.insert(nbr);
}

unsigned int Span::longestSpan()
{
	if (_array.size() < 2)
		throw (std::logic_error("Array not large enough"));
	return (*--_array.end() - *_array.begin());
}

unsigned int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw (std::logic_error("Array not large enough"));
	std::multiset<int>::iterator it = ++_array.begin();
	unsigned int min = *it - *--it;
	it++;
	for (it++; it != _array.end(); it++)
	{
		min = std::min(static_cast<unsigned int>(*it - *--it), min);
		it++;
	}
	return (min);
}

std::multiset<int>::iterator Span::getBegin()
{
	return (_array.begin());
}

std::multiset<int>::iterator Span::getEnd()
{
	return (_array.end());
}