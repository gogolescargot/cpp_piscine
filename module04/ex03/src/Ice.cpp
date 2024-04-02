/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:17:14 by ggalon            #+#    #+#             */
/*   Updated: 2024/04/02 10:17:14 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	_type = ice._type;
}

Ice& Ice::operator=(const Ice &ice)
{
	_type = ice._type;
	return (*this);
}

Ice::~Ice()
{

}

const std::string& Ice::getType() const
{
	return (_type);
}

AMateria* Ice::clone() const
{
	Ice *ice = new Ice;
	return (ice);
}

void Ice::use(ICharacter &character)
{
	std::cout << "* shoots an ice bolt at " << character.getName() << " *" << std::endl;
}
