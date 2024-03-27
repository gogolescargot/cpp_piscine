/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:18:09 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 08:18:09 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_health = 100;
	_energy = 50;
	_damage = 20;
	_gate = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_health = 100;
	_energy = 50;
	_damage = 20;
	_gate = false;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_gate = scavtrap._gate;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	_name = scavtrap._name;
	_health = scavtrap._health;
	_energy = scavtrap._energy;
	_damage = scavtrap._damage;
	_gate = scavtrap._gate;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " get destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_health == 0)
	{
		std::cout << "ScavTrap " << _name << " try to attack but not enough health..." << std::endl;
		return;
	}
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name << " try to attack but not enough energy..." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void ScavTrap::guardGate()
{
	if (_gate == false)
	{
		_gate = true;
		std::cout << "Scavtrap " << _name << " is now in gate keeper mode" << std::endl;
	}
	else
		std::cout << "Scavtrap " << _name << " is already in gate keeper mode" << std::endl;
}