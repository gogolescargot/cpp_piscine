/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:17:44 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/20 21:26:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong argument number" << std::endl;
		return (1);
	}

	try
	{
		rpn(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
