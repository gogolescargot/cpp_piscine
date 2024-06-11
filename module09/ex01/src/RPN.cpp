/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:17:42 by ggalon            #+#    #+#             */
/*   Updated: 2024/06/11 15:46:47 by ggalon           ###   ########.fr       */
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

	if (a == 0)
	{
		throw std::runtime_error("Error: Division by 0");
	}

	stack.push(b / a);
}

int rpn(std::string line)
{
	for (int i = 0; line[i]; i++)
	{
		if (!isdigit(line[i]) && line[i] != ' ' && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/' )
		{
			throw std::runtime_error("Error: Invalid character");
		}
	}

	std::stack<int> stack;
	std::stringstream ss(line);
    std::string element;
	int nbr;

	while (ss >> element)
	{
		if (element.length() != 1)
		{
			throw std::runtime_error("Error: Node too large");
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
				throw std::runtime_error("Error: Stack too small");
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
		throw std::runtime_error("Error: Stack not empty");
	}
	
	std::cout << stack.top() << std::endl;

	return (0);
}