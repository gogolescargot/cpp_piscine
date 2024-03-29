/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 06:24:48 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/26 06:24:48 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "../inc/Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const float, const float);
		Point(const Point&);
		~Point();
		Point &operator=(const Point&);
		float getX() const;
		float getY() const;
		void setX(const Fixed&);
		void setY(const Fixed&);
};

std::ostream &operator<<(std::ostream&, const Point&);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif