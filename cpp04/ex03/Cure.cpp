/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:52:52 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 11:29:53 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
    this->type = "cure";
}

Cure::~Cure()
{

}

Cure::Cure(const Cure& other)
{
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    this->type = other.type;
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure();
}
