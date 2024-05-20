/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:54:01 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/20 15:52:10 by ggalon           ###   ########.fr       */
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

int data(std::map<std::string, double> &map)
{
	std::ifstream infile;
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
	return (0);
}

void readData(const std::string &line, std::map<std::string, double> &map)
{
	if (line == "date | value" || line.empty())
		return ;
	
	if (line.length() < 14)
	{
		std::cerr << "Formatting error: Lengh" << std::endl;
		return ;
	}
	if (line.substr(10, 3) != " | ")
	{
		std::cerr << "Formatting error: ' | '" << std::endl;
		return ;
	}
	
	std::string date(line.substr(0, 10));
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i < 4 || i == 5 || i == 6 || i == 8 || i == 9) && !std::isdigit(date[i]))
		{
			std::cerr << "Formatting error: Date format" << std::endl;
			return ;
		}
		if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cerr << "Formatting error: Date format" << std::endl;
			return ;
		}
	}

	double value;
	std::stringstream ss(line.substr(13));
	ss >> value;
	if (value < 0 || value > 1000)
	{
		std::cerr << "Formatting error: Value" << std::endl;
		return ;
	}
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month > 12 || day > 31 || month == 0 || day == 0)
	{
		std::cerr << "Formatting error: Date value" << std::endl;
		return ;
	}
	
	double total;
	std::map<std::string, double>::iterator it;
	it = map.lower_bound(date);
	if (it == map.end())
	{
		it--;
		total = it->second;
	}
	else
	{
		total = it->second * value;
	}
	std::cout << date << " => " << value << " = " << total << std::endl;
}

int exchange(const char *filepath, std::map<std::string, double> &map)
{
	std::ifstream infile;
	std::string line;

	infile.open(filepath);
	if (infile.fail())
	{
		error("Cannot open file");
		return (1);
	}
	while (getline(infile, line))
	{
		readData(line, map);
	}
	infile.close();
	return (0);
}

int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		error("Wrong argument number");
		return (1);
	}

	std::map<std::string, double> map;
	if (data(map))
	{
		return (1);
	}
	if (exchange(argv[1], map))
	{
		return (1);
	}
	
	// int i;
	// for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// 	i++;
	// 	if (i == 250)
	// 		break ;
	// }
	return (0);
}
