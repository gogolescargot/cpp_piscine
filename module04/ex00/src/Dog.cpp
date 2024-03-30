/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:12:36 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 08:12:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->setType(dog.getType());
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog: Assignment operator called" << std::endl;
	this->setType(dog.getType());
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: Wouf" << std::endl;
}