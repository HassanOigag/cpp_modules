/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:49 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/12 19:19:50 by hoigag           ###   ########.fr       */
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

template <typename CONTAINER>
CONTAINER getRightSequence(int pendSize)
{
	CONTAINER seq;
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
        std::deque<int> dequeElement;
        dequeElement.push_back(integer);    
        this->myDeque.push_back(dequeElement);
    }
}
template <typename CONTAINER>
void printVector(CONTAINER numbers)
{
    if (numbers.empty())
    {
        std::cout << "[]";
        return;
    }
    printColored("[", 0);
    typename CONTAINER::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        std::cout << "\033[35m" << *it << "\033[0m";
        if (it + 1 != numbers.end())
            std::cout << " ";
        it++;
    }
    printColored("]", 0);
}
template <typename CONTAINER>
void printContainer(CONTAINER container)
{
    typename CONTAINER::iterator it = container.begin();
    printColored("[", 1);
    while (it != container.end())
    {
        printVector(*it);
        it++;
    }
    printColored("]", 1);
    std::cout << std::endl;
}
template <typename CONTAINER>
CONTAINER concatVecs(CONTAINER& first, CONTAINER& second)
{
    CONTAINER res;
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

template <typename CONTAINER>
std::pair<CONTAINER, CONTAINER > slice(CONTAINER main)
{
    int middle = main.size() / 2;
    typename CONTAINER::iterator it = main.begin();
    CONTAINER first(it, it + middle);
    CONTAINER second(it + middle, main.end());
    std::pair<CONTAINER, CONTAINER > pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

template <typename CONTAINER>
bool compare(CONTAINER a, CONTAINER b)
{
    i++;
    return a.back() < b.back();
}

void PmergeMe::forwardRecursionDeque()
{
    std::cout << "conatainer before pairing: ";
    printContainer(this->myDeque);
    std::deque<int> remain;
    if (this->myDeque.size() == 1)
    {
        std::cout << "done with pairing : ";
        printContainer(this->myDeque);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        return;
    }
    if (this->myDeque.size() % 2 != 0)
    {
        remain = this->myDeque.back();
        myDeque.pop_back();
    }
    this->marrySinglesDeque();
    std::cout << "conatainer after pairing: ";
    printContainer(this->numbers);
    std::cout << "remain: ";
    printVector(remain);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    this->forwardRecursionDeque();
    this->backwardsRecursionDeque(remain);
}
void PmergeMe::forwardRecursionVector()
{
    std::cout << "conatainer before pairing: ";
    printContainer(this->numbers);
    std::vector<int> remain;
    if (this->numbers.size() == 1)
    {
        std::cout << "done with pairing : ";
        printContainer(this->numbers);
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
    this->marrySinglesVector();
    std::cout << "conatainer after pairing: ";
    printContainer(this->numbers);
    std::cout << "remain: ";
    printVector(remain);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    this->forwardRecursionVector();
    this->backwardsRecursionVector(remain);
}

void PmergeMe::unpairVector()
{
    if (this->numbers[0].size() == 1)
        return;
    std::vector< std::vector<int> > holder;
    std::vector< std::vector<int> >::iterator it = this->numbers.begin();
    while (it != this->numbers.end())
    {
        std::pair<std::vector<int>, std::vector<int> > pair = slice<std::vector<int> >(*it);
        holder.push_back(pair.first);
        holder.push_back(pair.second);
        it++;
    }
    this->numbers.clear();
    this->numbers = holder;
    holder.clear();
}
void PmergeMe::unpairDeque()
{
    if (this->myDeque[0].size() == 1)
        return;
    std::deque< std::deque<int> > holder;
    std::deque< std::deque<int> >::iterator it = this->myDeque.begin();
    while (it != this->myDeque.end())
    {
        std::pair<std::deque<int>, std::deque<int> > pair = slice<std::deque<int> >(*it);
        holder.push_back(pair.first);
        holder.push_back(pair.second);
        it++;
    }
    this->myDeque.clear();
    this->myDeque = holder;
    holder.clear();
}


void PmergeMe::backwardsRecursionVector(std::vector<int> remain)
{
    std::cout << "container before unpairing: ";
    printContainer(this->numbers);
    this->unpairVector();
    std::cout << "container after unpairing: ";
    printContainer(this->numbers);
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
    printContainer(mainChain);
    std::cout << "pand: ";
    printContainer(pend);
    this->jacobSthalInsertionVector(mainChain, pend);
    this->numbers.clear();
    this->numbers = mainChain;
    std::cout << "after lower bound insertion" << std::endl;
    std::cout << "mainChain: ";
    printContainer(mainChain);
    std::cout << "pand: ";
    printContainer(pend);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void PmergeMe::backwardsRecursionDeque(std::deque<int> remain)
{
    std::cout << "container before unpairing: ";
    printContainer(this->numbers);
    this->unpairDeque();
    std::cout << "container after unpairing: ";
    printContainer(this->numbers);
    std::deque< std::deque<int> > mainChain;
    std::deque< std::deque<int> > pend;
    
    for (int i = 0; i < (int)this->myDeque.size(); i++)
    {
        if (i % 2 == 0)
            pend.push_back(this->myDeque[i]);
        else
            mainChain.push_back(this->myDeque[i]);
    }
    if (!remain.empty())
        pend.push_back(remain);
    std::cout << "mainChain: ";
    printContainer(mainChain);
    std::cout << "pand: ";
    printContainer(pend);
    this->jacobSthalInsertionDeque(mainChain, pend);
    this->myDeque.clear();
    this->myDeque = mainChain;
    std::cout << "after lower bound insertion" << std::endl;
    std::cout << "mainChain: ";
    printContainer(mainChain);
    std::cout << "pand: ";
    printContainer(pend);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}



std::vector< std::vector<int> > PmergeMe::getNumbers()
{
    return this->numbers;
}
std::deque< std::deque<int> > PmergeMe::getDeque()
{
    return this->myDeque;
}

void PmergeMe::marrySinglesVector()
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
void PmergeMe::marrySinglesDeque()
{
    std::deque< std::deque<int> > holder = this->myDeque;
    this->myDeque.clear();
    std::deque< std::deque<int> >::iterator it = holder.begin();
    while (it != holder.end())
    {
        std::deque<int> res = concatVecs(*it, *(it + 1));
        this->myDeque.push_back(res);
        it += 2;
    }
}

void PmergeMe::jacobSthalInsertionVector(std::vector< std::vector<int> >& mainChain, std::vector< std::vector<int> >& pend)
{
    std::vector<int> jacobSequence = getRightSequence<std::vector<int> >(pend.size());
    std::cout << "jacob sequenc: ";
    printVector(jacobSequence);
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
                std::vector<std::vector<int> >::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + jacobNumber + indexToPush, pend[indexToPush], compare<std::vector<int> >);
                mainChain.insert(pos, pend[indexToPush]);
                jacobNumber++;
            }
            indexToPush--;
        }
        startingPos = rangeStart;
    }
}
void PmergeMe::jacobSthalInsertionDeque(std::deque< std::deque<int> >& mainChain, std::deque< std::deque<int> >& pend)
{
    std::deque<int> jacobSequence = getRightSequence<std::deque<int> >(pend.size());
    std::cout << "jacob sequenc: ";
    printVector(jacobSequence);
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
                std::deque<std::deque<int> >::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + jacobNumber + indexToPush, pend[indexToPush], compare<std::deque<int> >);
                mainChain.insert(pos, pend[indexToPush]);
                jacobNumber++;
            }
            indexToPush--;
        }
        startingPos = rangeStart;
    }
}


PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    this->input = other.input;
    this->numbers = other.numbers;
    return *this;
}

