/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:41:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 12:35:30 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"


int main()
{
	Zombie *new_zombie = newZombie("heap");
	new_zombie->announce();
	randomChump("amine");
	delete new_zombie;
	return (0);
}
