/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:32:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/19 17:34:00 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Ivalid number of args." << std::endl;
		return 1;
	}
	std::string rpn = argv[1];
	std::cout << rpn << std::endl;
	return (0);
}
