/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:29:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/04/02 10:29:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "Character";
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string &name)
{
	if (name.empty())
		_name = "Character";
	else
		_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character &character)
{
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete (_inventory[i]);
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete (_inventory[i]);
	}
}

const std::string& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *amateria)
{
	if (!amateria)
		return;
	int i = 0;
	while (_inventory[i] && i < 4)
		i++;
	if (i < 4)
		_inventory[i] = amateria;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (!_inventory[idx])
		return;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &character)
{
	if (idx < 0 || idx > 3)
		return;
	if (!_inventory[idx])
		return;
	_inventory[idx]->use(character);
}
