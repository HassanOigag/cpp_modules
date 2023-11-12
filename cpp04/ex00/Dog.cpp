/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:28:03 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/12 13:40:48 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    this->type = other.type;
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