/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:13:37 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/13 11:41:46 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, other.brain->getIdea(i));
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignement operator called" << std::endl;
    
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, other.brain->getIdea(i));
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

Brain *Cat::getBrain(void) const
{
    return (this->brain);
}
