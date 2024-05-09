/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 05:49:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int sign, const int execute) : AForm(name, sign, execute)
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	(void)src;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > 137)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		std::fstream file;
		std::string filename;

		filename = executor.getName() + "_shrubbery";
		file.open(filename.c_str(), std::fstream::out);
		if (!file.is_open())
		{
			std::cerr << "Error: cannot open input file" << std::endl;
			return ;
		}
		file << "insert ascii art tree";
		file.close();
	}
}
