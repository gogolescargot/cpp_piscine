/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:15:29 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 07:29:13 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Form"), _sign(75), _execute(75), _signed(false)
{
	
}

Form::Form(const std::string name, const int sign, const int execute) : _name(name), _sign(sign), _execute(execute), _signed(false)
{
	if (_sign < 1 || _sign > 150)
		throw (Form::GradeTooHighException());
	else if (_execute < 1 || _execute > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
	
}

const std::string Form::getName() const
{
	return (_name);
}

int Form::getSignGrade() const
{
	return (_sign);
}

int Form::getExecuteGrade() const
{
	return (_execute);
}

bool Form::getSigned() const
{
	return (_signed);
}

void Form::sign()
{
	_signed = true;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (Form::GradeTooLowException());
	else
		this->sign();
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << src.getName() << ", " << src.getSignGrade() << ", " << src.getExecuteGrade() << ", " << src.getSigned();
	return (os);
}