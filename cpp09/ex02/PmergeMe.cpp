/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:49 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/04 17:25:40 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>

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
    double number = strtod(input.c_str(), nullptr);
    if (number > std::numeric_limits<int>::max() || number < 0)
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
        double number = strtod(soonToBeInt.c_str(), nullptr);
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
        return;
    std::vector<int>::iterator it = numbers.begin();
    printColored("[", 0);
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
    this->printContainer(this->numbers);
    this->forwardRecursion();
    this->printVector(remain);
    std::cout << std::endl;
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

