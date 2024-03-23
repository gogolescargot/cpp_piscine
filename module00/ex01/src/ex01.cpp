/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:08:33 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/22 20:08:33 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ex01.hpp"

int main(void) {
	PhoneBook	phonebook;
	std::string	input;
	while (true) {
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl << "Error occurs while reading" << std::endl;
			exit(1);
		}
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			exit(0);
	}
	return (0);
}
