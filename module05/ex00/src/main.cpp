/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:37:45 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 06:50:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat jean("Jean", 1);
	try
	{
		jean.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << jean << std::endl;

	Bureaucrat pierre("Pierre", 150);
	try
	{
		pierre.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << pierre << std::endl;

	Bureaucrat jacques;
	std::cout << jacques << std::endl;
	jacques.incrementGrade();
	std::cout << jacques << std::endl;
	jacques.decrementGrade();
	std::cout << jacques << std::endl;

	try
	{
		Bureaucrat henri("Henri", 999);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
