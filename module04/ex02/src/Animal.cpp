/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:42:32 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 07:42:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	_type = animal._type;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal: Assignment operator called" << std::endl;
	_type = animal._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const
{
	if (_type.empty())
		return ("Not an animal");
	return (_type);
}

void Animal::setType(const std::string &type)
{
	_type = type;
}

void Animal::makeSound() const
{
	std::cout << "Animal: *no sound*" << std::endl;
}