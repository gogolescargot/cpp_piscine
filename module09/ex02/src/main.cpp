/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:17:44 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/21 22:09:43 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
int main(int argc, char const *argv[])
{
	clock_t start, end;

	if (argc != 2)
	{
		std::cerr << "Error: Wrong argument number" << std::endl;
		return (1);
	}

	std::vector<int> vector;
	std::deque<int> deque;
	double elapsed_time_ms;
	
	if (checkArg(argv[1]))
	{
		return (1);
	}
	if (insertNbrVector(argv[1], vector))
	{
		return (1);
	}
	if (insertNbrDeque(argv[1], deque))
	{
		return (1);
	}

	std::cout << "Before: ";
	displayVector(vector);

	start = clock();
	mergeInsertionSortVector(vector);
	end = clock();

	std::cout << "After: ";
	displayVector(vector);
	
	elapsed_time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "Time Vector: " <<  elapsed_time_ms << "ms" << std::endl;


	std::cout << "Before: ";
	displayDeque(deque);

	start = clock();
	mergeInsertionSortDeque(deque);
	end = clock();

	std::cout << "After: ";
	displayDeque(deque);
	
	elapsed_time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "Time Deque: " <<  elapsed_time_ms << "ms" << std::endl;

	return (0);
}
