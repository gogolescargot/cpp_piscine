/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 07:59:49 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 07:59:49 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

void print(bool bsp)
{
	if (bsp)
		std::cout << "In" << std::endl;
	else
		std::cout << "Out" << std::endl;
}

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point p0(4.99, 4.99);
	Point p1(5, 5);
	Point p2(0, 0);
	Point p3(-5, 20);
	Point p4(0.521, 5.412);

	print(bsp(a, b, c, p0));
	print(bsp(a, b, c, p1));
	print(bsp(a, b, c, p2));
	print(bsp(a, b, c, p3));
	print(bsp(a, b, c, p4));

	return (0);
}
