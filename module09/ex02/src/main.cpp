/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:17:44 by ggalon            #+#    #+#             */
/*   Updated: 2024/06/11 17:02:03 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
int main(int argc, const char *argv[])
{
	struct timespec start, end;
	double elapsedTime, s, us;

	if (argc < 2)
	{
		std::cerr << "Error: Wrong argument number" << std::endl;
		return (1);
	}

	std::vector<int> vector;
	std::deque<int> deque;
	
	if (checkArg(argv))
	{
		return (1);
	}
	if (insertNbrVector(argv, vector))
	{
		return (1);
	}
	if (insertNbrDeque(argv, deque))
	{
		return (1);
	}

	std::cout << "Before: ";
	displayVector(vector);

	clock_gettime(CLOCK_MONOTONIC, &start);
	mergeInsertionSortVector(vector);
	clock_gettime(CLOCK_MONOTONIC, &end);

	std::cout << "After: ";
	displayVector(vector);
	
	s = end.tv_sec - start.tv_sec;
	us = end.tv_nsec - start.tv_nsec;
	elapsedTime = s * 1000000 + us / 1;

    std::cout << "Time Vector: " << elapsedTime << " us" << std::endl;

	std::cout << "Before: ";
	displayDeque(deque);

	clock_gettime(CLOCK_MONOTONIC, &start);
	mergeInsertionSortDeque(deque);
	clock_gettime(CLOCK_MONOTONIC, &end);

	std::cout << "After: ";
	displayDeque(deque);

	s = end.tv_sec - start.tv_sec;
	us = end.tv_nsec - start.tv_nsec;
	elapsedTime = s * 1000000 + us / 1;
	
	std::cout << "Time Deque: " << elapsedTime << " us" << std::endl;

	return (0);
}
