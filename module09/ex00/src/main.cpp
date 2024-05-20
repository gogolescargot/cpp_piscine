/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:54:01 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/20 22:49:25 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << ("Error: Wrong argument number") << std::endl;
		return (1);
	}
	btc(argv[1]);
	return (0);
}
