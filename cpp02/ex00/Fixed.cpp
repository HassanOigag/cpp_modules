/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/01 18:30:25 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
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

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
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

const int Fixed::nfBits = 8;

