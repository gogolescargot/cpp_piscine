/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:33:27 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 09:36:25 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap st("scavtrap");
	st.attack("ennemy");
	st.takeDamage(5);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.beRepaired(10);
	st.attack("ennemy");
	st.takeDamage(100);
	st.takeDamage(100);
	st.beRepaired(10);
	st.guardGate();
	st.guardGate();
	return (0);
}
