/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:23:18 by ggalon            #+#    #+#             */
/*   Updated: 2024/04/02 10:23:18 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	_type = cure._type;
}

Cure& Cure::operator=(const Cure &cure)
{
	_type = cure._type;
	return (*this);
}

Cure::~Cure()
{

}

const std::string& Cure::getType() const
{
	return (_type);
}

AMateria* Cure::clone() const
{
	Cure *cure = new Cure;
	return (cure);
}

void Cure::use(ICharacter &character)
{
	std::cout << "* heals " << character.getName() << "'s wounds *" << std::endl;
}
