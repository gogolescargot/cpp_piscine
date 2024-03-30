/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:27:01 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/30 08:27:01 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Cat* cat = new Cat();
	const Dog* dog = new Dog();

	cat->setIdeas("im a cat", 5);
	std::cout << cat->getIdeas(5) << std::endl;

	dog->setIdeas("im a dog", 5);
	std::cout << dog->getIdeas(5) << std::endl;

	const Dog* dog2 = new Dog(*dog);
	delete(dog);
	std::cout << dog2->getIdeas(5) << std::endl;

	delete(cat);
	delete(dog2);
	
	return (0);
}