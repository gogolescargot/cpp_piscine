/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:36:29 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 12:24:51 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <exception>
# include <iostream>

class Span
{
	private:
		std::multiset<int>_array;
		unsigned int _max;
		Span();
	public:
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		void addNumber(int);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::multiset<int>::iterator getBegin();
		std::multiset<int>::iterator getEnd();
		~Span();

		template <typename T>
		void addNumbers(T begin, T end)
		{
			for (; begin != end; begin++)
			{
				addNumber(*begin);
			}
		}
};

#endif