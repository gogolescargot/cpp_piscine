/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:51 by ggalon            #+#    #+#             */
/*   Updated: 2024/06/11 15:53:03 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>

int checkArg(const char *argv[]);

int mergeInsertionSortVector(std::vector<int>& vector);
int mergeInsertionSortDeque(std::deque<int>& vector);

int insertNbrVector(const char *argv[], std::vector<int>& vector);
int insertNbrDeque(const char *argv[], std::deque<int>& vector);

void displayVector(std::vector<int>& vector);
void displayDeque(std::deque<int>& vector);

#endif