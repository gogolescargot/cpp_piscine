/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:29:59 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 20:09:17 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

AForm* newShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* newRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* newPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm* (*form_list[3])(const std::string target) = {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};
	std::string form_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (form_list[i](target));
		}
	}
	std::cerr << "Error no form find with name " << name << std::endl;
	return (NULL);
}