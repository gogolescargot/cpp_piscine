/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:14:12 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 09:14:12 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal(wrongcat)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	this->setType(wrongcat.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "WrongCat: Assignment operator called" << std::endl;
	this->setType(wrongcat.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow" << std::endl;
}