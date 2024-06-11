/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:45:03 by ggalon            #+#    #+#             */
/*   Updated: 2024/06/11 14:12:51 by ggalon           ###   ########.fr       */
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

int dateFormat(const std::string &date)
{
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i <= 3 || i == 5 || i == 6 || i == 8 || i == 9) && !std::isdigit(date[i]))
		{
			std::cerr << "Formatting error: Date format" << std::endl;
			return (1);
		}
		if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cerr << "Formatting error: Date format" << std::endl;
			return (1);
		}
	}

	return (0);
}

int dateValid(const std::string &date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

	if (month > 12 || month == 0 || day == 0)
	{
		std::cerr << "Formatting error: Date value" << std::endl;
		return (1);
	}

	int maxDate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (leap)
	{
		maxDate[1] = 29;
	}

	if (day > maxDate[month - 1])
	{
		std::cerr << "Formatting error: Date not possible" << std::endl;
		return (1);
	}

	return (0);
}

int readDate(const std::string &line, std::string &date)
{
	if (line == "date | value" || line.empty())
	{
		return (1);
	}

	if (line.length() < 14)
	{
		std::cerr << "Formatting error: Lengh" << std::endl;
		return (1);
	}

	if (line.substr(10, 3) != " | ")
	{
		std::cerr << "Formatting error: ' | '" << std::endl;
		return (1);
	}

	date = line.substr(0, 10);

	if (dateFormat(date))
	{
		return (1);
	}

	if (dateValid(date))
	{
		return (1);
	}

	return (0);
}

int readValue(const std::string &line, double &value)
{
	std::stringstream ss(line.substr(13));
	ss >> value;
	
	if (value < 0 || value > 1000)
	{
		std::cerr << "Formatting error: Value" << std::endl;
		return (1);
	}

	return (0);
}

void displayResult(const std::string &date, const double &value, std::map<std::string, double> &map)
{
	double total;
	std::map<std::string, double>::iterator it;

	it = map.lower_bound(date);

	if (it == map.end())
	{
		it--;
		total = it->second * value;
	}
	else
	{
		total = it->second * value;
	}

	std::cout << date << " => " << value << " = " << total << std::endl;
}

int exchangeBtc(const std::string& filepath, std::map<std::string, double> &map)
{
	std::ifstream infile;
	std::string line;

	infile.open(filepath.c_str());

	if (infile.fail())
	{
		error("Cannot open file");
		return (1);
	}

	std::string date;
	double value;

	while (getline(infile, line))
	{
		if (readDate(line, date))
			continue;
		if (readValue(line, value))
			continue;
		displayResult(date, value, map);
	}
	
	infile.close();
		
	return (0);
}

int btc(const std::string& filepath)
{
	std::map<std::string, double> map;
	if (data(map))
	{
		return (1);
	}

	if (exchangeBtc(filepath, map))
	{
		return (1);
	}

	return (0);
}