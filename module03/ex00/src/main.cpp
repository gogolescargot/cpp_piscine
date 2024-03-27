/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:33:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 09:00:50 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("claptrap");
	ct.attack("ennemy");
	ct.takeDamage(5);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.beRepaired(10);
	ct.attack("ennemy");
	ct.takeDamage(100);
	ct.beRepaired(10);
	return (0);
}
