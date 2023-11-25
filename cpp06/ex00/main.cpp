/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:14:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/25 18:06:34 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of args" << std::endl;
		return 1;
	}
	std::string literal = argv[1];
	// char *letters;
	// double number = std::strtod(argv[1], &letters);
	// std::cout << "number: " <<  number << std::endl;
	// std::cout << "rest  : " <<  letters << std::endl;
	ScalarConverter::convert(literal);
	return 0;
}
