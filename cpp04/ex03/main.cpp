/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:18:20 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 17:54:20 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	Character c("hassan");
	c.equip(new Ice());
	c.equip(new Cure());
	c.equip(new Ice());
	c.equip(new Ice());
	c.equip(new Ice());
	c.equip(new Ice());
	c.equip(new Ice());
	c.equip(new Ice());
	c.equip(new Ice());

	c.printSlots();
	
	// LinkedList floor;
	// floor.addFirst(new Ice()); 
	// floor.addFirst(new Cure());
	// floor.addFirst(new Ice());
	// node *tmp = floor.getHead();
	// while (tmp)
	// {
	// 	std::cout << tmp->materia->getType() << std::endl;;
	// 	tmp = tmp->next;
	// }
	// // std::cout << m;aterial->use() << std::endl;
	// system("leaks -q t3nkich");
	// while (true);
	return (0);
}
