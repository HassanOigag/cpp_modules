/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:31:23 by hoigag            #+#    #+#             */
/*   Updated: 2024/01/14 16:37:48 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>


RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    this->expression = other.expression;
    this->mstack = other.mstack;
    return *this;
}

bool RPN::isOperation(std::string operation)
{
    if (operation.length() != 1)
        return false;
    std::string ops = "*/-+";
    return (ops.find(operation[0]) != std::string::npos);
}
bool RPN::isValidDigit(std::string operand)
{
    if (operand.length() != 1)
        return false;
    return std::isdigit(operand[0]);
}

double add(double a, double b)
{
    return a + b;
}
double subtruct(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("zero division");
    return a / b;
}

double doOperation(double a, double b, std::string operation)
{
    if (operation == "+")
        return add(a, b);
    else if (operation == "-")
        return subtruct(a, b);
    else if (operation == "*")
        return multiply(a, b);
    return divide(a, b);
}

double RPN::convert(std::string expression)
{
    std::stringstream stream;
    stream.str(expression);
    std::string operand;
    double result;
    while (stream >> operand)
    {
        if (this->isValidDigit(operand))
        {
            double number = operand[0] - '0';
            this->mstack.push(number);
        }
        else if (this->isOperation(operand))
        {
            if (this->mstack.empty() || this->mstack.size() < 2)
                throw std::runtime_error("Error");
            double secondOperand = this->mstack.top();
            this->mstack.pop();
            double firstOperand = this->mstack.top();
            this->mstack.pop();
            result = doOperation(firstOperand, secondOperand, operand);
            this->mstack.push(result);   
        }
        else
            throw std::runtime_error("Error");
    }
    if (this->mstack.size() != 1)
        throw std::runtime_error("Error");
    return this->mstack.top();
}