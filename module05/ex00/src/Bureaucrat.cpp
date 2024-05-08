/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 04:34:55 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 06:45:11 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(75)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	_grade = src.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat()
{

}

std::string const Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		_grade = 1;
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw (Bureaucrat::GradeTooLowException());
	}
	else
		_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(--_grade);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(++_grade);
}