/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:47:27 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/27 13:44:43 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string.h>

class HumanB {
	public:
		HumanB(std::string name);
		void setName(std::string name);
		void setWeapon(Weapon& weapon);
		std::string getName();
		Weapon getWeapon();
		void attack();
	private:
		std::string name;
		Weapon *weapon;
};

#endif
