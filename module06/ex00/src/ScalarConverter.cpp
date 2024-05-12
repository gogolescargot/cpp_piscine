/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:39:31 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/12 08:41:49 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int stoi(const std::string& s)
{
	int i;
	std::istringstream(s) >> i;
	return (i);
}

void display(const std::string& c, const std::string& i, const std::string& f, const std::string& d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

void display_special(int i)
{
	if (i <= 1)
		display("impossible", "impossible", "nanf", "nan");
	else if (i <= 3)
		display("impossible", "impossible", "+inff", "+inf");
	else
		display("impossible", "impossible", "-inff", "-inf");
}

void display_char(char c)
{
	std::string c_display;
	std::string i_display;
	std::string f_display;
	std::string d_display;

	std::stringstream ss;

	if (!std::isprint(c))
		ss << "Non displayable";
	else
		ss << "'" << static_cast<char>(c) << "'";
	c_display = ss.str();
	ss.str("");

	ss << static_cast<int>(c);
	i_display = ss.str();
	ss.str("");

	ss << static_cast<float>(c) << ".0f";
	f_display = ss.str();
	ss.str("");

	ss << static_cast<double>(c) << ".0";
	d_display = ss.str();

	display(c_display, i_display, f_display, d_display);
}

void display_number(double n)
{
	std::string c_display;
	std::string i_display;
	std::string f_display;
	std::string d_display;

	std::stringstream ss;

	if ((n < 0 || n > 255) || !std::isprint(n))
		ss << "Non displayable";
	else
		ss << "'" << static_cast<char>(n) << "'";
	c_display = ss.str();
	ss.str("");

	ss << static_cast<int>(n);
	i_display = ss.str();
	ss.str("");

	if (n == static_cast<int>(n))
		ss << static_cast<float>(n) << ".0f";
	else
		ss << static_cast<float>(n) << "f";
	f_display = ss.str();
	ss.str("");

	if (n == static_cast<int>(n))
		ss << static_cast<double>(n) << ".0";
	else
		ss << static_cast<double>(n);
	d_display = ss.str();

	display(c_display, i_display, f_display, d_display);
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		display_char(str[0]);
		return ;
	}

	std::string special[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	
	for (int i = 0; i < 6; i++)
	{
		if (str == special[i])
		{
			display_special(i);
			return ;
		}	
	}

	display_number(std::atof(str.c_str()));
}