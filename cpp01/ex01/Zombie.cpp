/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:42:58 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 16:29:24 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
    this->name = "";
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

std::string Zombie::getName(void)
{
    return this->name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->name << " is destroyed" << std::endl;
}

