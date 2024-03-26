/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:00:53 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 19:21:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap(std::string);
		ScavTrap(const ScavTrap&);
		ScavTrap &operator=(const ScavTrap&);
		~ScavTrap();

		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

		unsigned int getHealth() const;
		unsigned int getEnergy() const;
		std::string getName() const;
		void displayStats();

	private:
		std::string _name;
		unsigned int _health;
		unsigned int _energy;
		unsigned int _damage;

};

bool checkScavTrap(const ScavTrap&, std::string str);

#endif