/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:53 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/12 08:12:06 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
extern int i;
class PmergeMe
{
	public:
		PmergeMe(std::string input);
		void parseString();
		void printVector(std::vector<int> numbers);
		void printContainer(std::vector< std::vector<int> > container);
		
		void forwardRecursionVector();
		void unpairVector();
		void backwardsRecursionVector(std::vector<int> remain);
		void marrySinglesVector();
		void jacobSthalInsertionVector(std::vector< std::vector<int> >& mainChain, std::vector< std::vector<int> >& pend);
		std::vector< std::vector<int> > getNumbers();
		~PmergeMe();
	private:
		std::string input;
		std::vector< std::vector<int> > numbers;
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
};

std::string concat(char **args);
std::pair<std::vector<int>, std::vector<int> > slice(std::vector<int> main);

#endif
