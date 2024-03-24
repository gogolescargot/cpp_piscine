/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:53:32 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 21:53:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	if (name.empty())
		_name = "HumanA";
	else
		_name = name;
	std::cout << _name << ": appear" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << ": is dead" << std::endl;
}

void HumanA::attack()
{
	std::cout << _name << ": attacks with their " << _weapon.getType() << std::endl;
}