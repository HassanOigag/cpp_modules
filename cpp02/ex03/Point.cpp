/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:59 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 17:17:05 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b)) {}

Point::Point(const Point& point) : x(point.getX()), y(point.getY()) {}

Point::~Point() {}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

Point& Point::operator=(const Point& __unused other)
{
    std::cout << "copy assingnement called" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
    stream << "x: " << point.getX() << std::endl;
    stream << "y: " << point.getY() << std::endl;
    return stream;
}
