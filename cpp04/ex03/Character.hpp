/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:48:41 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 17:55:16 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "LinkedList.hpp"
#define SIZE 3

class Character
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
		void printSlots();
	private:
		AMateria** slots;
		std::string name;
		LinkedList garbageCollector;
		int index;
};

#endif
