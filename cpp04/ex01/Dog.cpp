/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:28:03 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/13 11:41:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& other)
{
    *this = other;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, other.brain->getIdea(i));
}

Dog& Dog::operator=(const Dog& other)
{
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, other.brain->getIdea(i));
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "wooof" << std::endl;
}

std::string Dog::getType(void) const
{
    return this->type;
}

Brain *Dog::getBrain(void) const
{
    return (this->brain);
}