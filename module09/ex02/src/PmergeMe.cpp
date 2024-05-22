/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:49 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/22 20:44:19 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t jacobsthal(size_t x)
{
	if (x == 0)
	{
		return (0);
	}
	if (x == 1)
	{
		return (1);
	}
	return (jacobsthal(x - 1) + 2 * jacobsthal(x - 2));
}

int checkArg(const std::string& arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] != '+' && arg[i] != ' ' && !isdigit(arg[i]))
		{
			std::cerr << "Error: Invalid character" << std::endl;
			return (1);
		}
	}
	return (0);
}

int insertNbrVector(const std::string& arg, std::vector<int>& vector)
{
	std::stringstream ss(arg);
	std::string element;

	while (std::getline(ss, element, ' '))
	{
		int nbr = atoi(element.c_str());
		if (std::find(vector.begin(), vector.end(), nbr) != vector.end())
		{
			std::cerr << "Error: Duplicate number" << std::endl;
			return (1);
		}
		vector.push_back(nbr);
	}
	return (0);
}

void displayVector(std::vector<int>& vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int binarySearchVector(const std::vector<int> &S, int end, int key)
{
	int begin = 0;
	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (S[mid] == key)
		{
			return (mid + 1);
		}
		else if (S[mid] < key)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return (begin);
}

void insertElementsVector(std::vector<int> &S, const std::vector<std::pair<int, int> > &pairs, int last)
{	
	for (size_t i = 1; jacobsthal(i - 1) < pairs.size() - 1; i++)
	{
		size_t idx = jacobsthal(i);
		size_t idx_prev = jacobsthal(i - 1);
		while (idx > idx_prev)
		{
			if (idx < pairs.size())
			{
				int position = binarySearchVector(S, S.size() - 1, pairs[idx].first);
				S.insert(S.begin() + position, pairs[idx].first);
			}
			idx--;
		}
	}
	if (last != -1)
	{
		int position = binarySearchVector(S, S.size() - 1, last);
		S.insert(S.begin() + position, last);
	}
}

// https://en.wikipedia.org/wiki/Merge-insertion_sort

int mergeInsertionSortVector(std::vector<int>& X)
{
	if (X.size() <= 1)
		return (0);

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> S;

	// Group elements into pairs and determine the larger element in each pair and leave the last one if odd elements
	for (size_t i = 0; i < X.size() / 2; ++i)
	{
		int a = X[2 * i];
		int b = X[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	// Recursively sort the larger elements from each pair
	mergeInsertionSortVector(S);

	// Insert at the start of S the element that was paired with the first and smallest element of S
	S.insert(S.begin(), pairs[0].first);

	// Insert the remaining elements into S
	if (X.size() % 2 == 1)
		insertElementsVector(S, pairs, X[X.size() - 1]);
	else 
		insertElementsVector(S, pairs, -1);

	X = S;
	return (0);
}

// ==============================================================================================

int insertNbrDeque(const std::string& arg, std::deque<int>& deque)
{
	std::stringstream ss(arg);
	std::string element;

	while (std::getline(ss, element, ' '))
	{
		int nbr = atoi(element.c_str());
		if (std::find(deque.begin(), deque.end(), nbr) != deque.end())
		{
			std::cerr << "Error: Duplicate number" << std::endl;
			return (1);
		}
		deque.push_back(nbr);
	}
	return (0);
}

void displayDeque(std::deque<int>& deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int binarySearchDeque(const std::deque<int> &S, int end, int key)
{
	int begin = 0;
	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (S[mid] == key)
		{
			return (mid + 1);
		}
		else if (S[mid] < key)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return (begin);
}

void insertElementsDeque(std::deque<int> &S, const std::deque<std::pair<int, int> > &pairs, int last)
{
	for (size_t i = 1; jacobsthal(i - 1) < pairs.size() - 1; i++)
	{
		size_t idx = jacobsthal(i);
		size_t idx_prev = jacobsthal(i - 1);
		while (idx > idx_prev)
		{
			if (idx < pairs.size())
			{
				int position = binarySearchDeque(S, S.size() - 1, pairs[idx].first);
				S.insert(S.begin() + position, pairs[idx].first);
			}
			idx--;
		}
	}
	if (last != -1)
	{
		int position = binarySearchDeque(S, S.size() - 1, last);
		S.insert(S.begin() + position, last);
	}
}

int mergeInsertionSortDeque(std::deque<int>& X)
{
	if (X.size() <= 1)
		return (0);

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> S;

	for (size_t i = 0; i < X.size() / 2; ++i)
	{
		int a = X[2 * i];
		int b = X[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	mergeInsertionSortDeque(S);

	S.insert(S.begin(), pairs[0].first);

	if (X.size() % 2 == 1)
		insertElementsDeque(S, pairs, X[X.size() - 1]);
	else 
		insertElementsDeque(S, pairs, -1);

	X = S;
	return (0);
}
