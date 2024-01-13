/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:44 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/13 13:41:44 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <time.h>
int main(int argc, char __unused **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	try
	{
		double start, end;
		std::string input = concat(argv + 1);
		PmergeMe pmm(input);
		start = static_cast<double>(clock()) / CLOCKS_PER_SEC;
		pmm.parseString();
		// pmm.printContainer(pmm.getDeque());
		pmm.forwardRecursionVector();
		end = static_cast<double>(clock()) / CLOCKS_PER_SEC;
		// pmm.printContainer(pmm.getNumbers());
		std::cout << start  << " " <<  end << std::endl;
		double time = end - start;
		std::cout << "len : " << pmm.getDeque().size() << std::endl;
		std::cout << "comparaisons: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(15)<< "time elapsed : " << time << std::endl;
		// pmm.printContainer(pmm.getNumbers());
		// pmm.printNumbers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
