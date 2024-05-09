/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:30:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 19:49:12 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		AForm* makeForm(std::string, std::string);
};

#endif