/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:31:08 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 12:57:49 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::deque<int> deque;
		deque.push_back(5);
		deque.push_back(17);
		std::cout << deque.back() << std::endl;
		deque.pop_back();
		std::cout << deque.size() << std::endl;
		deque.push_back(3);
		deque.push_back(5);
		deque.push_back(737);
		//[...]
		deque.push_back(0);
		MutantStack<int>::iterator it = deque.begin();
		MutantStack<int>::iterator ite = deque.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(deque);
	}

	return 0;
}