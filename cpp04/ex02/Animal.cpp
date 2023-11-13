/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:04:33 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/12 13:37:21 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "animal";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    this->type = other.type;
    return *this;
}

void Animal::makeSound(void) const
{
    std::cout << "??????" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}