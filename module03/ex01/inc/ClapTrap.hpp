/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:23 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 18:55:57 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _health;
		unsigned int _energy;
		unsigned int _damage;

	public:
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap&);
		~ClapTrap();
		
		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

		unsigned int getHealth() const;
		unsigned int getEnergy() const;
		std::string getName() const;
		void displayStats();

};

bool checkClapTrap(const ClapTrap&, std::string str);

#endif