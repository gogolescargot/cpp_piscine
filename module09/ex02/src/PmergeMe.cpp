/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:49 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/21 22:09:18 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void displayVector(std::vector<int>& vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void displayDeque(std::deque<int>& deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
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

// Function to insert elements into the sorted sequence
void insertElementsVector(std::vector<int> &S, const std::vector<std::pair<int, int> > &pairs, int last)
{
	for (size_t i = 1; i < pairs.size(); i++)
	{
		int position = binarySearchVector(S, S.size() - 1, pairs[i].first);
		S.insert(S.begin() + position, pairs[i].first);
	}
	if (last != -1)
	{
		int position = binarySearchVector(S, S.size() - 1, last);
		S.insert(S.begin() + position, last);
	}
		
}

// Function to insert elements into the sorted sequence
void insertElementsDeque(std::deque<int> &S, const std::deque<std::pair<int, int> > &pairs, int last)
{
	for (size_t i = 1; i < pairs.size(); i++)
	{
		int position = binarySearchDeque(S, S.size() - 1, pairs[i].first);
		S.insert(S.begin() + position, pairs[i].first);
	}
	if (last != -1)
	{
		int position = binarySearchDeque(S, S.size() - 1, last);
		S.insert(S.begin() + position, last);
	}
		
}

// Recursive function to sort the array using merge-insertion sort
int mergeInsertionSortVector(std::vector<int>& X)
{
	if (X.size() <= 1)
		return (0);

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> S;

	// Group elements into pairs and determine the larger element in each pair
	for (size_t i = 0; i < X.size() / 2; ++i)
	{
		int a = X[2 * i];
		int b = X[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	// Recursively sort the larger elements (stored in S)
	mergeInsertionSortVector(S);

	// Insert the element that was paired with the first and smallest element of S
	S.insert(S.begin(), pairs[0].first);

	// Insert the remaining elements into S
	if (X.size() % 2 == 1)
		insertElementsVector(S, pairs, X[X.size() - 1]);
	else 
		insertElementsVector(S, pairs, -1);

	// Copy the sorted sequence back to the original array
	X = S;
	return (0);
}

// Recursive function to sort the array using merge-insertion sort
int mergeInsertionSortDeque(std::deque<int>& X)
{
	if (X.size() <= 1)
		return (0);

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> S;

	// Group elements into pairs and determine the larger element in each pair
	for (size_t i = 0; i < X.size() / 2; ++i)
	{
		int a = X[2 * i];
		int b = X[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	// Recursively sort the larger elements (stored in S)
	mergeInsertionSortDeque(S);

	// Insert the element that was paired with the first and smallest element of S
	S.insert(S.begin(), pairs[0].first);

	// Insert the remaining elements into S
	if (X.size() % 2 == 1)
		insertElementsDeque(S, pairs, X[X.size() - 1]);
	else 
		insertElementsDeque(S, pairs, -1);

	// Copy the sorted sequence back to the original array
	X = S;
	return (0);
}
