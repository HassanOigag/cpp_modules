/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:29:34 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/27 13:30:30 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	public:
		// HumanA();
		HumanA(std::string name, Weapon& weapon);
		void setName(std::string name);
		void setWeapon(Weapon weapon);
		std::string getName();
		Weapon getWeapon();
		void attack();
	private:
		std::string name;
		Weapon& weapon;
};

#endif
