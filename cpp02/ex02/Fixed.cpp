/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/02 13:52:42 by hoigag           ###   ########.fr       */
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
    // this->value = roundf(number * power(2, Fixed::nfBits));
    value = number * (1 << nfBits);
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

Fixed Fixed::operator+(const Fixed& other)
{
    int i = this->value + other.value;
    return Fixed(i);
}

float Fixed::toFloat(void) const
{
    // return this->value * power(2, Fixed::nfBits);
    return ((float)value / (1 << nfBits)); 
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

const int Fixed::nfBits = 8;

