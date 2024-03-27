/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:03:18 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 09:03:18 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = "DiamondTrap";
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name;
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	_name = diamondtrap._name;
	_health = diamondtrap._health;
	_energy = diamondtrap._energy;
	_damage = diamondtrap._damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " get destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Am I " << _name << " or " << ClapTrap::_name << " ?" << std::endl;
}
