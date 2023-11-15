/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:54:37 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 17:58:19 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
Character::Character()
{
    this->name = "";
    this->slots = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->slots[i] = NULL;
    index = 0;
}
Character::Character(std::string name)
{
    this->name = name;
    index = 0;
    this->slots = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->slots[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < SIZE; i++)
        delete this->slots[i];
    delete[] this->slots;
}

Character::Character(const Character& other)
{
    this->index = other.index;
    this->name = other.name;
    this->garbageCollector = other.garbageCollector;
    this->slots = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->slots[i] = other.slots[i]->clone();
}

Character& Character::operator=(const Character& other)
{
    for (int i = 0; i < SIZE; i++)
        delete other.slots[i];
    delete[] other.slots;
    
    this->index = other.index;
    this->garbageCollector = other.garbageCollector;
    this->name = other.name;
    this->slots = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->slots[i] = other.slots[i]->clone();
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (this->index < 0 || this->index >= SIZE)
        return;
    this->slots[this->index] = m;
    this->index++;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= SIZE || !this->slots[idx])
        return;
    this->garbageCollector.addFirst(this->slots[idx]);
    this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= SIZE)
        return;
    this->slots[idx]->use(target);
}

void Character::printSlots()
{
    for (int i = 0; i < this->index; i++)
    {
        if (!this->slots[i])
            std::cout << "NULL" << std::endl;
        else
            std::cout << this->slots[i]->getType() << std::endl;
    }
}