/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:38:59 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/11 10:30:09 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default costructor called" << std::endl;
    this->name = "";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap parameter costructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignement called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->attackDamage = other.attackDamage;
    this->energyPoints = other.energyPoints;
    return *this;
}

void	FragTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "FragTrap " << this->name << " can not attack, inusfficient hit points or energy points" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "positive high fives" << std::endl;
}

