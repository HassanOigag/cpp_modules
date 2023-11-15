/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:35 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 10:49:13 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
    this->type = "ice";
}

Ice::~Ice()
{

}

Ice::Ice(const Ice& other)
{
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    this->type = other.type;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
