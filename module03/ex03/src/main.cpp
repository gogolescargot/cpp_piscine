/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:33:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 09:56:08 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("diamondtrap");
	dt.attack("ennemy");
	dt.takeDamage(5);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.beRepaired(10);
	dt.attack("ennemy");
	dt.takeDamage(100);
	dt.takeDamage(100);
	dt.beRepaired(10);
	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();
	return (0);
}
