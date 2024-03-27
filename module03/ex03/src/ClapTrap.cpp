/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:48:09 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 08:44:50 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = "ClapTrap";
	_health = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	if (name.empty())
		_name = "ClapTrap";
	else
		_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = claptrap._name;
	_health = claptrap._health;
	_energy = claptrap._energy;
	_damage = claptrap._damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	_name = claptrap._name;
	_health = claptrap._health;
	_energy = claptrap._energy;
	_damage = claptrap._damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " get destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_health == 0)
	{
		std::cout << "ClapTrap " << _name << " try to attack but not enough health..." << std::endl;
		return;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name << " try to attack but not enough energy..." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health < amount)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount - (amount - _health) << " points of damage and got no more health!" << std::endl;
		_health = 0;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health == 0)
	{
		std::cout << "ClapTrap " << _name << " try to repair but not enough health..." << std::endl;
		return;
	}
	if (_energy == 0)
	{
		std::cout << "ClapTrap " << _name << " try to repair but not enough energy..." << std::endl;
		return;
	}
	_energy--;
	_health += amount;
	std::cout << "ClapTrap " << _name << " get repaired " << amount << " points of health!" << std::endl;
}
