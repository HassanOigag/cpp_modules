/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:28:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/15 17:24:14 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>

 


BitcoinExchange::BitcoinExchange()
{
    this->db_filename = "data.csv";
    this->loadDataBase();
}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->db_filename = other.db_filename;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    this->db_filename = other.db_filename;
    return *this;
}

int convertDateToInt(std::string )
{
    
}

void BitcoinExchange::loadDataBase()
{
    std::ifstream file(this->db_filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open the file");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream stream;
        stream.str(line);
        std::string date;
        std::string strExchangeRate; 
        double exchangeRate;
        std::getline(stream, date, ',');
        stream >> exchangeRate;
        this->dataBase.insert(std::make_pair(date, exchangeRate));
    }
}

void BitcoinExchange::printData() const
{
    std::map<std::string, double>::const_iterator it = this->dataBase.cbegin();
    while (it  != dataBase.cend())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}


void trimString(std::string& str)
{
    if (str.empty())
        return;
    int start  = 0;
    int end = str.length() - 1;
    for (; str[start] && (str[start] == ' ' || str[start] == '\t'); start++){}
    for (; end >= 0 && (str[end] == ' ' || str[end] == '\t'); end--){}
    str = str.substr(start, end - start + 1);
}

double getDouble(std::string& literal)
{
    double number;
    char *garbage;

    trimString(literal);
    if (literal.empty())
        throw std::runtime_error("Error: empty price");
    number = std::strtod(literal.c_str(), &garbage);
    for (int i = 0; garbage[i]; i++)
    {
        if (garbage[i] != ' ')
            throw std::runtime_error("Error: bad input => " + literal);
    }
    return number;
}

int isDateValid(int day, int month, int year)
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    if (day < 0 || day > 31 || month < 0 || month > 12 || year < 0)
        return 0;
    if (day < 2 && month < 1 && year < 2009)
        return (0);
    if (month == 2 && day > 29)
        return 0;
    if (day > now->tm_mday && month > now->tm_mon && year > now->tm_year)
        return 0;
    return 1;
}


void parseDate(std::string& date)
{
    trimString(date);
    if (date.empty())
        throw std::runtime_error("Error: emtpy date field");
    std::stringstream stream;
    stream.str(date);
    int year, month, day;
    std::string strYear, strMonth, strDay;
    std::getline(stream, strYear, '-');
    std::getline(stream, strMonth, '-');
    std::getline(stream, strDay);
    if (strYear.empty() || strMonth.empty() || strDay.empty())        
        throw std::runtime_error("Error: missing date element");
    try
    {
        year = getDouble(strYear);
        month = getDouble(strMonth);           
        day = getDouble(strDay);        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: bad input => " + date << std::endl;
        return;
    }
    if (!isDateValid(day, month, year))
        throw std::runtime_error("Error: bad input => " + date);   
}


void BitcoinExchange::exchange(std::string fileName)
{
    std::fstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open the input file");
    std::string line;
    getline(inputFile, line);
    while (getline(inputFile, line))
    {
        std::stringstream stream;
        stream.str(line);
        std::string date;
        std::string strPrice;
        double price;
        getline(stream, date, '|');
        getline(stream, strPrice);
        try
        {
            parseDate(date);
            price = getDouble(strPrice);
            std::cout << this->dataBase[date] << std::endl;
            // std::cout << date << " => " << price <<  " = " << "100" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}