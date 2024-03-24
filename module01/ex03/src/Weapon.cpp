/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:05:33 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 22:05:33 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty())
		_type = "default weapon";
	else
		_type = type;
	std::cout << _type << " is crafted" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << _type << " is broken" << std::endl;
}

void Weapon::setType(std::string type)
{
	if (type.empty())
		_type = "default weapon";
	else
		_type = type;
}

const std::string Weapon::getType()
{
	return (_type);
}

