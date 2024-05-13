/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:08:52 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/13 15:37:41 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void iter(T* array, std::size_t size, void (*function)(T&))
{
	for (std::size_t i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

#endif