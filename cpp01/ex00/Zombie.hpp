/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:23:52 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 15:47:36 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
//adfasdffdasfdas
 
class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		std::string getName(void);
		void setName(std::string name);
		void announce(void);
	private:
		std::string name;
};

void	randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif
