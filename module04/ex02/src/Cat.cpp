/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:25:01 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 08:25:01 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->setType("Cat");
	_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->setType(cat.getType());
	_brain = new Brain(*cat._brain);
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat: Assignment operator called" << std::endl;
	this->setType(cat.getType());
	_brain = new Brain(*cat._brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete (_brain);
}

void Cat::makeSound() const
{
	std::cout << "Cat: Meow" << std::endl;
}

void Cat::setIdeas(const std::string &str, unsigned int i) const
{
	_brain->setIdeas(str, i);
}

std::string Cat::getIdeas(unsigned int i) const
{
	return (_brain->getIdeas(i));
}
