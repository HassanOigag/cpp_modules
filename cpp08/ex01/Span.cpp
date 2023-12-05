/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:16:27 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/05 14:18:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span()
{
    this->N = 0;
    this->currentSize = 0;
}
Span::Span(unsigned int N)
{
    this->N = N;
    this->currentSize = 0;
}

Span::~Span()
{

}

// Span::Span(const Span& other)
// {

// }

// Span& Span::operator=(const Span& other)
// {
    
// }

void Span::addNumber(int n)
{
    
    if (this->currentSize >= N)
        throw std::runtime_error("the span is full");
    this->span.push_back(n);
    this->currentSize += 1;
}


void Span::fillSpan()
{
    
}

void Span::printSpan() const
{
    std::vector<int>::const_iterator it = this->span.cbegin();
    while (it != this->span.cend())
    {
        std::cout << *it << " ";
        it++;
    }
}

unsigned int Span::longestSpan()
{
    int max = *std::max_element(this->span.cbegin(), this->span.cend());
    int min = *std::min_element(this->span.cbegin(), this->span.cend());
    int distance = max - min;
    return ((distance > 0) ? distance : -distance);
}

unsigned int Span::shortestSpan()
{
    std::vector<int>::const_iterator first = this->span.cbegin();
    std::vector<int>    distances;
    while (first != this->span.cend())
    {
        std::vector<int>::const_iterator second = this->span.cbegin();
        while (second != this->span.cend())
        {
            if (first != second)
            {
                int distance = *first - *second;
                if (distance < 0)
                    distances.push_back(-distance);
                else
                    distances.push_back(distance);
            }
            second++;
        }
        first++;
    }
    return *std::min_element(distances.cbegin(), distances.cend());;
}

void Span::fillSpan()
{
    
}