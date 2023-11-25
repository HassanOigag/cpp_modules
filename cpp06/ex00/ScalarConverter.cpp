/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:08:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/25 18:29:52 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& __unused other)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& __unused other)
{
    return *this;
}

void displayChar(double number)
{
    std::cout << "char   : ";
    if (number > std::numeric_limits<char>::max()
        || number < std::numeric_limits<char>::min() || number != number)
        std::cout << "impossible" << std::endl;
    else if (number >= 32 && number < 127)
        std::cout << static_cast<char>(number) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}
void displayInt(double number)
{
    std::cout << "int    : ";
    if (number > std::numeric_limits<int>::max()
        || number < std::numeric_limits<int>::min() || number != number)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(number) << std::endl;
}

void displayFloat(double number, int precision)
{
    std::cout << "float  : ";
    std::cout << std::fixed << std::setprecision(precision);
    if (number == 0)
        std::cout << number << "f" << std::endl;
    else if (number == std::numeric_limits<float>::infinity())
        std::cout << "+inff" << std::endl;
    else if (number == -std::numeric_limits<float>::infinity())
        std::cout << "-inff" << std::endl;
    else if (number > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << number << "f" << std::endl;
}

void displayDouble(double number, int precision)
{
    std::cout << "double : ";
    std::cout << std::fixed << std::setprecision(precision);
     if (number == 0)
        std::cout << number << std::endl;
    else if (number == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (number == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else if (number > std::numeric_limits<double>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << number << std::endl;
}


int getPrecision(std::string literal)
{
    int commaPos = literal.find(".");
    if (commaPos == -1)
        return 1;
    std::string fractionalPart = literal.substr(commaPos + 1);
    return fractionalPart.length();
}

void prettify_display(double number, int precision)
{
    displayChar(number);
    displayInt(number);
    displayFloat(number, precision);
    displayDouble(number, precision);
}

void displayNonNumbers()
{
    std::cout << "char   : impossible" << std::endl;
    std::cout << "int    : impossible" << std::endl;
    std::cout << "float  : impossible" << std::endl;
    std::cout << "double : impossible" << std::endl;
}

bool parseDouble(std::string literal)
{
    double number;
    char *garbage;

    number = std::strtod(literal.c_str(), &garbage);
    if (std::strlen(garbage) > 1)
        return 0;
    if (literal.length() == 1 && garbage[0])
        return 1;
    if (garbage[0] && garbage[0] != 'f')
        return 0;
    return 1;
}

void ScalarConverter::convert(std::string literal)
{
    double number;
    char *garbage;
    
    if (!parseDouble(literal))
    {
        displayNonNumbers();
        return;
    }
    if (literal.length() == 1 && !isdigit(literal[0]))
        number = static_cast<double>(literal[0]);
    else
        number = std::strtod(literal.c_str(), &garbage);
    prettify_display(number, getPrecision(literal));
}
