/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:31:20 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 06:31:20 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
	float area = 0.5 * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));

	if (area < 0)
		area *= -1;
	
	Fixed area_f(area);

	return (area_f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a0 = area(a, b, c);
	Fixed a1 = area(point, a, b);
	Fixed a2 = area(point, b, c);
	Fixed a3 = area(point, c, a);

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	
	return (a1 + a2 + a3 == a0);
}
