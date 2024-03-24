/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:01:45 by ggalon            #+#    #+#             */
/*   Updated: 2024/03/23 23:01:45 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace(std::string buffer, std::string search, std::string replace)
{
	int i = 0;
	while (true)
	{
		i = buffer.find(search, i);
		if (i == -1)
			break ;
		buffer.erase(i, search.length());
		buffer.insert(i, replace);
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong parameters number" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::fstream infile;
	std::fstream outfile;
	
	std::string buffer;

	infile.open(filename.c_str(), std::fstream::in);
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return (1);
	}
	
	outfile.open((filename + ".replace").c_str(), std::fstream::out | std::fstream::trunc);
	if (!outfile.is_open())
	{
		infile.close();
		std::cerr << "Error: cannot create output file" << std::endl;
		return (1);
	}

	if (!s1.empty())
	{
		while (std::getline(infile, buffer))
		{
			outfile << replace(buffer, s1, s2);
		}
	}
	
	infile.close();
	outfile.close();
	
	return (0);
}
