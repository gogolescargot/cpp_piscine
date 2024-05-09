/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:15:29 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 05:36:22 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _sign(75), _execute(75), _signed(false)
{
	
}

AForm::AForm(const std::string name, const int sign, const int execute) : _name(name), _sign(sign), _execute(execute), _signed(false)
{
	if (_sign < 1 || _sign > 150)
		throw (AForm::GradeTooHighException());
	else if (_execute < 1 || _execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm& src) : _name(src.getName()), _sign(src.getSignGrade()), _execute(src.getExecuteGrade()), _signed(src.getSigned())
{
	if (_sign < 1 || _sign > 150)
		throw (AForm::GradeTooHighException());
	else if (_execute < 1 || _execute > 150)
		throw (AForm::GradeTooLowException());
}


AForm::~AForm()
{
	
}

AForm& AForm::operator=(const AForm& src)
{
	_signed = src._signed;
	return (*this);
}

const std::string AForm::getName() const
{
	return (_name);
}

int AForm::getSignGrade() const
{
	return (_sign);
}

int AForm::getExecuteGrade() const
{
	return (_execute);
}

bool AForm::getSigned() const
{
	return (_signed);
}

void AForm::sign()
{
	_signed = true;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	else
		this->sign();
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << src.getName() << ", " << src.getSignGrade() << ", " << src.getExecuteGrade() << ", " << src.getSigned();
	return (os);
}