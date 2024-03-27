/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:33:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 09:55:16 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap ft("fragtrap");
	ft.attack("ennemy");
	ft.takeDamage(5);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.beRepaired(10);
	ft.attack("ennemy");
	ft.takeDamage(100);
	ft.takeDamage(100);
	ft.beRepaired(10);
	ft.highFivesGuys();
	return (0);
}
