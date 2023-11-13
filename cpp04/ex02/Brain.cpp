/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:41:54 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/13 10:28:09 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "idea" + std::to_string(i);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "index out of range";
}

void Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
        return;
    this->ideas[index] = idea;
}
