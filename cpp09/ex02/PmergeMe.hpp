/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:53 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/07 17:30:13 by hoigag           ###   ########.fr       */
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
		void printNumbers();
		void forwardRecursion();
		void unpair();
		void backwardsRecursion(std::vector<int> remain);
		void marrySingles();
		std::vector< std::vector<int> > getNumbers();
		// ~PmergeMe();
		// PmergeMe(const PmergeMe& other);
		// PmergeMe& operator=(const PmergeMe& other);
	private:
		std::string input;
		std::vector< std::vector<int> > numbers;
		std::vector< std::vector<int> > remain;
};
std::string concat(char **args);
std::pair<std::vector<int>, std::vector<int> > slice(std::vector<int> main);

#endif
