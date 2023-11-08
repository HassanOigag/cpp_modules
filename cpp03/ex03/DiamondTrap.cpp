/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:18:53 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/08 17:44:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}
DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap parameter constructor called" << std::endl;
    this->name = name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap parameter destructor called" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& __unused other)
{

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& __unused other)
{
    return *this;
}

