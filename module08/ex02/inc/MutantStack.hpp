/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:36:29 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 12:58:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& src)
		{
			*this = src;
		}
		MutantStack& operator=(const MutantStack& src)
		{
			*this = src;
			return (*this);
		}

		typedef typename std::deque<T>::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};

#endif