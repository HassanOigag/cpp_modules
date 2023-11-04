/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:39:19 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 18:16:21 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <ostream>

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point& other);

		void setX(Fixed x);
		Fixed getX(void) const;
		void setY(Fixed y);
		Fixed getY(void) const;

		Point& operator=(const Point& other);
	private:
		Fixed const x;
		Fixed const y;
};

float getArea(const Point& a, const Point& b, const Point& c);

std::ostream& operator<<(std::ostream& stream, const Point& point);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
