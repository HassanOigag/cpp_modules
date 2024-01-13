/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:44 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/13 17:26:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <time.h>

double getTimeOfExecution(PmergeMe& pmm, std::string container)
{
	double start, end;
	start = static_cast<double>(clock()) / CLOCKS_PER_SEC;
	if (container == "vector")
		pmm.forwardRecursionVector();
	else
		pmm.forwardRecursionDeque();
	end = static_cast<double>(clock()) / CLOCKS_PER_SEC;
	double time = end - start;
	return time;
}

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
		std::cout << "Before: ";
		printContainer(pmm.getNumbers());
		double vectorTime = getTimeOfExecution(pmm, "vector");
		double dequeTime = getTimeOfExecution(pmm, "deque");
		std::cout << "After : ";
		printContainer(pmm.getNumbers());

		std::cout << "Time to process a range of " << pmm.getNumbers().size() << " elements with std::vector : "<< vectorTime <<" us" << std::endl;
		std::cout << "Time to process a range of " << pmm.getNumbers().size() << " elements with std::deque  : "<< dequeTime <<" us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
