/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:19:49 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 18:11:36 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point.hpp"    
#include "Fixed.hpp"

int main( void ) {
    Point a(30.0f, 50.0f);
    Point b(50.0f, 10.0f);
    Point c(10.0f, 10.0f);

    Point point1(60.f, 30.0f);
    Point point2(30.f, 30.0f);
    Point point3(40.f, 15.25f);
    Point point4(11.45f, 20.0f);
    Point point5(15.45f, 20.1f);

    std::cout << bsp(a, b, c, point1) << std::endl;
    std::cout << bsp(a, b, c, point2) << std::endl;
    std::cout << bsp(a, b, c, point3) << std::endl;
    std::cout << bsp(a, b, c, point4) << std::endl;
    std::cout << bsp(a, b, c, point5) << std::endl;
    // std::cout << "area: " << "{" << getArea(a, b, c) << "}" << std::endl;
    return 0;
}