/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:41:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/05 15:02:11 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap attacker("hassan");
	attacker.setAttackDamage(2);

	ClapTrap victim("amine");
	std::cout << victim << std::endl;

	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getAttackDamage());
	std::cout << victim << std::endl;

	victim.beRepaired(10);
	std::cout << victim << std::endl;
	return (0);
}
