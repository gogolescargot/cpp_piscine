/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:23 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/27 08:44:25 by ggalon           ###   ########.fr       */
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
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap &operator=(const ClapTrap&);
		~ClapTrap();
		
		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

};

#endif