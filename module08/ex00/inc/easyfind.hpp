/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:11:30 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/16 09:13:58 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
bool easyfind(T container, int nbr)
{
	if (std::find(container.begin(), container.end(), nbr) != container.end())
		return (true);
	return (false);
}

#endif