/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:44 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/08 17:30:32 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int JSSequence(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return JSSequence(index - 1) + 2 * JSSequence(index - 2);
}
std::vector<int> jacobStahlSeq(int n)
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    int tmp;


    int i = 2;
    tmp = 0;
    while (tmp < n)
    {
        tmp = seq[i - 1] + 2 * seq[i - 2];
        if (tmp > n)
            tmp = n;
        else
            seq.push_back(tmp);
        i++;
    }
    seq.erase(seq.begin());
    seq.erase(seq.begin());
	for (int i = 0; i < (int) seq.size(); i++)
		std::cout << seq[i] <<  " " ;
    return seq;
}
std::vector<int> getRightSequence(int pendSize)
{
	// int tmp = 0;
	std::vector<int> seq;
	int i = 0;
	while (1)
	{
		if (JSSequence(i) > pendSize)
			break;
		seq.push_back(JSSequence(i));
		i++;
	}
	seq.erase(seq.begin());
	seq.erase(seq.begin());
	for (size_t i = 0; i < seq.size(); i++)
	{
		std::cout << seq[i] << " ";
	}
	
	return seq;
}
int main(int argc, char __unused **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	jacobStahlSeq(1);
	std::cout << std::endl;
	getRightSequence(1);
	// jacobStahlSeq(3);
	// try
	// {
	// 	std::string input = concat(argv + 1);
	// 	PmergeMe pmm(input);
	// 	pmm.parseString();
	// 	// pmm.printContainer(pmm.getNumbers());
	// 	pmm.forwardRecursion();
	// 	pmm.printContainer(pmm.getNumbers());
	// 	std::cout << "comparaisons: " << i << std::endl;
	// 	// pmm.printContainer(pmm.getNumbers());
	// 	// pmm.printNumbers();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	return (0);
}
