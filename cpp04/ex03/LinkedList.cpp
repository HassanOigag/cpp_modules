/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:34:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 16:05:21 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"
#include <iostream>
LinkedList::LinkedList()
{
    this->head = NULL;
}

void LinkedList::addFirst(AMateria *m)
{
    node *newNode = new node;
    newNode->materia = m;
    newNode->next = NULL;
    if (!this->head)
    {
        this->head = newNode;
        return;
    }
    newNode->next = this->head;
    this->head = newNode;
}

node *LinkedList::getHead()
{
    return this->head;
}

void LinkedList::purge()
{
    node *tmp = this->getHead();
    node *toDelete;
    while (tmp)
    {
        toDelete = tmp;
        tmp = tmp->next;
        delete toDelete->materia;
        delete toDelete;
    }
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    this->purge();
}

LinkedList::LinkedList(const LinkedList& other)
{
    
    std::cout << "copy assignement called" << std::endl;
    node *tmp = other.head;
    this->head = NULL;
    while (tmp)
    {
        this->addFirst(tmp->materia->clone());
        tmp = tmp->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    std::cout << "copy assignement called" << std::endl;
    this->purge();
    node *tmp = other.head;
    while (tmp)
    {
        this->addFirst(tmp->materia->clone());
        tmp = tmp->next;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, LinkedList& ls)
{
    node *tmp = ls.getHead();
    if (!tmp)
    {
        stream << "garbage collector is empty" << std::endl;
        return stream;   
    }
    stream << "head -> " ;
    while (tmp)
    {
        stream << tmp->materia->getType() << " -> ";
        tmp = tmp->next;
    }
    stream << "NULL";
    stream << std::endl;
    return stream;
}

LinkedList LinkedList::getListCopy() const
{
    LinkedList copy;
    node *tmp = this->head;
    while (tmp)
    {
       copy.addFirst(tmp->materia->clone());
       tmp = tmp->next; 
    }
    return copy;
}