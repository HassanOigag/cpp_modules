/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:13:37 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:27:07 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    this->type = other.type;
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "meoooow" << std::endl;
}

std::string Cat::getType(void) const
{
    return this->type;
}