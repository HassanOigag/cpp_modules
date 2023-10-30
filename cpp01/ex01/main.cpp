/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:49:18 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 12:36:30 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	int n = 4;
	Zombie *zombies = zombieHorde(n, "hassan");
	if (!zombies)
	{
		std::cout << "error" << std::endl;
		return 1;
	}
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
