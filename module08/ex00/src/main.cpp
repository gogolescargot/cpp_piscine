/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:10:54 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 09:31:05 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

void finded(bool b)
{
	if (b)
	{
		std::cout << "Element found" << std::endl;
	}
	else
	{
		std::cerr << "Element not found" << std::endl;
	}
}

int main()
{
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	finded(easyfind(vector, 3));
	finded(easyfind(vector, -2));

	std::deque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	deque.push_back(4);
	deque.push_back(5);
	finded(easyfind(deque, 5));
	finded(easyfind(deque, 10));

	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	finded(easyfind(list, 1));
	finded(easyfind(list, 999));
	return (0);
}
