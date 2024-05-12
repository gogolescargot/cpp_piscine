/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:44:25 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/12 09:04:38 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>

struct Data
{
	std::string str;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data*);
		static Data* deserialize(uintptr_t);
};

#endif