/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:44 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/03 12:21:00 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		std::string input = concat(argv + 1);
		PmergeMe pmm(input);
		pmm.parseString();
		// pmm.printMyContainer();
		pmm.mergeInsertSmthSmth();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// std::cout << input << std::endl;
	// try
	// {
	// 	PmergeMe::parseString(input);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << input << std::endl;
	return (0);
}
