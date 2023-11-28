/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:41:29 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/28 20:01:17 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <string>

int main()
{
	Array<std::string> names(3);
	names[0] = "hassan";
	names[1] = "houssine";
	names[2] = "jamal";
	std::cout << copy.size() << std::endl;
	std::cout << copy << std::endl;
	system("leaks -q array");
	return (0);
}
