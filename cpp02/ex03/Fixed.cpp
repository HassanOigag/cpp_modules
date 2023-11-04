/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 18:13:07 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int power(int base, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
        result *= base;
    return result;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(number * power(2, Fixed::nfBits));
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = number * power(2, Fixed::nfBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = other.value;
    return *this;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (power(2, Fixed::nfBits))); 
}

int Fixed::toInt(void) const
{
    return this->value / power(2, Fixed::nfBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
    stream << fixed.toFloat();
    return stream;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed sum;
    sum.setRawBits(this->value + other.value);
    return sum;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed sub;
    sub.setRawBits(this->value - other.value);
    return sub;
}

Fixed Fixed::operator*(const Fixed& other)const 
{
    float value = (this->value * other.value) / (float)power(2, Fixed::nfBits * 2);
    return Fixed(value);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    float value = (float)this->value / other.value;
    return Fixed(value);
}


bool    Fixed::operator==(const Fixed& other) const
{
    return (this->value == other.value);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return !(this->value == other.value);
}

bool    Fixed::operator>(const Fixed& other) const
{
    return (this->value > other.value);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (!(this->value < other.value));
}
    
bool    Fixed::operator<(const Fixed& other) const
{
    return (this->value < other.value);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return !(this->value > other.value);
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}

Fixed& Fixed::operator++()
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed copy = *this;
    this->operator++();
    return copy;
}

Fixed& Fixed::operator--()
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copy = *this;
    this->operator--();
    return copy;
}

const int Fixed::nfBits = 8;