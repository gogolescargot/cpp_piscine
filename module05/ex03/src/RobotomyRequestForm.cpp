/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 06:34:06 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Target")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm("RobotomyRequestForm", 72, 45), _target("Target")
{
	(void)src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	(void)src;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		std::cout << "*drilling noise*" << std::endl;
		std::srand(std::time(0));
		int rand = std::rand() % 2;
		if (rand)
			std::cout << "Robotomy success " << this->getTarget() << std::endl;
		else
			std::cout << "Robotomy failed " << this->getTarget() << std::endl;

	}
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}
