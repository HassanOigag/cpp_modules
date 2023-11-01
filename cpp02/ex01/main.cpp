/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:19:49 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/01 19:54:58 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <iomanip>      
#include "Fixed.hpp"
using namespace std;
int main( void )
{
	Fixed a(1234.4321f);
	std::cout << a.getValue() << std::endl;
	// std::cout << b << std::endl;
	// Fixed a;
	// std::cout << a << std::endl;;
	return 0;
}