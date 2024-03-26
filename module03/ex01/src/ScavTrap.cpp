/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:13:21 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 19:26:15 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &claptrap) : ClapTrap(claptrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = claptrap._name;
	_health = claptrap._health;
	_energy = claptrap._energy;
	_damage = claptrap._damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	ClapTrap::operator=(scavtrap);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " get destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!checkScavTrap(*this, "attack"))
		return;
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_health < amount)
	{
		std::cout << "ScavTrap " << _name << " takes " << amount - (amount - _health) << " points of damage and got no more health!" << std::endl;
		_health = 0;
		return;
	}
	std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_health -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (!checkScavTrap(*this, "repair"))
		return;
	_energy--;
	_health += amount;
	std::cout << "ScavTrap " << _name << " get repaired " << amount << " points of health!" << std::endl;
}

void ScavTrap::displayStats()
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Health: " << _health << std::endl;
	std::cout << "Energy: " << _energy << std::endl;
}


unsigned int ScavTrap::getHealth() const
{
	return (_health);
}

unsigned int ScavTrap::getEnergy() const
{
	return (_energy);
}

std::string ScavTrap::getName() const
{
	return (_name);
}

bool checkScavTrap(const ScavTrap &claptrap, std::string str)
{
	if (claptrap.getHealth() == 0)
	{
		std::cout << "ScavTrap " << claptrap.getName() << " try to " << str << " but not enough health..." << std::endl;
		return (false);
	}
	if (claptrap.getEnergy() == 0)
	{
		std::cout << "ScavTrap " << claptrap.getName() << " try to " << str << " but not enough energy..." << std::endl;;
		return (false);
	}
	return (true);
}