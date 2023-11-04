/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:03:13 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 18:00:06 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

float abs_(float number)
{
    if (number < 0)
        return -number;
    return number;
}

// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
float getArea(const Point& a, const Point& b, const Point& c)
{
    Fixed expr1 = a.getX() * (b.getY() - c.getY());
    Fixed expr2 = b.getX() * (c.getY() - a.getY());
    Fixed expr3 = c.getX() * (a.getY() - b.getY());
    Fixed sum = expr1 + expr2 + expr3;
    return (abs_(sum.toFloat() / 2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float bigArea = getArea(a, b, c);
    float area1 = getArea(a, b, point);
    float area2 = getArea(a, c, point);
    float area3 = getArea(b, c, point);
    
    if (!area1 || !area2 || !area3)
        return false;
    return ((area1 + area2 + area3) == bigArea);
}