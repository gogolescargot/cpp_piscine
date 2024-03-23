/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:09:08 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/22 19:09:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "ex01.hpp"

class PhoneBook {

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
		void	display(int id);
	
	private:
		Contact 	contacts[8];
		int			get_input(std::string str);
};

#endif
