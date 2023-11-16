/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:46:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 16:59:25 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
MateriaSource::MateriaSource()
{
    this->index = 0;
    this->materias = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
        this->materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    this->deleteMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    this->index = other.index;
    this->materias = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (!other.materias[i])
            this->materias[i] = NULL;
        else
            this->materias[i] = other.materias[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& __unused other)
{
    this->deleteMaterias();
    this->index = other.index;
    this->materias = new AMateria*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (!other.materias[i])
            this->materias[i] = NULL;
        else
            this->materias[i] = other.materias[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *newMateria)
{
    if (this->index < 0 || this->index >= SIZE || this->materias[this->index])
    {
        delete newMateria;
        return;
    }
    this->materias[this->index] = newMateria;
    this->index++;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (this->materias[i] && this->materias[i]->getType() == type)
            return this->materias[i]->clone();
    }
    return NULL;
}

void MateriaSource::printMaterias() const
{
    for (int i = 0; i < SIZE; i++)
    {
        if (!this->materias[i])
            std::cout << "NULL ";
        else
            std::cout << this->materias[i]->getType() << " ";
    }
    std::cout << std::endl;
}

void MateriaSource::deleteMaterias()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
    delete[] this->materias;
}