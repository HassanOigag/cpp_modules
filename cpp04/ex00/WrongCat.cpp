/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:07:28 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/12 14:14:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    this->type = other.type;
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "meoooooooow" << std::endl;
}

std::string WrongCat::getType(void) const
{
    return this->type;
}


