/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:22:30 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/22 19:22:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "ex01.hpp"

class Contact {

	public:
		Contact();
		~Contact();
		void	init();
		void	init_index(int i);
		void	display_short();
		void	display();

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		int			index;
		std::string	get_input(std::string str);
		void		display_attribute(std::string str);

};

#endif