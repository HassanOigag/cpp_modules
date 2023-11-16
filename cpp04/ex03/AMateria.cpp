/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:16:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:06:07 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    this->type = "default type";
}	

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::~AMateria()
{

}

AMateria::AMateria(const AMateria& other)
{
    this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& __unused other)
{
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->type;
}


void AMateria::use(ICharacter& target)
{
    std::cout << "generic use function " << target.getName() << std::endl;
}