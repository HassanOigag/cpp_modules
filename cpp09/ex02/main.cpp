/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:44 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/12 08:07:22 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"


int main(int argc, char __unused **argv)
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
		// pmm.printContainer(pmm.getNumbers());
		pmm.forwardRecursionVector();
		pmm.printContainer(pmm.getNumbers());
		std::cout << "len : " << pmm.getNumbers().size() << std::endl;
		std::cout << "comparaisons: " << i << std::endl;
		// pmm.printContainer(pmm.getNumbers());
		// pmm.printNumbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
