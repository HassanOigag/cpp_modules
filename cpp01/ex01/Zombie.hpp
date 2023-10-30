/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:40:52 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 16:29:10 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
		std::string getName();
		void setName(std::string name);

		void announce(void);
	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
