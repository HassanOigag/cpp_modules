/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:29:34 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/28 13:15:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	public:
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
