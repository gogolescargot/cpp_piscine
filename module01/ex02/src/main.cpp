/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:34 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 19:13:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "string variable address: " << &string << std::endl;
	std::cout << "string pointer address: " << stringPTR << std::endl;
	std::cout << "string reference address: " << &stringREF << std::endl;

	std::cout << "string variable value: " << string << std::endl;
	std::cout << "string pointer value: " << *stringPTR << std::endl;
	std::cout << "string reference value: " << stringREF << std::endl;

	return (0);
}
