/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:17:42 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/20 22:38:05 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void add(std::stack<int> &stack)
{
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b + a);
}

void subtract(std::stack<int> &stack)
{
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b - a);
}

void multiply(std::stack<int> &stack)
{
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b * a);
}

void divide(std::stack<int> &stack)
{
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b / a);
}

int rpn(std::string line)
{
	for (int i = 0; line[i]; i++)
	{
		if (line[i] != ' ' && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/' && !isdigit(line[i]))
		{
			std::cerr << "Error: Invalid character" << std::endl;
			return (1);
		}
	}
	std::stack<int> stack;
	std::stringstream ss(line);
    std::string element;
	int nbr;
	while (std::getline(ss, element, ' '))
	{
		if (element.length() != 1)
		{
			std::cerr << "Error: Node too large" << std::endl;
			return (1);
		}
		if (isdigit(element[0]))
		{
			nbr = atoi(element.c_str());
			stack.push(nbr);
		}
		else
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Stack too small" << std::endl;
				return (1);
			}
			switch (element[0])
			{
				case '+':
					add(stack);
					break;
				case '-':
					subtract(stack);
					break;
				case '*':
					multiply(stack);
					break;
				case '/':
					divide(stack);
					break;
			}
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: Stack too small" << std::endl;
		return (1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
}