/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:37:45 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 07:28:05 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat jean("Jean", 150);
	Form form("Test", 150, 20);
	std::cout << jean << std::endl << form << std::endl;
	try
	{
		form.beSigned(jean);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		jean.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}
