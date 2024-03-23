/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:38 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/22 20:01:38 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ex01.hpp"

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

void	PhoneBook::add() {
	static size_t	i;
	Contact			contact;
	contact.init();
	contact.init_index(i % 8);
	this->contacts[i % 8] = contact;
	i++;
}

void	PhoneBook::search() {
	int i = 0;
	std::cout << "|        ID|First Name| Last Name|  Nickname|" << std::endl;
	while (i < 8) {
		this->contacts[i].display_short();
		i++;
	}
	i = get_input("Select a contact (0-7): ");
	display(i);
}

void	PhoneBook::display(int id) {
	this->contacts[id].display();
}

int	PhoneBook::get_input(std::string str) {
	int	input;

	while (true) {
		std::cout << str;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof()) {
				std::cout << std::endl << "Error occurs while reading" << std::endl;
				exit(1);
			}
			std::cout << "Invalid input, Try again" << std::endl;
			continue;
		}
		if (input >= 0 && input <= 7)
			break;
		std::cout << "Invalid number, Try again" << std::endl;
	}
	return (input);
}