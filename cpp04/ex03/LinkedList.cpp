/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:34:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 16:54:20 by hoigag           ###   ########.fr       */
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
        delete toDelete;
    }
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    std::cout << "ls destructor" <<  std::endl;
    this->purge();
}

LinkedList::LinkedList(const LinkedList& other)
{
    node *tmp = other.head;
    while (tmp)
    {
        this->addFirst(tmp->materia);
        tmp = tmp->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    this->purge();
    node *tmp = other.head;
    while (tmp)
    {
        this->addFirst(tmp->materia);
        tmp = tmp->next;
    }
    return *this;
}

