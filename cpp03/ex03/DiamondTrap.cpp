/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:18:53 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 17:24:05 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}
DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap parameter constructor called" << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}		

void DiamondTrap::attack(const std::string& target)
{
   ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap parameter destructor called" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    this->ClapTrap::name = other.ClapTrap::name;
    this->name = other.name;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->hitPoints = other.hitPoints;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "diamond name: " << this->name << std::endl;
    std::cout << "clap    name: " << ClapTrap::getName() << std::endl;
}

