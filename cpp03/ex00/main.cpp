/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:41:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 17:04:42 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap attacker("hassan");
	attacker.setAttackDamage(2);
	std::cout << attacker;

	ClapTrap victim("amine");
	std::cout << victim << std::endl;

	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getAttackDamage());
	std::cout << victim << std::endl;
	std::cout << attacker << std::endl;

	victim.beRepaired(10);
	std::cout << victim << std::endl;
	std::cout << attacker << std::endl;

	return (0);
}
