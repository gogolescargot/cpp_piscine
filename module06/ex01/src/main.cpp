/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:53:21 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/12 09:09:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *before = new Data;
	Data *after;
	uintptr_t raw;
	before->str = "test";
	std::cout << before->str << std::endl;
	raw = Serializer::serialize(before);
	std::cout << raw << std::endl;
	after = Serializer::deserialize(raw);
	std::cout << after->str << " == " << before->str << std::endl;
	delete before;
	return (0);
}
