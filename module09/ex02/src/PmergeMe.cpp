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
				std::cout << "Error: Invalid character" << std::endl;
				return (1);
			}
			if (j != 0 && !isdigit(argv[i][j]))
			{
				std::cout << "Error: Invalid character" << std::endl;
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
			std::cout << "Error: Duplicate number" << std::endl;
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

int findPairVector(std::vector<std::pair<int, int> > pairs, int nbr)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == nbr)
			return (pairs[i].first);
	}
	return (-1);
}

void insertElementsVector(std::vector<int>& S, const std::vector<std::pair<int, int> >& pairs, int last)
{	
	std::vector<int> SCopy(S);

	S.insert(S.begin(), findPairVector(pairs, S[0]));

	for (size_t i = 1; jacobsthal(i - 1) < pairs.size() - 1; i++)
	{
		size_t idx = jacobsthal(i);
		size_t idx_prev = jacobsthal(i - 1);
		while (idx > idx_prev)
		{
			if (idx < pairs.size())
			{
				int position = binarySearchVector(S, S.size() - 1, findPairVector(pairs, SCopy[idx]));
				S.insert(S.begin() + position, findPairVector(pairs, SCopy[idx]));
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

int mergeInsertionSortVector(std::vector<int>& X)
{
	if (X.size() <= 1)
		return (0);

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> S;

	for (size_t i = 0; i < X.size() / 2; i++)
	{
		int a = X[i * 2];
		int b = X[i * 2 + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	mergeInsertionSortVector(S);

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
			std::cout << "Error: Duplicate number" << std::endl;
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

int binarySearchDeque(const std::deque<int>& S, int end, int key)
{
	int begin = 0;
	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (S[mid] <= key)
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

int findPairDeque(std::deque<std::pair<int, int> > pairs, int nbr)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == nbr)
			return (pairs[i].first);
	}
	return (-1);
}

void insertElementsDeque(std::deque<int>& S, const std::deque<std::pair<int, int> >& pairs, int last)
{	
	std::deque<int> SCopy(S);

	S.insert(S.begin(), findPairDeque(pairs, S[0]));

	for (size_t i = 1; jacobsthal(i - 1) < pairs.size() - 1; i++)
	{
		size_t idx = jacobsthal(i);
		size_t idx_prev = jacobsthal(i - 1);
		while (idx > idx_prev)
		{
			if (idx < pairs.size())
			{
				int position = binarySearchDeque(S, S.size() - 1, findPairDeque(pairs, SCopy[idx]));
				S.insert(S.begin() + position, findPairDeque(pairs, SCopy[idx]));
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

	for (size_t i = 0; i < X.size() / 2; i++)
	{
		int a = X[i * 2];
		int b = X[i * 2 + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		S.push_back(b);
	}

	mergeInsertionSortDeque(S);

	if (X.size() % 2 == 1)
		insertElementsDeque(S, pairs, X[X.size() - 1]);
	else 
		insertElementsDeque(S, pairs, -1);

	X = S;
	return (0);
}
