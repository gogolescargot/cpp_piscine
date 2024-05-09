/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 06:34:19 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Target")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("ShrubberyCreationForm", 145, 137), _target("Target")
{
	(void)src;
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
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		std::fstream file;
		std::string filename;

		filename = this->getTarget() + "_shrubbery";
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

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}