/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:37:45 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 20:13:00 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat someRandomBureaucrat("Jean", 1);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	someRandomBureaucrat.signForm(*rrf);
	rrf->execute(someRandomBureaucrat);
	return (0);
}
