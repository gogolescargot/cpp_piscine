/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/22 20:01:41 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ex01.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void	Contact::init() {
	this->firstName = get_input("First name: ");
	this->lastName = get_input("Last name: ");
	this->nickName = get_input("Nickname : ");
	this->phoneNumber = get_input("Phone number: ");
	this->darkestSecret = get_input("Darkest secret: ");
}

void	Contact::init_index(int index) {
	this->index = index;
}

void	Contact::display_short() {
	if (this->phoneNumber.empty())
		return;
	std::cout << "|";
	std::cout << "         ";
	std::cout << (this->index);
	std::cout << "|";
	display_attribute(this->firstName);
	std::cout << "|";
	display_attribute(this->lastName);
	std::cout << "|";
	display_attribute(this->nickName);
	std::cout << "|";
	std::cout << std::endl;
}

void	Contact::display() {
	if (this->phoneNumber.empty()) {
		std::cout << "Contact not registered" << std::endl;;
		return;
	}
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickName << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
}

std::string	Contact::get_input(std::string str) {
	std::string input;
	while (true) {
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "Error occurs while reading" << std::endl;
			exit(1);
		}
		if (!input.empty())
			break;
		std::cout << "Invalid input, Try again" << std::endl;
	}
	return (input);
}

void	Contact::display_attribute(std::string str) {
	int i = 0;
	int p = 0;
	if (str.length() > 10)
		str[9] = '.';
	int l = 10 - str.length() ;
	while (p < l) {
		std::cout << " ";
		p++;
	}
	while (str[i] && p < 10) {
		std::cout << str[i];
		i++;
		p++;
	}
}
