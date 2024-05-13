/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:06:04 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/13 15:36:06 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void opposite(int& nbr)
{
	nbr *= -1;
}

void capitalize(std::string& str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
}

void print_array_nbr(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void print_array_str(std::string *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main( void )
{
	int array_nbr[] = {0, 1, 2, 3, 4, 5};
	std::string array_str[] = {"a", "b", "c", "d", "e", "f"};
	
	print_array_nbr(array_nbr, 6);
	iter(array_nbr, 6, &opposite);
	print_array_nbr(array_nbr, 6);

	print_array_str(array_str, 6);
	iter(array_str, 6, &capitalize);
	print_array_str(array_str, 6);
	
	return (0);
}