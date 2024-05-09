/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 06:21:35 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		ShrubberyCreationForm(const std::string, const int, const int);
		std::string getTarget() const;
		void execute(const Bureaucrat&) const;
};

#endif