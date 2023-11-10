/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:30:32 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 16:58:43 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl; 
    this->name = "";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap constructor called" << std::endl; 
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment" << std::endl;
    this->name = other.name;
    this->attackDamage = other.attackDamage;
    this->energyPoints = other.energyPoints;
    this->hitPoints = other.hitPoints;
    return *this;
}

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& ct)
{
    stream << "name          : " << ct.getName() << std::endl;
    stream << "hit points    : " << ct.getHitPoints() << std::endl;
    stream << "energy points : " << ct.getEnergyPoints() << std::endl;
    stream << "attack damage : " << ct.getAttackDamage() << std::endl;
    return stream;
}

void	ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can not attack, inusfficient hit points or energy points" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can not take damage, inusfficient hit points or energy points" << std::endl;
        return;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " took a hit, lost "<< amount << " hit points!" << std::endl;   
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can not be repaired, inusfficient hit points or energy points" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " gained " << amount << " hit points back!" << std::endl;
}


std::string ClapTrap::getName(void) const
{
    return this->name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return this->attackDamage;
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setHitpoints(unsigned int hitPoints)
{
    this->hitPoints = hitPoints;
}

