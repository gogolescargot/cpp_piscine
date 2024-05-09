/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 20:13:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Target")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm("PresidentialPardonForm", 25, 5), _target("Target")
{
	(void)src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	(void)src;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else
		std::cout << "Zaphod Beeblebrox pardonned " << this->getTarget() << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}
