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
	Zombie *zombie = newZombie("Zombie01");
	zombie->announce();
	delete(zombie);
	randomChump("Zombie02");
	std::cout << "end" << std::endl;
	return (0);
}
