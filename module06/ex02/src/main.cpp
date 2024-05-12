/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:32:25 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/12 10:07:22 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	std::srand(std::time(0));
	int rand = std::rand() % 3;
	switch (rand)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << 'A' << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << 'B' << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << 'C' << std::endl;
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
}

void identify(Base& p)
{
	try 
	{
		dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
	}
	catch (const std::exception &e)
	{
		
	}
	try 
	{
		dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
	}
	catch (const std::exception &e)
	{
		
	}
	try 
	{
		dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
	}
	catch (const std::exception &e)
	{
		
	}
}

int main()
{
	Base *b = generate();
	identify(b);
	identify(*b);
	delete b;
	return (0);
}
