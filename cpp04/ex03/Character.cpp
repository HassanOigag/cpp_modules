/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:54:37 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:17:18 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
Character::Character()
{
    this->name = "";
    this->inventory = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->inventory[i] = NULL;
    this->indexOfEmptySlot = 0;
}
Character::Character(std::string name)
{
    this->name = name;
    this->indexOfEmptySlot = 0;
    this->inventory = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->inventory[i] = NULL;
}

Character::~Character()
{
    this->emptyInventory();
    this->garbageCollector.purge();
}

Character::Character(const Character& other)
{
    this->indexOfEmptySlot = other.indexOfEmptySlot;
    this->name = other.name;
    this->garbageCollector = other.garbageCollector.getListCopy();
    this->inventory = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    this->emptyInventory();
    this->garbageCollector.purge();
    this->indexOfEmptySlot = other.indexOfEmptySlot;
    this->garbageCollector = other.garbageCollector.getListCopy();
    this->name = other.name;
    this->inventory = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (this->indexOfEmptySlot < 0
        || this->indexOfEmptySlot >= SIZE
        || this->inventory[this->indexOfEmptySlot])
        {
            this->garbageCollector.addFirst(m);
            return;
        }
        this->inventory[this->indexOfEmptySlot] = m;
        this->indexOfEmptySlot++;  
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= SIZE || !this->inventory[idx])
        return;
    this->garbageCollector.addFirst(this->inventory[idx]);
    this->inventory[idx] = NULL;
    this->indexOfEmptySlot = idx;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= SIZE)
        return;
    if (inventory[idx])
        this->inventory[idx]->use(target);
}

void Character::printInventory()
{
    std::cout << "-------------------------------\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (!this->inventory[i])
            std::cout << "| NULL |";
        else
            std::cout << "| " << this->inventory[i]->getType() << " |";
    }
    std::cout << "\n-------------------------------\n";
}

void Character::printGarbageCollector()
{
    std::cout << this->garbageCollector << std::endl;
}

void Character::emptyInventory()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    delete[] this->inventory;
}