/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:49 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/07 17:45:41 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <limits>

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
void PmergeMe::printNumbers()
{
    std::cout << "Numbers: ";
    this->printContainer(this->numbers);
    std::cout << "Remain: ";
    this->printContainer(this->remain);
}



void PmergeMe::printVector(std::vector<int> numbers)
{
    if (numbers.empty())
    {
        std::cout << "[]";
        return;
    }
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
    if (first.back() < second.back())
    {
        i++;
        res.insert(res.end(), first.begin(), first.end());
        res.insert(res.end(), second.begin(), second.end());
    }
    else
    {
        i++;
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
void PmergeMe::forwardRecursion()
{
    std::vector<int> remain;
    if (this->numbers.size() == 1)
        return;
    if (this->numbers.size() % 2 != 0)
    {
        remain = this->numbers.back();
        numbers.pop_back();
    }
    this->marrySingles();
    this->forwardRecursion();
    std::cout << "conatainer: ";
    this->printContainer(this->numbers);
    std::cout << "remain: ";
    this->printVector(remain);
    std::cout << std::endl;
    this->backwardsRecursion(remain);
    // std::cout << "container: ";
    // this->printContainer(this->numbers);
    // std::cout << "remain: ";
    // this->printVector(remain);
    // std::cout << std::endl;
    // this->printContainer(this->numbers);
    // exit(1);
}

// [[1 2 3 4 5 6 7 8]] 
// [[1 2 3 4][5 6 7 8]]
// // m = [5 6 7 8]
// // p = [1 2 3 4]
// [[1 2][3 4][5 6][7 8]]
// // m = [3 4] [7 8]
// // p = [1 2] [5 6]
// [[1 2] [3 4] [5 6] [7 8]]


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

bool compare(std::vector<int> a, std::vector<int> b)
{
    i++;
    if (a.empty() || b.empty())
        return false;
    return a.back() < b.back();
}

void PmergeMe::backwardsRecursion(std::vector<int> remain)
{
    this->unpair();
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
    // for (int i = 0; i < static_cast<int>(pend.size()); i++)
    // {
    // std::cout << "mainchain: ";
    // this->printContainer(mainChain);
    // std::cout << "pend: ";
    // this->printContainer(pend);
    std::vector< std::vector<int> >::iterator it = pend.begin();
    while (pend.size() != 0)
    {
        std::vector< std::vector<int> >::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it, compare);
        mainChain.insert(pos, *it);
        pend.erase(it);
        this->numbers.clear();
        this->numbers = mainChain;
    }
    std::cout << "after lower bound insertino" << std::endl;
    std::cout << "mainChain: ";
    this->printContainer(mainChain);
    std::cout << "pand: ";
    this->printContainer(pend);
    // }
}
// [[1 2][3][4][5]]
// [6 8 1] [0 7 0]



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



// PmergeMe::~PmergeMe()
// {

// }

// PmergeMe::PmergeMe(const PmergeMe& other)
// {

// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& other)
// {

// }

