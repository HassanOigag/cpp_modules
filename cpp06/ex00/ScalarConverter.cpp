/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:08:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/23 15:53:58 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
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

bool isAllDigits(std::string literal)
{
    for (int i = 0; literal[i]; i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

int countCharactersInString(std::string str, char c)
{
    int counter = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            counter++;
        i++;
    }
    return counter;
}

double parseDouble(std::string literal)
{
    int commaCount = countCharactersInString(literal, '.');
    if (commaCount > 1)
        throw std::runtime_error("too many commas in string");
    char lastChar = literal.back();
    int commaPos = literal.find('.');
    if (commaPos == 0)
        literal.insert(0, "0");
    else if (lastChar == literal[commaPos])
        literal.insert(literal.length(), "0");
    lastChar = literal.back();
    if (!std::isdigit(lastChar) && lastChar != 'f' && lastChar != 'F')
        throw std::runtime_error("Invalid number format");
    commaPos = literal.find('.');
    std::string decimalPart = literal.substr(0, commaPos);
    std::string fractionalPart = literal.substr(commaPos + 1, literal.length() - decimalPart.length() - 2);
    if (decimalPart.empty())
    if (fractionalPart.empty())
        fractionalPart += "0";
    lastChar = fractionalPart.back();
    if (std::isdigit(lastChar))
        fractionalPart += lastChar;
    if (commaCount == 0 && isAllDigits(decimalPart + fractionalPart))
        return std::stod(literal);
    if (!isAllDigits(decimalPart + fractionalPart))
        throw std::runtime_error("please provide digits");
    return std::stod(literal);
}

void ScalarConverter::convert(std::string __unused literal)
{
    try
    {
        double number = parseDouble(literal);
        std::cout << number << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    // std::cout  <<  number << std::endl;
 

    // if (isRealNumber == -1)
    // {
    //     std::cout << isAllDigits(literal) << std::endl;
    // }
    // std::cout << commaCount << std::endl;
    // std::cout << isRealNumber << std::endl;
    // int literalToInt = 0;
    // float literalToFloat = 0.0f;
    // double literalToDouble = 0.0;
    // char literalToChar = 'a';
    // std::cout << "char   : " << literalToChar << std::endl;
    // std::cout << "int    : " << literalToInt << std::endl;
    // std::cout << "float  : " << literalToFloat << std::endl;
    // std::cout << "double : " << literalToDouble << std::endl;
}
