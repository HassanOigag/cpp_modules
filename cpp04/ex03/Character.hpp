/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:48:41 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:02:02 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "LinkedList.hpp"
#include "ICharacter.hpp"
#define SIZE 4

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& other);
		Character& operator=(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printInventory();
		void printGarbageCollector();
		void emptyInventory();
	private:
		AMateria** inventory;
		std::string name;
		LinkedList garbageCollector;
		int indexOfEmptySlot;
};



#endif
