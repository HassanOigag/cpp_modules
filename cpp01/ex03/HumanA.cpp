/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:38:31 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/27 13:47:41 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
    this->name = name;
}

void HumanA::setName(std::string name)
{
    this->name = name;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}

std::string HumanA::getName()
{
    return this->name;
}

Weapon HumanA::getWeapon()
{
    return this->weapon;
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

