/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:33:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 18:53:51 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap cp("Gauthier");
    cp.attack("Olivier");
    cp.takeDamage(5);
    cp.displayStats();
    cp.beRepaired(10);
    cp.displayStats();
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.beRepaired(10);
    cp.displayStats();
    cp.attack("Guilhem");
    cp.takeDamage(100);
    cp.displayStats();
    cp.beRepaired(10);
    return (0);
}
