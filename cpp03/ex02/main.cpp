/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:41:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/06 19:56:04 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip> 

void custom_print(const ScavTrap& attacker, const FragTrap& victim)
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
	ScavTrap amine("amine");
	FragTrap frag("hamza");
	FragTrap hamza;

	hamza = frag;
	
	custom_print(amine, hamza);

	amine.attack(hamza.getName());
	hamza.takeDamage(amine.getAttackDamage());
	
	custom_print(amine, hamza);

	amine.attack(hamza.getName());
	hamza.takeDamage(amine.getAttackDamage());
	
	custom_print(amine, hamza);

	amine.attack(hamza.getName());
	hamza.takeDamage(amine.getAttackDamage());
	
	custom_print(amine, hamza);
	
	amine.attack(hamza.getName());
	hamza.takeDamage(amine.getAttackDamage());
	
	custom_print(amine, hamza);
	
	amine.attack(hamza.getName());
	hamza.takeDamage(amine.getAttackDamage());
	
	custom_print(amine, hamza);
	
	hamza.attack(amine.getName());
	if (hamza.getHitPoints() > 0 && hamza.getEnergyPoints() > 0)
		amine.takeDamage(hamza.getAttackDamage());
	
	custom_print(amine, hamza);

	amine.guardGate();
	hamza.highFivesGuys();
	return (0);
}
