/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:38:33 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 09:38:33 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	std::copy(brain._ideas, brain._ideas + 100, _ideas);
}

Brain& Brain::operator=(const Brain &brain)
{
	std::cout << "Brain: Assignment operator called" << std::endl;
	std::copy(brain._ideas, brain._ideas + 100, _ideas);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

void Brain::setIdeas(const std::string& str, unsigned int i)
{
	if (i > 99)
		return ;
	_ideas[i] = str;
}

std::string Brain::getIdeas(unsigned int i) const
{
	if (i > 99)
		return ("");
	return (_ideas[i]);
}
