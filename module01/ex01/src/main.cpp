/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:34 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 19:13:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(5, "Horde");
	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[](zombies);
	std::cout << "end" << std::endl;
	return (0);
}
