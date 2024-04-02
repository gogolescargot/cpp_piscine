/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:37:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/04/02 10:37:41 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	
}

AMateria::AMateria(const std::string& type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &amateria)
{
	_type = amateria._type;
}

AMateria& AMateria::operator=(const AMateria &amateria)
{
	_type = amateria._type;
	return (*this);
}

const std::string &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &amateria)
{
	std::cout << "AMateria used on " << amateria.getName() << std::endl;
}

AMateria::~AMateria()
{

}
