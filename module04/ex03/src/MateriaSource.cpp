/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:24:44 by ggalon            #+#    #+#             */
/*   Updated: 2024/04/02 11:24:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiasrc)
{
	for (int i = 0; i < 4; i++)
	{
		if (materiasrc._memory[i])
			_memory[i] = materiasrc._memory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiasrc)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
			delete (_memory[i]);
		if (materiasrc._memory[i])
			_memory[i] = materiasrc._memory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
			delete (_memory[i]);
	}
}

void MateriaSource::learnMateria(AMateria *amateria)
{
	if (!amateria)
		return;
	int i = 0;
	while (_memory[i] && i < 4)
		i++;
	if (i < 4)
		_memory[i] = amateria;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	return (NULL);
}
