/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:16:27 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/05 18:23:59 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <ctime>

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

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    this->N = other.N;
    this->currentSize = other.currentSize;
    this->span = other.span;
    return *this;
}

void Span::addNumber(int n)
{
    
    if (this->currentSize >= N)
        throw std::runtime_error("the span is full");
    this->span.push_back(n);
    this->currentSize += 1;
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
    return (std::abs(distance));
}

unsigned int Span::shortestSpan()
{
    std::vector<int> distances;
    std::sort(this->span.begin(), this->span.end());
    std::vector<int>::iterator it = this->span.begin();
    while (it != this->span.cend())
    {
        if (it + 1 == this->span.cend())
            break;
        distances.push_back(std::abs(*(it + 1) - *it));
        it++;
    }
    return *std::min_element(distances.cbegin(), distances.cend());
}

void Span::fillSpan(int min, int max)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < this->N; i++)
    {
        int randomInt = min + (rand() % (max - min + 1));
        this->addNumber(randomInt);
    }
}
