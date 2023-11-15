/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:31:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 16:37:19 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "AMateria.hpp"
#include <ostream>
struct node
{
	AMateria *materia;
	struct node *next;
};

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		void addFirst(AMateria *m);
		void purge();
		// void setHead(node *newHead);
		node *getHead(void);
		LinkedList(const LinkedList& other);
		LinkedList& operator=(const LinkedList& other);
	private:
		node *head;	
};

std::ostream& operator<<(std::ostream& stream, LinkedList& ls);

#endif
