/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 06:29:23 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/09 06:29:52 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		PresidentialPardonForm(const std::string, const int, const int);
		std::string getTarget() const;
		void execute(const Bureaucrat&) const;
};

#endif