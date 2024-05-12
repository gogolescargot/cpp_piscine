/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:47:05 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/12 07:55:20 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, const char **argv)
{
	if (argc != 2)
		return (1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
