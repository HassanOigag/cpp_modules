/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:14:49 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/09 16:48:14 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <ostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void		setName(std::string name);
		void 		setHitpoints(int hitPoints);
		void 		setEnergyPoints(int energyPoints);
		void 		setAttackDamage(int attackDamage);

		virtual void	attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	protected:
		std::string name;
		int			hitPoints;
		int 		energyPoints;
		int 		attackDamage;
};

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& ct);

#endif
