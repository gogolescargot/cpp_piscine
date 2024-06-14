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

int main(int argc, const char *argv[])
{
	struct timeval start, end;
	double elapsedTime, s, us;

	if (argc < 2)
	{
		std::cout << "Error: Wrong argument number" << std::endl;
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

	gettimeofday(&start, NULL);
	mergeInsertionSortVector(vector);
	gettimeofday(&end, NULL);

	std::cout << "After: ";
	displayVector(vector);
	
	s = end.tv_sec - start.tv_sec;
	us = end.tv_usec  - start.tv_usec ;
	elapsedTime = s * 1000000.0 + us;

    std::cout << "Time Vector: " << elapsedTime << " us" << std::endl;

	gettimeofday(&start, NULL);
	mergeInsertionSortDeque(deque);
	gettimeofday(&end, NULL);

	s = end.tv_sec - start.tv_sec;
	us = end.tv_usec - start.tv_usec;
	elapsedTime = s * 1000000.0 + us;
	
	std::cout << "Time Deque: " << elapsedTime << " us" << std::endl;

	return (0);
}
