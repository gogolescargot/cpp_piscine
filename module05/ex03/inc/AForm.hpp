/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:15:25 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 04:02:20 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _sign;
		const int _execute;
		bool _signed;

	public:
		AForm();
		AForm(const std::string, const int, const int);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		~AForm();
		const std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSigned() const;
		void beSigned(const Bureaucrat&);
		void sign();
		virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Grade too low");
		}
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Form not signed");
		}
	};
};

std::ostream &operator<<(std::ostream&, const AForm&);


#endif