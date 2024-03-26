/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:48:09 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 17:32:04 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	_name = claptrap._name;
	_health = claptrap._health;
	_energy = claptrap._energy;
	_damage = claptrap._damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	_name = claptrap._name;
	_health = claptrap._health;
	_energy = claptrap._energy;
	_damage = claptrap._damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy < 1)
	{
		
	}
	else
	{
		_energy--;
		std::cout << "ClapTrap " << _name << "attacks " << target << ",causing " << _damage << " points of damage!" << std::endl
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health < amount)
	{
		_health = 0;
	}
	else
	{
		_health -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy < 1)
	{
		
	}
	else
	{
		_energy--;
		_health += amount;
	}
	
}