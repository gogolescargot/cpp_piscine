/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 04:34:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/08 06:05:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void setGrade(int);
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string, int);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat&);
		~Bureaucrat();
		const std::string getName() const; 
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
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

std::ostream &operator<<(std::ostream&, const Bureaucrat&);

#endif