/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:51:49 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 21:51:49 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	if (name.empty())
		_name = "HumanB";
	else
		_name = name;
	_weapon = NULL;
	std::cout << _name << ": appear" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << _name << ": is dead" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << ": attacks with their bare hands" << std::endl;
	else
		std::cout << _name << ": attacks with their " << _weapon->getType() << std::endl;
}