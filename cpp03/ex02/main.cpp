/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:41:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/10 17:21:55 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip> 

void custom_print(const FragTrap& attacker, const ScavTrap& victim)
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
	FragTrap amine("amine");
	ScavTrap hamza("hamza");
	
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
	amine.takeDamage(hamza.getAttackDamage());
	custom_print(amine, hamza);

	hamza.guardGate();
	amine.highFivesGuys();
	return (0);
}
