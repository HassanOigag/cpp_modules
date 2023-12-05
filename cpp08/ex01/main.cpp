/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:43:23 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/05 13:23:53 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(-5);
		sp.addNumber(-6);
		sp.addNumber(-5);
		sp.addNumber(3);
		sp.addNumber(-17);
		sp.addNumber(9);
		// sp.addNumber(11);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest  span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{ 
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
