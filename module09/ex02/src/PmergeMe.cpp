/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:49 by ggalon            #+#    #+#             */
/*   Updated: 2024/06/11 17:33:13 by ggalon           ###   ########.fr       */
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

int checkArg(const char *argv[])
{
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (j == 0 && argv[i][j] != '+' && !isdigit(argv[i][j]))
			{
				std::cerr << "Error: Invalid character" << std::endl;
				return (1);
			}
			if (j != 0 && !isdigit(argv[i][j]))
			{
				std::cerr << "Error: Invalid character" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int insertNbrVector(const char *argv[], std::vector<int>& vector)
{
	for (int i = 1; argv[i]; i++)
	{
		int nbr = atoi(argv[i]);
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

void insertionSortVector(std::vector<std::pair<int, int> >& pairs)
{
	int n = pairs.size();
	for (int i = 1; i < n; i++)
	{
		std::pair<int, int> key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].second > key.second)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
}

int binarySearchVector(const std::vector<int>& S, int end, int key)
{
	int begin = 0;
	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (S[mid] < key)
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

void insertElementsVector(std::vector<int>& S, const std::vector<std::pair<int, int> >& pairs, int last)
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
		int a = X[i * 2];
		int b = X[i * 2 + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	// Sort the larger elements from each pair
	insertionSortVector(pairs);

	// Recursively make pairs from the highest elements of each pairs
	mergeInsertionSortVector(S);

	// Insert at the start of S the element that was paired with the first and smallest element of S
	S.insert(S.begin(), pairs[0].first);

	// Insert the remaining elements into S using Jacobsthal numbers
	if (X.size() % 2 == 1)
		insertElementsVector(S, pairs, X[X.size() - 1]);
	else 
		insertElementsVector(S, pairs, -1);

	X = S;
	return (0);
}

// ==============================================================================================

int insertNbrDeque(const char *argv[], std::deque<int>& deque)
{
	for (int i = 1; argv[i]; i++)
	{
		int nbr = atoi(argv[i]);
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

void insertionSortDeque(std::deque<std::pair<int, int> >& pairs)
{
	int n = pairs.size();
	for (int i = 1; i < n; i++)
	{
		std::pair<int, int> key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].second > key.second)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
}

int binarySearchDeque(const std::deque<int>& S, int end, int key)
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

void insertElementsDeque(std::deque<int>& S, const std::deque<std::pair<int, int> >& pairs, int last)
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
		int a = X[i * 2];
		int b = X[i * 2 + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	insertionSortDeque(pairs);

	mergeInsertionSortDeque(S);

	S.insert(S.begin(), pairs[0].first);

	if (X.size() % 2 == 1)
		insertElementsDeque(S, pairs, X[X.size() - 1]);
	else 
		insertElementsDeque(S, pairs, -1);

	X = S;
	return (0);
}
