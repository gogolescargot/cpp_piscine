/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:15:25 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 07:19:48 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _sign;
		const int _execute;
		bool _signed;

	public:
		Form();
		Form(const std::string, const int, const int);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		const std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSigned() const;
		void beSigned(const Bureaucrat&);
		void sign();

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
};

std::ostream &operator<<(std::ostream&, const Form&);


#endif