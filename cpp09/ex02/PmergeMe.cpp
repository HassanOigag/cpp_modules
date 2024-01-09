/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:49 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/09 12:49:17 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <limits>

int JSSequence(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return JSSequence(index - 1) + 2 * JSSequence(index - 2);
}

std::vector<int> getRightSequence(int pendSize)
{
	std::vector<int> seq;
	int i = 0;
	while (true)
	{
        int jacobLmerd = JSSequence(i);
		if ( jacobLmerd > pendSize)
        {
            if (pendSize != JSSequence(i - 1))
                seq.push_back(pendSize);
			break;
        }
		seq.push_back(jacobLmerd);
		i++;
	}
	seq.erase(seq.begin());
	seq.erase(seq.begin());
	return seq;
}

int i = 0;

void printColored(std::string output, int flag)
{
    //1 red, 0 green
    if (flag)
        std::cout << "\033[31m" << output << "\033[0m";
    else
        std::cout << "\033[32m" << output << "\033[0m";
        
}

std::string concat(char **args)
{
    int i = 0;
    std::string output = "";
    while (args[i])
    {
        output += args[i];
        output += " ";
        i++;
    }
    return output;
}

static bool isValidNumber(std::string input)
{
    if (input.empty())
        return false;
    for (int i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    double number = strtod(input.c_str(), NULL);
    if ((number > std::numeric_limits<int>::max()) || number < 0)
        return false;
    return true;
}

PmergeMe::PmergeMe(std::string input)
{
    this->input = input;
}

void PmergeMe::parseString()
{
    std::stringstream stream;
    stream.str(input);  
    std::string soonToBeInt;
    while (std::getline(stream, soonToBeInt, ' '))
    {
        if (!isValidNumber(soonToBeInt))
            throw std::runtime_error("Error");
        double number = strtod(soonToBeInt.c_str(), NULL);
        int integer = static_cast<int>(number);
        std::vector<int> element;
        element.push_back(integer);    
        this->numbers.push_back(element);
    }
}

void PmergeMe::printContainer(std::vector< std::vector<int> > container)
{
    std::vector<std::vector<int> >::iterator it = container.begin();
    printColored("[", 1);
    while (it != container.end())
    {
        this->printVector(*it);
        it++;
    }
    printColored("]", 1);
    std::cout << std::endl;
}

void PmergeMe::printVector(std::vector<int> numbers)
{
    if (numbers.empty())
    {
        std::cout << "[]";
        return;
    }
    printColored("[", 0);
    std::vector<int>::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        std::cout << "\033[35m" << *it << "\033[0m";
        if (it + 1 != numbers.end())
            std::cout << " ";
        it++;
    }
    printColored("]", 0);
}
std::vector<int> concatVecs(std::vector<int>& first, std::vector<int>& second)
{
    std::vector<int> res;
    i++;
    if (first.back() < second.back())
    {
        res.insert(res.end(), first.begin(), first.end());
        res.insert(res.end(), second.begin(), second.end());
    }
    else
    {
        res.insert(res.end(), second.begin(), second.end());
        res.insert(res.end(), first.begin(), first.end());
    }
    first.clear();
    second.clear();
    return res;
}

std::pair<std::vector<int>, std::vector<int> > slice(std::vector<int> main)
{
    int middle = main.size() / 2;
    std::vector<int>::iterator it = main.begin();
    std::vector<int> vec1(it, it + middle);
    std::vector<int> vec2(it + middle, main.end());
    std::pair<std::vector<int>, std::vector<int> > pair;
    pair.first = vec1;
    pair.second = vec2;
    return pair;
}

bool compare(std::vector<int> a, std::vector<int> b)
{
    if (a.empty() || b.empty())
        return false;
    i++;
    return a.back() < b.back();
}

void PmergeMe::forwardRecursion()
{
    std::cout << "conatainer before pairing: ";
    this->printContainer(this->numbers);
    std::vector<int> remain;
    if (this->numbers.size() == 1)
    {
        std::cout << "done with pairing : ";
        this->printContainer(this->numbers);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        return;
    }
    if (this->numbers.size() % 2 != 0)
    {
        remain = this->numbers.back();
        numbers.pop_back();
    }
    this->marrySingles();
    std::cout << "conatainer after pairing: ";
    this->printContainer(this->numbers);
    std::cout << "remain: ";
    this->printVector(remain);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    this->forwardRecursion();
    this->backwardsRecursion(remain);
}

void PmergeMe::unpair()
{
    if (this->numbers[0].size() == 1)
        return;
    std::vector< std::vector<int> > holder;
    std::vector< std::vector<int> >::iterator it = this->numbers.begin();
    while (it != this->numbers.end())
    {
        std::pair<std::vector<int>, std::vector<int> > pair = slice(*it);
        holder.push_back(pair.first);
        holder.push_back(pair.second);
        it++;
    }
    this->numbers.clear();
    this->numbers = holder;
    holder.clear();
}


void PmergeMe::backwardsRecursion(std::vector<int> remain)
{
    std::cout << "container before unpairing: ";
    this->printContainer(this->numbers);
    this->unpair();
    std::cout << "container after unpairing: ";
    this->printContainer(this->numbers);
    std::vector< std::vector<int> > mainChain;
    std::vector< std::vector<int> > pend;
    
    for (int i = 0; i < (int)this->numbers.size(); i++)
    {
        if (i % 2 == 0)
            pend.push_back(this->numbers[i]);
        else
            mainChain.push_back(this->numbers[i]);
    }
    if (!remain.empty())
        pend.push_back(remain);
    std::cout << "mainChain: ";
    this->printContainer(mainChain);
    std::cout << "pand: ";
    this->printContainer(pend);
    this->jacobSthalInsertion(mainChain, pend);
    this->numbers.clear();
    this->numbers = mainChain;
    std::cout << "after lower bound insertion" << std::endl;
    std::cout << "mainChain: ";
    this->printContainer(mainChain);
    std::cout << "pand: ";
    this->printContainer(pend);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}



std::vector< std::vector<int> > PmergeMe::getNumbers()
{
    return this->numbers;
}
void PmergeMe::marrySingles()
{
    std::vector< std::vector<int> > holder = this->numbers;
    this->numbers.clear();
    std::vector< std::vector<int> >::iterator it = holder.begin();
    while (it != holder.end())
    {
        std::vector<int> res = concatVecs(*it, *(it + 1));
        this->numbers.push_back(res);
        it += 2;
    }
}

void PmergeMe::jacobSthalInsertion(std::vector< std::vector<int> >& mainChain, std::vector< std::vector<int> >& pend)
{
    std::vector<int> jacobSequence = getRightSequence(pend.size());
    std::cout << "jacob sequenc: ";
    this->printVector(jacobSequence);
    std::cout << std::endl;
    int jacobNumber = 0;
    int startingPos = 0;
    for (size_t i = 0; i < jacobSequence.size(); i++)
    {
        int rangeStart = jacobSequence[i];
        int indexToPush = rangeStart - 1;
        while (indexToPush >= startingPos)
        {
            if (indexToPush == 0)
            {
                mainChain.insert(mainChain.begin(), pend[indexToPush]);
                jacobNumber++;
            }
            else
            {
                std::vector<std::vector<int> >::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + jacobNumber + indexToPush, pend[indexToPush], compare);
                mainChain.insert(pos, pend[indexToPush]);
                jacobNumber++;
            }
            indexToPush--;
        }
        startingPos = rangeStart;
    }
}


// PmergeMe::~PmergeMe()
// {

// }

// PmergeMe::PmergeMe(const PmergeMe& other)
// {

// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& other)
// {

// }

