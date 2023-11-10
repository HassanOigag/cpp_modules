/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:19:49 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 17:20:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap default costructor called" << std::endl;
    this->name = "";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap parameter costructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignement called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->attackDamage = other.attackDamage;
    this->energyPoints = other.energyPoints;
    return *this;
}

void	ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ScavTrap can not attack, inusfficient hit points or energy points" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "the ScavTrap is now in Gate keeper mode" << std::endl;
}
