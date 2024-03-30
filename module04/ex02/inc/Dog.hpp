/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:10:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 08:10:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog&);
		Dog &operator=(const Dog&);
		virtual ~Dog();

		void makeSound() const;
		void setIdeas(const std::string&, unsigned int) const;
		std::string getIdeas(unsigned int) const;
};

#endif
