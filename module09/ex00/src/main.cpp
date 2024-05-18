/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:54:01 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/18 21:31:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void error(const std::string& msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

void insertData(const std::string& line, std::map<std::string, double>& map)
{
	if (line == "date,exchange_rate")
		return ;
		
	double value;
	std::stringstream ss(line.substr(11));
	ss >> value;

	std::string date(line.substr(0, 10));
	
	map.insert(std::pair<std::string, double>(date, value));
}

int data()
{
	std::ifstream infile;
	std::map<std::string, double> map;
	std::string line;

	infile.open("data.csv");
	if (infile.fail())
	{
		error("Cannot open file");
		return (1);
	}
	while (getline(infile, line))
	{
		insertData(line, map);
	}
	infile.close();
}

int exchange(const char *filepath)
{
	std::ifstream infile;
	std::map<std::string, double> map;
	std::string line;

	infile.open(filepath);
	if (infile.fail())
	{
		error("Cannot open file");
		return (1);
	}
	
	infile.close();
}

int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		error("Wrong argument number");
		return (1);
	}
	if (data())
	{
		return (1);
	}
	if (exchange(argv[1]))
	{
		return (1);
	}
	

	// for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }
	return (0);
}
