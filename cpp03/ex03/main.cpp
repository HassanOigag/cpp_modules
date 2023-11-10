/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:41:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 18:31:12 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iomanip> 

void custom_print(const ClapTrap& attacker, const ClapTrap& victim)
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(15) << "Name"
				<< std::setw(15) << "Hit Points"
				<< std::setw(15) << "Energy Points"
				<< std::setw(15) << "Attack Damage" << '\n';

	std::cout << std::left << std::setw(15) << attacker.getName()
				<< std::setw(15) << attacker.getHitPoints()
				<< std::setw(15) << attacker.getEnergyPoints()
				<< std::setw(15) << attacker.getAttackDamage() << '\n';

	std::cout << std::left << std::setw(15) << victim.getName()
				<< std::setw(15) << victim.getHitPoints()
				<< std::setw(15) << victim.getEnergyPoints()
				<< std::setw(15) << victim.getAttackDamage() << '\n';
	std::cout << std::endl;
}

int main()
{
	DiamondTrap hamza("hamza");
	DiamondTrap amine("amine");
	
	DiamondTrap hassan = amine;
	
	std::cout << hassan;
	
	custom_print(hamza, amine);
	
	hamza.attack("amine");
	amine.takeDamage(hamza.getAttackDamage());
	custom_print(hamza, amine);

	
	hamza.whoAmI();
	amine.whoAmI();
	std::cout << std::endl;

	return (0);
}
