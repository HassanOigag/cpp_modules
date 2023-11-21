/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 15:58:30 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat hassan("hassan", 3);
		std::cout << hassan;
		std::cout << "increment\n";
		hassan.increment();
		std::cout << hassan;
		std::cout << "decrement\n";
		hassan.decrement();
		std::cout << hassan;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
