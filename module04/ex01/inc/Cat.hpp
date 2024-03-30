/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:10:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 08:10:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat&);
		Cat &operator=(const Cat&);
		virtual ~Cat();

		void makeSound() const;
		void setIdeas(const std::string&, unsigned int) const;
		std::string getIdeas(unsigned int) const;

};

#endif
